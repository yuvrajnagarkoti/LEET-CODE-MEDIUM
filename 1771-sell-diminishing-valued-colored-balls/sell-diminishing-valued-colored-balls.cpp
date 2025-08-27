class Solution {
public:
    int maxProfit(vector<int>& inventory, int orders) {
        const int MOD = 1e9 + 7;
        sort(inventory.begin(), inventory.end(), greater<int>());
        inventory.push_back(0); // sentinel
        
        long long ans = 0;
        int n = inventory.size();
        int i = 0;
        
        while (orders > 0) {
            long long curr = inventory[i];
            long long next = inventory[i + 1];
            long long count = i + 1; // how many colors at this level
            long long diff = curr - next; // how many layers we can sell fully
            
            long long totalBalls = diff * count;
            
            if (orders >= totalBalls) {
                // sell all levels down to 'next'
                long long sum = (curr + next + 1) * diff / 2;
                ans = (ans + sum * count) % MOD;
                orders -= totalBalls;
            } else {
                // we cannot sell all, only partial
                long long full = orders / count;
                long long remainder = orders % count;
                
                long long sum = (curr + curr - full + 1) * full / 2;
                ans = (ans + sum * count) % MOD;
                
                ans = (ans + (curr - full) * remainder) % MOD;
                
                orders = 0;
            }
            i++;
        }
        return ans % MOD;
    }
};