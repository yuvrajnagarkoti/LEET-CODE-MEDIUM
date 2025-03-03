// Comparator function for sorting in descending order
int compare(const void* a, const void* b) {
    return (*(int*)b - *(int*)a);
}

int maxCoins(int* piles, int pilesSize) {
    // Step 1: Sort the piles in descending order
    qsort(piles, pilesSize, sizeof(int), compare);

    // Step 2: Pick every second element from sorted piles, skipping every third pick
    int sum = 0;
    for (int i = 1; i < pilesSize * 2 / 3; i += 2) {
        sum += piles[i];
    }

    return sum;
}