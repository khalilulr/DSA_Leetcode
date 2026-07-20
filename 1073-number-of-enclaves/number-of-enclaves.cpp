class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();

        queue<pair<int,int>>q;
        vector<vector<bool>>vis(n,vector<bool>(m,false));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && (i==n-1 || i==0 || j==0 || j==m-1)){
                    q.push({i,j});
                    vis[i][j]=true;
                }
            }
        }

        int ro[4]={-1,1,0,0};
        int co[4]={0,0,-1,1};

        while(!q.empty()){
            auto [r,c]=q.front();q.pop();

            for(int i=0;i<4;i++){
                int nr=ro[i]+r;
                int nc=co[i]+c;
                if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==1 &&!vis[nr][nc]){
                    q.push({nr,nc});
                    vis[nr][nc]=true;
                }
            }
        }

        int cnt=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]==1)
                    cnt++;
            }
        }
        return cnt;
    }
};