int com(const void*a,const void *b)
{
    return (*(int*)a-*(int*)b);
}

int minimumPushes(char* word) 
{
  int i,len,*arr,re=0;
  len=strlen(word);
  arr=calloc(sizeof(int),26);
  for(i=0;i<len;++i)
    arr[(int)word[i]-97]+=1;
  qsort(arr,26,sizeof(int),com);
  for(i=25;i>=0;--i)
    {
        if(arr[i]==0)
          break;
        else if(i>=18)
          re+=arr[i];
        else if(i>=10)
          re+=(arr[i]*2);
        else if(i>=2)
          re+=(arr[i]*3);
        else
          re+=(arr[i]*4);
    }
  return re;
}