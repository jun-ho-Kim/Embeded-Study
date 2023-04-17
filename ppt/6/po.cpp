int power(int n, int m)
{
	int i, result = 1;
	for(i = 1; i<=m; i++) result *= n;
	return result;
}
