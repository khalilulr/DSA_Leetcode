class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,0);
        dp[0]=nums[0];

        if(n==1)
            return nums[0];

        int prev=max(nums[0],nums[1]);
        int prev2=nums[0];
        int cur=max(prev,prev2);

        for(int i=2;i<n;i++){
            cur=max(prev,prev2+nums[i]);
            prev2=prev;
            prev=cur;
        }

        return cur;
    }
};