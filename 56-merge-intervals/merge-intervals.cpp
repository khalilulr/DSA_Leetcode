class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[](vector<int>&a,vector<int>&b){
            return a[0]<b[0];
        });
        vector<vector<int>>ans;
        vector<int>prev(2,0);
        prev[0]=intervals[0][0];
        prev[1]=intervals[0][1];
        for(auto interval:intervals){
            if(interval[0]<=prev[1]){
                prev[1]=max(prev[1],interval[1]);
            }else{
                ans.push_back(prev);
                prev[0]=interval[0];
                prev[1]=interval[1];
            }
        }
        ans.push_back(prev);
        return ans;

    }
};