import pygame as pg
import numpy as np
import math

clock = pg.time.Clock()
FPS = 30
WIDTH = 1920
HEIGHT = 1080

R = 350
MAP_WIDTH = 149
MAP_HEIGHT = 38

pg.init()

my_font = pg.font.SysFont('arial', 18)

with open('moon.txt') as f:
	data = [f.read().replace('\n', '')]
	
ascii_chars = []
for line in data:
	for char in line:
		ascii_chars.append(char)

ascii_chars.reverse()

class Projection:
	def __init__(self, width, height):
		self.width = width
		self.height = height
		self.screen = pg.display.set_mode((width, height))
		self.background = (10, 10, 60)
		pg.display.set_caption('Happy Mid Autumn Festival')
		self.surfaces = {}

	def addSurface(self, name, surface):
		self.surfaces[name] = surface

	def display(self):
		self.screen.fill(self.background)
		for surface in self.surfaces.values():
			i = 0
			for node in surface.nodes:
				self.text = ascii_chars[i]
				self.text_surface = my_font.render(self.text, False, (255, 255, 255))
				if node[1] > 0:
					self.screen.blit(self.text_surface, ((WIDTH / 2) + int(node[0]), HEIGHT / 2 + int(node[2])))
				i += 1
				
	def rotateAll(self, theta):
		for surface in self.surfaces.values():
			center = surface.findCenter()
			c = np.cos(theta)
			s = np.sin(theta) 
			matrix = np.array([	[c, -s, 0, 0],
								[s, c, 0, 0],
								[0, 0, 1, 0],
								[0, 0, 0, 1]])
			surface.rotate(center, matrix)
		
class Object:
	def __init__(self):
		self.nodes = np.zeros((0, 4))
		
	def addNodes(self, node_array):
		ones_column = np.ones((len(node_array), 1))
		ones_added = np.hstack((node_array, ones_column))
		self.nodes = np.vstack((self.nodes, ones_added))

	def findCenter(self):
		return self.nodes.mean(axis = 0)

	def rotate(self, center, matrix):
		for i, node in enumerate(self.nodes):
			self.nodes[i] = center + np.matmul(matrix, node - center)
			

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
spin = -0.02

while running:
	clock.tick(FPS)
	pv.rotateAll(spin)
	pv.display()
	for event in pg.event.get():
		if event.type == pg.QUIT:
			running = False
	pg.display.update()

