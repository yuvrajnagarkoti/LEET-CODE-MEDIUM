class Node
{
    
    public:
    int val;
    int min;
    Node(int v,int m)
    {
        val = v;
        min = m;
    }
};

class MinStack
{
public:

    stack<Node> st;
    MinStack()
    {
    }
    
    void push(int value)
    {
        if(st.empty())
        {
            Node n(value,value);
            st.push(n);
        }
        else
        {
            int m = st.top().min;
            if(value < m)
                m=value;
            st.push(Node (value,m));
        }
    }
    
    void pop()
    {
        st.pop();
    }
    
    int top()
    {
        return st.top().val;  
    }
    
    int getMin()
    {
        return st.top().min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */