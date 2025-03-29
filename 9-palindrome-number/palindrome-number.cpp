class Solution
{
public:
    bool isPalindrome(int x)
    {
        if (x < 0) return false;     
        vector<int> ans;
        int temp = x; // Store original value
        while (temp > 0)
        {
            ans.push_back(temp % 10);
            temp /= 10;
        }
        // Compare first half with the second half
        int n = ans.size();
        for (int i = 0; i < n / 2; i++)
        {
            if (ans[i] != ans[n - 1 - i]) 
                return false;
        }
        return true;
    }
};