class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();

        vector<vector<int>>dp(n,vector<int>(m,0));
        vector<int>temp(m,1);
        int curSum=0;
        for(int i=0;i<n;i++){
            curSum+=grid[i][0];
            dp[i][0]=curSum;
        }
        curSum=0;
        for(int i=0;i<m;i++){
            curSum+=grid[0][i];
            temp[i]=curSum;
        }

        for(int i=1;i<n;i++){
            temp[0]+=grid[i][0];
            for(int j=1;j<m;j++){
                temp[j]=min(temp[j] , temp[j-1])+grid[i][j];
            }
        }

        return temp[m-1];
    }
};