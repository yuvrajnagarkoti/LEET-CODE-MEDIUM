class Solution {
    public int scoreOfParentheses(String s)
    {
        Stack<Integer> st = new Stack<>();
        st.push(0);
        for(int i=0;i<s.length();i++)
        {
            if(s.charAt(i) == '(')
                st.push(0);
            else
            {
                int temp = st.peek();
                st.pop();
                
                int count = temp==0? 1 : 2*temp;
                int parent = st.peek();
                st.pop();

                st.push(count+parent);
            }
        }

        return st.peek();    
    }
}