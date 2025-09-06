class RandomizedSet
{
    private:
    vector<int> nums;
    unordered_map <int,int> mpp;
    
    public:
    RandomizedSet(){
    }
    
    bool insert(int val)
    {
        if(mpp.find(val) == mpp.end())
        {
            nums.push_back(val);
            mpp[val]=nums.size()-1;
            return true;
        }
        return false;
    }
    
    bool remove(int val)
    {
        if (mpp.find(val) == mpp.end()) return false;
        
        int idx = mpp[val];          // index of val to remove
        int last = nums.back();      // last element in nums
        // move last element into idx position
        nums[idx] = last;
        mpp[last] = idx;
        // remove last element
        nums.pop_back();
        mpp.erase(val);
        return true;
    }
    
    int getRandom()
    {
        int index = rand() % nums.size();
        return nums[index];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */