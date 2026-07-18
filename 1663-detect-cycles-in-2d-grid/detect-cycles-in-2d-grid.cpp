class Solution {
public:
    bool dfs(int x,int y,int px,int py,vector<vector<bool>>&vis,vector<vector<char>>&grid){
        vis[x][y]=true;
        char curChar=grid[x][y];
        int ro[4]={-1,1,0,0};
        int co[4]={0,0,-1,1};
        for(int i=0;i<4;i++){
            int nr=ro[i]+x;
            int nc=co[i]+y;
            if(nr>=0 && nr<grid.size() && nc>=0 && nc<grid[0].size()){
                if(!vis[nr][nc] && grid[nr][nc]==curChar){
                    if(dfs(nr,nc,x,y,vis,grid))
                        return true;
                }else if (
                    vis[nr][nc] &&
                    grid[nr][nc] == curChar &&
                    (nr != px || nc != py)){
                        return true;
                }
            }
        }
        // vis[x][y]=false;
        return false;
    }
    bool containsCycle(vector<vector<char>>& grid) {
        int n=grid.size(),m=grid[0].size();
        if(n<2 || m<2 )
            return false;
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j]){
                    if(dfs(i,j,-1,-1,vis,grid))
                        return true;
                }

            }
        }
        return false;
    }
};