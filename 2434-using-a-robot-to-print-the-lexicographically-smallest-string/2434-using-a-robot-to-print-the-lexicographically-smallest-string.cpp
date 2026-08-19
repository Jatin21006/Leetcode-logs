class Solution {
public:
    string robotWithString(string s) {
        int n=s.size();
        vector<char> suf(n);   
        suf[n-1]=s[n-1];  
        for(int i=n-2;i>=0;i--){
            suf[i]=min(suf[i+1],s[i]);
        }   
        stack<char> st;
        string ans;
        for(int i=0;i<n;i++){
            while(!st.empty() && st.top()<=suf[i]){
                ans+=st.top();
                st.pop();
            }
            st.push(s[i]);
        }
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};