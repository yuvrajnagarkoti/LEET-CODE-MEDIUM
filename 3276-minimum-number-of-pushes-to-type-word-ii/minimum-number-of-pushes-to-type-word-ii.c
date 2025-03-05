int compare(const void *a, const void *b)
{
    return ((int *)b)[1] - ((int *)a)[1];
}

int minimumPushes(char* word)
{
    int count[26] = {0};
    int i,z=0,c=0,k=1,index = 0;
    for (i = 0; word[i] != '\0'; i++)
    {
        count[word[i] - 'a']++;
    }
    int charCount[26][2];
    for (i = 0; i < 26; i++)
    {
        charCount[i][0] = i + 'a';
        charCount[i][1] = count[i];
    }
    qsort(charCount, 26, sizeof(charCount[0]), compare);
    for(i=0;i<26;i++)
    {
        if(charCount[i][1]==0)
            continue;
        else
        {
            z=z+1;
            if (z <= 8)
            {
                c=c+charCount[i][1];
            }
            else if (z <= 16)
            {
                k = 2;
                c= c + (charCount[i][1] * k);
            }
            else if (z <= 24)
            {
                k = 3;
                c= c + (charCount[i][1] * k);
            }
            else
            {
                k = 4;
                c= c + (charCount[i][1] * k);
            }
        }
    }
    return c;
}

