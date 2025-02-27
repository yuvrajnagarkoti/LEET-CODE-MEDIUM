int minPartitions(char* n)
{
    char max= '0' ;
    for(int i=0; n[i]!='\0' ;i++)
    {
        if( max < n[i] )
        {
            max=n[i];
        }
    }
    return max-'0';
}