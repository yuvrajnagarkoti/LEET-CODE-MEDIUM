class Solution
{
public:
    vector<long long> maximumEvenSplit(long long finalSum)
    {
        vector<long long> result;
        if (finalSum % 2 != 0)
            return result;
        long long current = 2;
        long long sum = 0;
        while (sum + current <= finalSum)
        {
            result.push_back(current);
            sum += current;
            current += 2;
        }
        // Adjust the last element if needed
        if (sum != finalSum)
        {
            result.back() += (finalSum - sum);
        }
        return result;
    }
};