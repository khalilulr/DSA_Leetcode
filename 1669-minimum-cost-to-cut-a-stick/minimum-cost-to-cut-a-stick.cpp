class Solution {
    vector<vector<int>>dp;
public:
    int solve(int i,int j,vector<int>&cuts){
        if(i>j)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int mini=INT_MAX;
        for(int k=i;k<=j;k++){
            int cost=cuts[j+1]-cuts[i-1] + solve(i,k-1,cuts) + solve(k+1,j,cuts);
            mini=min(mini,cost);
        }
        return dp[i][j]=mini;
    }
    int minCost(int n, vector<int>& cuts) {
        // 0 1 3 4 5 7
        //0-3  3--7   7
        // 4-3 + 7 -4 =4

        // int n=cuts.size();
        int m=cuts.size();

        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        dp=vector<vector<int>>(m+2,vector<int>(m+2,-1));
        sort(cuts.begin(),cuts.end());
       return solve(1,m,cuts);
    }
};