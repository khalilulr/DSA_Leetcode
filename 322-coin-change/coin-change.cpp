class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,1e9));

        for(int i=0;i<n;i++)
            dp[i][0]=0;

        for(int i=1;i<=amount;i++){
            if(i%coins[0]==0)
                dp[0][i]=i/coins[0];
        }

        for(int i=1;i<n;i++){
            for(int j=1;j<=amount;j++){
                int notTake=dp[i-1][j];
                int take=1e9;
                if(j-coins[i]>=0)
                    take=dp[i][j-coins[i]] + 1;

                dp[i][j]=min(take,notTake);
            }
        }

        return dp[n-1][amount]==1e9?-1:dp[n-1][amount];
    }
};