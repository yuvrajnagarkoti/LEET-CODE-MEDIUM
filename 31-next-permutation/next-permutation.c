void nextPermutation(int *a, int s) {
    int i, j, temp, flag = 0;
    if (s <= 1) return; 
    for (i = s - 2; i >= 0; i--)
    {
        if (a[i] < a[i + 1])
        {
            flag = 1;
            break;
        }
    }
    if (flag==1)
    {
        for (j = s - 1; j > i; j--)
        {
            if (a[j] > a[i])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
                break;
            }
        }
    }
    for (j = i + 1, temp = s - 1; j < temp; j++, temp--)
    {
        int sTemp = a[j];
        a[j] = a[temp];
        a[temp] = sTemp;
    }
}
