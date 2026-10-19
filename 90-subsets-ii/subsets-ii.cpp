class Solution {
public:
    void solve(int i,int n,vector<int>&nums,vector<int>ss,vector<vector<int>>&ans){
        if(i==n){
            ans.push_back(ss);
            return;
        }
        ss.push_back(nums[i]);
        solve(i+1,n,nums,ss,ans);
        ss.pop_back();
        while(i+1<n && nums[i]==nums[i+1])
            i++;
        solve(i+1,n,nums,ss,ans);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>ss;
        vector<vector<int>>ans;

        solve(0,nums.size(),nums,ss,ans);

        return ans;
    }
};