class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,0);
        dp[0]=nums[0];

        if(n>1)
            dp[1]=max(nums[0],nums[1]);

        for(int i=2;i<n;i++){
            int notTake=dp[i-1];
            int take=dp[i-2]+nums[i];
            dp[i]=max(take,notTake);
        }

        return dp[n-1];
    }
};