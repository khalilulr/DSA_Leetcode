class Solution {
    // vector<vector<int>>dp;
    vector<int>dp;
public:
    int solve(int i,int j,vector<int>&arr,int k){
        if(i>=j)
            return 0;
        if(dp[i]!=-1)
            return dp[i];
        int maxi=INT_MIN,len=0;
        int total=0;
        for(int l=i;l<min(j,i+k);l++){
            len++;
            maxi=max(maxi,arr[l]);
            int cost= len * maxi + solve(l+1,j,arr,k);
            total=max(total,cost);
        }
        return dp[i]=total;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
         dp=vector<int>(n, -1);
        return solve(0,n,arr,k);
    }
};