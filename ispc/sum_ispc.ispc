
export uniform int sum2(uniform int a[], uniform int count)
{
	int total = 0;
	foreach (i = 0 ... count)
	{
		total += a[i];
	}
	return reduce_add(total);
}
