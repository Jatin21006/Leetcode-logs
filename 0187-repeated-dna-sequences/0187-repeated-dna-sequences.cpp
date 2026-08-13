class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if(s.size()<10)return {};
        unordered_set<string> seen;
        unordered_set<string> repeated;

        for(int i = 0; i <= s.size() - 10; i++) {
            string curr = s.substr(i, 10);

            if(seen.count(curr))
                repeated.insert(curr);
            else
                seen.insert(curr);
        }
        vector<string> ans(repeated.begin(),repeated.end());
        return ans;
    }
};