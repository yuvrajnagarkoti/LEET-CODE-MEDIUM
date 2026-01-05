class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix)
    {
        int count=0;
        long long sum=0;
        int minabs=INT_MAX;

        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                if(matrix[i][j] < 0)
                {
                    count+=1;
                    sum=sum-matrix[i][j];
                }
                else
                {
                    sum=sum+matrix[i][j];
                }
                minabs = min(abs(matrix[i][j]),minabs);
            }
        }
        if(count%2 == 0)
        {
            return sum;
        }
        return sum-2*minabs;
    }
};