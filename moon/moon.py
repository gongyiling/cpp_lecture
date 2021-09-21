import pygame as pg
import numpy as np
import math
import random

clock = pg.time.Clock()
FPS = 30
WIDTH = 1920
HEIGHT = 1080

R = 350
MAP_WIDTH = 149
MAP_HEIGHT = 38

pg.init()

text_font = pg.font.SysFont('arial', 10)
title_font = pg.font.SysFont('arial', 20)
title = 'Happy Mid Autumn Festival'
ascii_chars = []
title_color = (255, 215, 0)

with open('moon.txt') as f:
	lines = f.readlines()
	for i, line in enumerate(lines):
		line = line.strip()
		for j, char in enumerate(line):
			if j < len(title) and i == MAP_HEIGHT / 2:
				ascii_chars.append((title[j], True))
			else:
				ascii_chars.append((char, False))

ascii_chars.reverse()

class Projection:
	def __init__(self, width, height):
		self.width = width
		self.height = height
		self.screen = pg.display.set_mode((width, height))
		self.background = (10, 60, 60)
		pg.display.set_caption(title)
		self.surfaces = {}

	def addSurface(self, name, surface):
		text_surfaces = []
		low = 250
		high = 250
		for i, node in enumerate(surface.nodes):
			text = ascii_chars[i][0]
			if ascii_chars[i][1]:
				render_font = title_font
				c = title_color
			else:
				render_font = text_font
				c = (random.randint(low, high), random.randint(low, high), random.randint(low, high))
			text_surfaces.append(render_font.render(text, False, c))
		surface.text_surfaces = text_surfaces
		self.surfaces[name] = surface

	def display(self):
		self.screen.fill(self.background)
		for surface in self.surfaces.values():
			for i, node in enumerate(surface.nodes):
				text_surface = surface.text_surfaces[i] 
				if node[1] > 0:
					self.screen.blit(text_surface, ((WIDTH / 2) + int(node[0]), HEIGHT / 2 + int(node[2])))
				
	def rotateAll(self, theta):
		for surface in self.surfaces.values():
			c = np.cos(theta)
			s = np.sin(theta) 
			matrix = np.array([	[c, -s, 0, 0],
								[s, c, 0, 0],
								[0, 0, 1, 0],
								[0, 0, 0, 1]])
			surface.rotate(matrix)
		
class Object:
	def __init__(self):
		self.nodes = np.zeros((0, 4))
		self.text_surfaces = []
		
	def addNodes(self, node_array):
		ones_column = np.ones((len(node_array), 1))
		ones_added = np.hstack((node_array, ones_column))
		self.nodes = np.vstack((self.nodes, ones_added))
		self.center = self.findCenter()

	def findCenter(self):
		return self.nodes.mean(axis = 0)

	def rotate(self, matrix):
		nodes = self.nodes - self.center
		self.nodes = self.center + np.transpose(np.dot(matrix, np.transpose(nodes)))

running = True
xyz = []

for i in range(MAP_HEIGHT + 1):
	lat = (math.pi / MAP_HEIGHT) * i
	for j in range(MAP_WIDTH + 1):
		lon = (2 * math.pi / MAP_WIDTH) * j;
		x = round(R * math.sin(lat) * math.cos(lon), 2)
		y = round(R * math.sin(lat) * math.sin(lon), 2)
		z = round(R * math.cos(lat), 2)
		xyz.append((x, y, z))

pv = Projection(WIDTH, HEIGHT)
moon = Object()
moon_nodes = [i for i in xyz]
moon.addNodes(np.array(moon_nodes))
pv.addSurface('moon', moon)
spin = 0.01

while running:
	clock.tick(FPS)
	pv.rotateAll(spin)
	pv.display()
	for event in pg.event.get():
		if event.type == pg.QUIT:
			running = False
	pg.display.update()

