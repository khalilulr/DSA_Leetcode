class Solution {
public:
    void solve(int i,vector<int>&nums,vector<int>ss,vector<vector<int>>&ans){
        if(i>=nums.size()){
            ans.push_back(ss);
            return;
        }
        ss.push_back(nums[i]);
        solve(i+1,nums,ss,ans);
        ss.pop_back();
        solve(i+1,nums,ss,ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>ans;
        vector<int>ss;
        solve(0,nums,ss,ans);
        return ans;
    }
};