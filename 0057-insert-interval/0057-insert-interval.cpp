class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if(newInterval.empty())return intervals;
        if(intervals.empty())return {newInterval};
        int n=intervals.size();
        int start=newInterval[0];
        int end=newInterval[1];
        //figuring out new start and end
        for(int i=0;i<n;i++){
            int currS=intervals[i][0];
            int currE=intervals[i][1];
            //are they overlapping
            if((start>=currS && start<=currE)||(end>=currS && end<=currE)){
                //yes they are overlapping
                start=min(start,currS);
                end=max(end,currE);
            }
            //if they are not 
            else if(end<currS)break;//no need to go futher
        }

        //building out the answer
        bool placed=false;
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            int currS=intervals[i][0];
            int currE=intervals[i][1];
            if(!placed){
                if(currE<start)ans.push_back({currS,currE});
                else{
                    ans.push_back({start,end});
                    placed=true;
                    i--;
                }
            }
            else{
                if(currS>end)ans.push_back({currS,currE});
            }
            
        }
        if(!placed)ans.push_back({start,end});
        return ans;
        
    }
};