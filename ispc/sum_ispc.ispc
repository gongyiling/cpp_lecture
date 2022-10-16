
export uniform int sum2(uniform int a[], uniform int count)
{
	int total = 0;
	for (int i = 0; i < count; i++)
	{
		total += a[i];
	}
	return reduce_add(total);
}
