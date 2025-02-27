int minPartitions(char* n) {
    char maxDigit = '0';
    for (int i = 0; n[i] != '\0'; i++)
    {
        if (n[i] > maxDigit) {
            maxDigit = n[i];
        }
        if (maxDigit == '9') return 9;
    }
    return maxDigit - '0';
}