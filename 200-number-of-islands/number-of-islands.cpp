class Solution {
public:
    void dfs(int i,int j,vector<vector<char>>& grid,vector<vector<bool>>&vis){
        vis[i][j]=true;
        int ro[4]={-1,1,0,0};
        int co[4]={0,0,-1,1};
        for(int k=0;k<4;k++){
            int nr=ro[k]+i;
            int nc=co[k]+j;
            if(nr>=0 && nr<grid.size() && nc>=0 && nc<grid[0].size() && grid[nr][nc]=='1' &&  !vis[nr][nc]){
                dfs(nr,nc,grid,vis);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && !vis[i][j]){
                    dfs(i,j,grid,vis);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};