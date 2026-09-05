class Solution {
public:
    int compress(vector<char>& chars)
    {
        int i=0,index=0,n=chars.size();
        char cur=chars[0];
        int count=0;
        while(i<n)
        {
            if(chars[i] == cur)
            {
                count++;
            }
            else
            {
                chars[index]=cur;
                index++;
                if(count > 1)
                {
                    string num = to_string(count);
                    for(int j=0;j<num.length();j++)
                    {
                        chars[index] = num[j];
                        index++;
                    }
                }
                cur = chars[i];
                count=1;
            }

            i++;
        }
        chars[index]=cur;
        index++;
        if(count > 1)
        {
            string num = to_string(count);
            for(int j=0;j<num.length();j++)
            {
                chars[index] = num[j];
                index++;
            }
        }
        return index;
    }
};