class Solution {
public:
    int furthestDistanceFromOrigin(string moves)
    {
        int count=0;
        int x=0;
        for(int i=0;i<moves.size();i++)
        {
            if(moves[i] == '_')
                count++;
            else if(moves[i] == 'L')
                x--;
            else
                x++;
        }
        if(x>0)
            return x+count;
        return -x+count;
    }
};