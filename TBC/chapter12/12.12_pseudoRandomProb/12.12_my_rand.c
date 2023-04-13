unsigned int next = 1;

int my_rand(void)
{
	next = next * 1103515245 + 1234;
	next = (unsigned int)(next / 65536) % 32768;
	printf("my_rand: %d %p\n", &next, &next);
	return (int)next;
}

void my_srand(unsigned int seed)
{
	next = seed;
	printf("my_srand: %d %p\n", &next, &next);
}