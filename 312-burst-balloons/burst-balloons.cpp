class Solution {
    vector<vector<int>>dp;
public:
    int solve(int s,int e,vector<int>&nums){
        if(s>e)
            return 0;
        if(dp[s][e]!=-1)
            return dp[s][e];
        int maxi=INT_MIN;
        for(int i=s;i<=e;i++){
            int curC=nums[s-1]*nums[i]*nums[e+1] + solve(s,i-1,nums) + solve(i+1,e,nums);
            maxi=max(maxi,curC);
        }

        return dp[s][e]=maxi;
    }
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        int n=nums.size();
       dp= vector<vector<int>>(n+1,vector<int>(n+1,-1));
        return solve(1,n-2,nums);
    }
};