
static unsigned long int seed = 1;

int my_rand(void)
{
    seed = seed * 1103515245 + 12345;
    return (unsigned int) (seed / 65536) % 32768;
}

void my_srand(unsigned int userSeed)
{
    seed = userSeed;
}
