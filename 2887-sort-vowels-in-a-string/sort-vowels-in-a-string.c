#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Corrected comparator function for sorting vowels
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

char* sortVowels(char* s)
{
    int i, j = 0, n = strlen(s);
    // Allocate memory for vowels
    int *a = (int *)malloc(n * sizeof(int));
    // Extract vowels
    for (i = 0; i < n; i++) {
        if (s[i] == 'a' || s[i] == 'A' || s[i] == 'e' || s[i] == 'E' ||
            s[i] == 'i' || s[i] == 'I' || s[i] == 'o' || s[i] == 'O' ||
            s[i] == 'u' || s[i] == 'U') {
            a[j++] = s[i];
        }
    }
    // Sort vowels
    qsort(a, j, sizeof(int), compare);
    // Replace vowels in original string
    j = 0;
    for (i = 0; i < n; i++)
    {
        if (s[i] == 'a' || s[i] == 'A' ||
            s[i] == 'e' || s[i] == 'E' ||
            s[i] == 'i' || s[i] == 'I' ||
            s[i] == 'o' || s[i] == 'O' ||
            s[i] == 'u' || s[i] == 'U')
        {
                s[i] = a[j++];
        }
    }
    // Free allocated memory
    free(a);
    return s;
}
