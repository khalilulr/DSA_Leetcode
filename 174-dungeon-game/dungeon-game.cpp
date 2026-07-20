class Solution {
    int n,m;
    vector<vector<int>>dp;
public:
    int solve(int i,int j, vector<vector<int>>&d){
        if(i<0 || i>=n  || j<0 || j>=m)
            return 1e9;

        if(i==n-1 && j==m-1){
            if(d[i][j]>0){
                return 1;
            }
            return abs(d[i][j])+1;
        }

        else if(dp[i][j]!=-1)
            return dp[i][j];

        int right=solve(i,j+1,d);
        int down=solve(i+1,j,d);

        int result = min(down,right) - d[i][j];
        return dp[i][j]=result>0?result:1;
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        // num>5 , cur=3+1 
        n=dungeon.size(),m=dungeon[0].size();
        dp=vector<vector<int>>(n,vector<int>(m,-1));
       return solve(0,0,dungeon);
    }
};