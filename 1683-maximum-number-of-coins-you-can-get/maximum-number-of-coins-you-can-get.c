// comparator function for descending order
int compare(const void* a, const void* b)
{
    return (*(int*)b - *(int*)a); // Sort in descending order
}

int maxCoins(int* piles, int pilesSize)
{
    int i, sum = 0;
    // Sort the piles in descending order
    qsort(piles, pilesSize, sizeof(int), compare);
    // Start picking coins optimally
    for (i = 1; i < pilesSize / 3 * 2; i += 2) {
        sum += piles[i]; // Pick every second element from sorted piles
    }
    return sum;
}