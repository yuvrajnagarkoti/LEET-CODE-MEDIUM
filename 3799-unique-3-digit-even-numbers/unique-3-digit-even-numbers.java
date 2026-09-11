class Solution {
    public int totalNumbers(int[] digits)
    {
        int count = 0;
        int[] freq = new int[10];
        for(int d : digits)
            freq[d]++;
        
        for(int i = 100; i <= 998; i += 2)
        {
            int a = i / 100;
            int b = (i / 10) % 10;
            int c = i % 10;

            if(freq[a] > 0)
            {
                freq[a]--;

                if(freq[b] > 0)
                {
                    freq[b]--;

                    if(freq[c] > 0)
                        count++;

                    freq[b]++;
                }
                freq[a]++;
            }
        }

        return count;
    }
}