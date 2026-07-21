class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();

        vector<int>dp(n,1);
        vector<int>parent(n,0);

        int maxi=INT_MIN;
        int idx=-1;

        for(int i=0;i<n;i++)
            parent[i]=i;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0 && dp[i]<dp[j]+1){
                    dp[i]=dp[j]+1;
                    parent[i]=j;
                }
            }
            if(dp[i]>maxi){
                maxi=dp[i];
                idx=i;
            }
        }
        
        vector<int>ans;

        while(parent[idx]!=idx){
            ans.push_back(nums[idx]);
            idx=parent[idx];
        }
        ans.push_back(nums[idx]);
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
};