class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0,n=nums.size();

        for(auto num:nums)
            sum+=num;

        if(sum%2!=0)
            return false;

        int target=sum/2;

        vector<vector<bool>>dp(n,vector<bool>(target+1,false));

        for(int i=0;i<n;i++)
            dp[i][0]=true;

        if(nums[0]<=target)
            dp[0][nums[0]]=true;

        for(int i=1;i<n;i++){
            for(int j=1;j<=target;j++){
                bool take=false;
                bool notTake=dp[i-1][j];

                if(j-nums[i]>=0)
                    take=dp[i-1][j-nums[i]];

                dp[i][j]=take | notTake;
            }
        }

        return dp[n-1][target];

    }
};