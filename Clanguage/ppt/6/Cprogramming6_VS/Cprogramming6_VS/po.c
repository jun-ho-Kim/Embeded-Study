int power(int n, int m)
{
	int i, result = 1;
	for (i = 1; i <= m; i++) result *= n;
	return result;
}

int sum(int n, int m)
{
	return n + m;
}