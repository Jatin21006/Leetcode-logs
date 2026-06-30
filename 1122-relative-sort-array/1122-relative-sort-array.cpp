class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> st(arr2.begin(),arr2.end());
        unordered_map<int , int> hash;
        vector<int> complement;
        for(int i=0;i<arr1.size();i++){
            if(st.find(arr1[i])!=st.end())hash[arr1[i]]++;
            else complement.push_back(arr1[i]);
        }
        vector<int> res;
        for(int i=0;i<arr2.size();i++){
            res.insert(res.end(),hash[arr2[i]],arr2[i]);
        }
        sort(complement.begin(),complement.end());
        res.insert(res.end(),complement.begin(),complement.end());
        return res;
    }
};