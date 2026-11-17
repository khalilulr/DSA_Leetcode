class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,1e9));
        vector<int>prev(amount+1,1e9);
        vector<int>cur(amount+1,1e9);


        prev[0]=0;

        for(int j=1;j<=amount;j++){
            if(j%coins[0]==0)
                prev[j]=j/coins[0];
        }

        for(int i=1;i<n;i++){
            cur[0]=0;
            for(int j=1;j<=amount;j++){
                int notTake=prev[j];
                int take=1e9;
                if(j-coins[i]>=0)
                    take=cur[j-coins[i]] +1;

                cur[j]=min(take,notTake);
            }
            prev=cur;
        }

        return prev[amount]==1e9?-1:prev[amount];
    }
};