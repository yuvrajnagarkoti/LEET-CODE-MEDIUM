#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Function to check if a character is a vowel
bool isVowel(char c) {
    return (c == 'a' || c == 'A' || c == 'e' || c == 'E' ||
            c == 'i' || c == 'I' || c == 'o' || c == 'O' ||
            c == 'u' || c == 'U');
}

// Comparator function for sorting vowels
int compare(const void *a, const void *b) {
    return (*(char*)a - *(char*)b);  // Sort vowels in ascending order
}

char* sortVowels(char* s) {
    int n = strlen(s);
    // Dynamically allocate memory for vowels and their positions
    char *vowels = (char*)malloc(n * sizeof(char));
    int *index = (int*)malloc(n * sizeof(int));
    int count = 0;
    // Step 1: Extract vowels and store their positions
    for (int i = 0; i < n; i++) {
        if (isVowel(s[i])) {
            vowels[count] = s[i];  // Store vowel
            index[count] = i;       // Store position
            count++;
        }
    }
    // Step 2: Sort only the vowels
    qsort(vowels, count, sizeof(char), compare);
    // Step 3: Put sorted vowels back into their original positions
    for (int i = 0; i < count; i++) {
        s[index[i]] = vowels[i];
    }
    // Free allocated memory
    free(vowels);
    free(index);
    return s;
}
