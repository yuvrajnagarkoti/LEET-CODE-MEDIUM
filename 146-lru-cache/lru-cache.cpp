class LRUCache
{
public:
    unordered_map<int,pair<int,int>> mpp;
    int count=1;
    int capacity;
    LRUCache(int capacity) 
    {
        this->capacity = capacity;
    }
    
    int get(int key)
    {
        if(mpp.find(key) != mpp.end())
        {
            mpp[key].second = count++;
            return mpp[key].first;
        }
        return -1;
    }
    
    void put(int key, int value)
    {
        
        mpp[key].first = value;
        mpp[key].second = count++;

        if(mpp.size() > capacity)
        {
            int ind=-1;
            int lru=INT_MAX;
            for(auto it : mpp)
            {
                if(it.second.second < lru)
                {
                    lru = it.second.second;
                    ind = it.first;
                }
            }
            
            mpp.erase(ind);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */