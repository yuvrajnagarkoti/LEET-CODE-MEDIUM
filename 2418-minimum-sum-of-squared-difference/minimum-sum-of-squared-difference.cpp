class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        long long k = (long long)k1 + k2;
        int n = nums1.size();

        vector<int> diff(n);
        int maxi = 0;

        for (int i = 0; i < n; i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
            maxi = max(maxi, diff[i]);
        }

        long long total = 0;
        for (int x : diff) {
            total += x;
        }

        if (total <= k) return 0;

        int low = 0, high = maxi;

        while (low < high) {
            int mid = low + (high - low) / 2;
            long long needed = 0;

            for (int x : diff) {
                if (x > mid) {
                    needed += x - mid;
                }
            }

            if (needed <= k)
                high = mid;
            else
                low = mid + 1;
        }

        int limit = low;
        long long ans = 0;
        long long remaining = k;

        for (int x : diff) {
            if (x > limit) {
                remaining -= x - limit;
                x = limit;
            }
            ans += 1LL * x * x;
        }

        // Use leftover operations to reduce differences at the limit.
        // Each such reduction changes limit^2 to (limit-1)^2.
        // Apply them to as many elements as possible.
        if (limit > 0 && remaining > 0) {
            for (int i = 0; i < n && remaining > 0; i++) {
                if (diff[i] >= limit) {
                    ans -= 1LL * limit * limit;
                    ans += 1LL * (limit - 1) * (limit - 1);
                    remaining--;
                }
            }
        }

        return ans;
    }
};