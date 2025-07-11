class Solution
{
public:
    void merge(vector<int> &arr, int l, int mid, int h)
    {
        int n1 = mid - l + 1;
        int n2 = h - mid;
        vector<int> left(n1);
        vector<int> right(n2);

        for (int i = 0; i < n1; i++)
            left[i] = arr[l + i];
        for (int j = 0; j < n2; j++)
            right[j] = arr[mid + 1 + j];

        int i = 0, j = 0, k = l;
        
        while (i < n1 && j < n2)
        {
            if (left[i] <= right[j])
            {
                arr[k++] = left[i++];
            }
            else
            {
                arr[k++] = right[j++];
            }
        }

        while (i < n1)
        {
            arr[k++] = left[i++];
        }

        while (j < n2)
        {
            arr[k++] = right[j++];
        }
    }

    void mergesort(vector<int> &nums, int l, int h)
    {
        if (l < h)
        {
            int mid = l + (h - l) / 2;
            mergesort(nums, l, mid);
            mergesort(nums, mid + 1, h);
            merge(nums, l, mid, h);
        }
    }

    vector<int> sortArray(vector<int> &nums)
    {
        mergesort(nums, 0, nums.size() - 1);
        return nums;
    }
};