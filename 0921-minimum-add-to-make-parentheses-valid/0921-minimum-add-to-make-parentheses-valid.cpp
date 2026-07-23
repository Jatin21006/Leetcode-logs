class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        for(char c:s){
            if(c=='(')st.push(c);
            else{
                if(st.empty() || st.top()!='(')st.push(c);
                else st.pop();
            }
        }
        int ans=0;
        while(!st.empty()){
            ans++;
            st.pop();
        }
        return ans;
        
    }
};