class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();

        vector<vector<int>>dp(n,vector<int>(amount+1,0));
        vector<unsigned long long>prev(amount+1,0);
        vector<unsigned long long>cur(amount+1,0);

        prev[0]=1;

        if(coins[0]<=amount)
            prev[coins[0]]=1;
        else if(coins[0]==0)
            prev[0]=2;

        for(int j=1;j<=amount;j++){
            if(j%coins[0]==0)
                prev[j]=1;
        }


        for(int i=1;i<n;i++){
            cur[0]=prev[0];
            if(coins[i]==0)
                cur[0]+=prev[0];
            for(int j=1;j<=amount;j++){
                unsigned long long notTake=prev[j];
                unsigned long long take=0;
                if(j-coins[i]>=0)
                    take=cur[j-coins[i]];

                cur[j]=take+notTake;
            }
            prev=cur;
        }
        return int(prev[amount]);
    }
};