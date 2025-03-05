// Comparison function for qsort to sort integers in ascending order
int com(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);  // Compare the values at the pointers a and b
}

// Function to calculate the minimum number of pushes required
int minimumPushes(char* word) {
    int i, len, *arr, re = 0;
    
    len = strlen(word);  // Get the length of the input word
    arr = calloc(26, sizeof(int));  // Create an array of 26 integers initialized to 0 (one for each letter a-z)
    
    // Count the frequency of each character in the word
    for (i = 0; i < len; ++i) {
        arr[(int)word[i] - 97] += 1;  // Increment the count for the character (word[i] - 'a')
    }

    // Sort the frequency array in ascending order using qsort
    qsort(arr, 26, sizeof(int), com);

    // Calculate the total pushes required based on the sorted frequencies
    for (i = 25; i >= 0; --i) {
        if (arr[i] == 0)  // Skip characters that do not appear in the word
            break;
        else if (i >= 18)  // If i >= 18 (i.e., last 8 characters), each group gets 1 push
            re += arr[i];
        else if (i >= 10)  // If i >= 10 (i.e., next 8 characters), each group gets 2 pushes
            re += (arr[i] * 2);
        else if (i >= 2)  // If i >= 2 (i.e., next 8 characters), each group gets 3 pushes
            re += (arr[i] * 3);
        else  // If i < 2 (first 2 characters), each group gets 4 pushes
            re += (arr[i] * 4);
    }
    
    return re;  // Return the total pushes required
}