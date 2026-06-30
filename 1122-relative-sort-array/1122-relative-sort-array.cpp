class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int,int> pos;
        for (int x : arr2) pos[x] = 0;

        vector<int> complement;
        for (int x : arr1) {
            if (pos.count(x))
                pos[x]++;
            else
                complement.push_back(x);
        }
        
        vector<int> res;
        for(int x:arr2){
            res.insert(res.end(),pos[x],x);
        }
        sort(complement.begin(),complement.end());
        res.insert(res.end(),complement.begin(),complement.end());
        return res;
    }
};