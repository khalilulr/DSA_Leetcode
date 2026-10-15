class Solution {
public:
    void solve(int idx,int n,int target,vector<int>&candidates,vector<int>ss,vector<vector<int>>&ans){
        if(target==0){
            ans.push_back(ss);
            return;
        }
        if(idx==n  || target<0)
            return;

        ss.push_back(candidates[idx]);
        solve(idx+1,n,target-candidates[idx],candidates,ss,ans);
        ss.pop_back();
        while(idx+1<n && candidates[idx]==candidates[idx+1])
            idx++;
        solve(idx+1,n,target,candidates,ss,ans);
        
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int>ss;
        vector<vector<int>>ans;
        solve(0,candidates.size(),target,candidates,ss,ans);
        return ans;
    }
};