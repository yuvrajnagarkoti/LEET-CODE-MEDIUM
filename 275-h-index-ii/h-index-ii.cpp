class Solution {
public:
    int hIndex(vector<int>& citations) {
        int start = 0, end = citations.size() - 1, mid = (start + end) / 2, ans = 0;
        while(start <= end) {
            int cites = citations[mid];
            int papers = citations.size() - mid;
            if(papers <= cites) {
                ans = papers;
                end = mid - 1;
            }
            else {
                start = mid + 1;
            }
            mid = (start + end) / 2;
        }
        return ans;
    }
};