class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix)
    {
        int m=matrix.size(),n=matrix[0].size();
        int count=0;
        long long sum=0;
        int minabs=INT_MAX;

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
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
        return sum-minabs-minabs;
    }
};