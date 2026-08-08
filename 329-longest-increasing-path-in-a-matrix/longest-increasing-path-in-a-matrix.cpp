class Solution {
    int n,m;
    bool isValid(int r,int c){
        return r>=0 && r<n && c>=0 && c<m;
    }

public:
    int dfs(int r,int c,
            vector<vector<int>>&matrix,
            vector<vector<int>>&dp){

        if(dp[r][c]!=-1)
            return dp[r][c];

        int ro[4]={-1,1,0,0};
        int co[4]={0,0,-1,1};

        int maxL=1;

        for(int i=0;i<4;i++){
            int nr=ro[i]+r;
            int nc=co[i]+c;

            if(isValid(nr,nc) && matrix[nr][nc]>matrix[r][c]){
                maxL=max(maxL,1+dfs(nr,nc,matrix,dp));
            }
        }

        return dp[r][c]=maxL;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        n=matrix.size();
        m=matrix[0].size();

        vector<vector<int>>dp(n,vector<int>(m,-1));
        // vector<vector<bool>>vis(n,vector<bool>(m,false));

        int maxi=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                    maxi=max(maxi,dfs(i,j,matrix,dp));
                
            }
        }

        for(auto el:dp){
            for(auto e:el)
                cout<<e<<" ";
            cout<<endl;
        }
        return maxi;
        
    }
};