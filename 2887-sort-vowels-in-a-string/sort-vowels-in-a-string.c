int isVowel(char ch) 
{
    return ch == 'a' || ch == 'A' || 
           ch == 'e' || ch == 'E' || 
           ch == 'i' || ch == 'I' || 
           ch == 'o' || ch == 'O' || 
           ch == 'u' || ch == 'U';
}

void countingSort(char* vowels, int count) 
{
    int freq[128] = {0}; 
    for (int i = 0; i < count; i++) 
    {
        freq[(int)vowels[i]]++;
    }
    int index = 0;
    for (int i = 0; i < 128; i++) 
    {
        while (freq[i] > 0) 
        {
            vowels[index++] = (char)i;
            freq[i]--;
        }
    }
}

char* sortVowels(char* s) 
{
    int n = strlen(s);
    char vowels[n];
    int count = 0;

    for (int i = 0; i < n; i++) 
    {
        if (isVowel(s[i])) 
        {
            vowels[count++] = s[i];
        }
    }

    countingSort(vowels, count);

    int index = 0;
    for (int i = 0; i < n; i++) 
    {
        if (isVowel(s[i])) 
        {
            s[i] = vowels[index++];
        }
    }
    return s;
}