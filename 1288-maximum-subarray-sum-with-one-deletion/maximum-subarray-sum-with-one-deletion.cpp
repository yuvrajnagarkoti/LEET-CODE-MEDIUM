class Solution {
public:
    int maximumSum(vector<int>& arr)
    {
        int nodel=arr[0];
        int onedel=0;
        int ans=arr[0];
        for(int i=1;i<arr.size();i++)
        {
            onedel=max(nodel,onedel+arr[i]);
            nodel=max(nodel+arr[i],arr[i]);
            ans=max(ans,max(onedel,nodel));
        }
        return ans;
    }  
};