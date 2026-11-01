class Solution {
public:

    int check(int temp)
    {
        int sum = 0;

        while(temp > 0)
        {
            int t = temp % 10;
            sum += t * t;
            temp /= 10;
        }

        return sum;
    }

    bool isHappy(int n)
    {
        unordered_set<int> st;

        while(n != 1)
        {
            if(st.find(n) != st.end())
                return false;

            st.insert(n);

            n = check(n);
        }

        return true;
    }
};