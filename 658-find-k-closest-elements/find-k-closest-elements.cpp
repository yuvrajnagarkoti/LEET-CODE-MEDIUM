class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int low = 0;
        int high = arr.size() - k;

        // Binary search to find the optimal starting index
        while (low < high) {
            int mid = low + (high - low) / 2;

            // Compare the distance of x from arr[mid] and arr[mid + k]
            // We want the window that has closer elements to x
            if (x - arr[mid] > arr[mid + k] - x) {
                low = mid + 1; // Window should shift to the right
            } else {
                high = mid;    // Window should shift to the left or stay
            }
        }

        // Return the k elements starting from 'low'
        return vector<int>(arr.begin() + low, arr.begin() + low + k);
    }
};