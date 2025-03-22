int hIndex(int* citations, int n)
{
    int *count = (int *)calloc(n + 1, sizeof(int));
    int i, hIndex = 0;
    
    // Count occurrences
    for (i = 0; i < n; i++)
    {
        if (citations[i] >= n)
            count[n]++; // Any value >= n counts towards n
        else
            count[citations[i]]++;
    }
    // Compute H-Index
    int total = 0;
    for (i = n; i >= 0; i--)
    {
        total += count[i]; // Sum of papers with citations >= i
        if (total >= i)
        {
            hIndex = i;
            break;
        }
    }
    free(count);
    return hIndex;
}