class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity)
    {
        int step = 0;
        int water = capacity;
        for(int i=0;i<plants.size();i++)
        {
            if(water >= plants[i])
            {
                water -= plants[i];
                step++;
            }
            else
            {
                water = capacity;
                water -= plants[i];

                step += i;
                step += i+1;
            }
        }

        return step;
    }
};