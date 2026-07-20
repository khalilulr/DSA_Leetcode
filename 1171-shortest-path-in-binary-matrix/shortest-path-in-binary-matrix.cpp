class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();

        if(grid[0][0]==1)
            return -1;

        int ro[8]={-1,1,0,0,-1,-1,1,1};
        int co[8]={0,0,-1,1,-1,1,-1,1};

        int steps=1;
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        queue<pair<int,int>>q;


        q.push({0,0});
        vis[0][0]=true;

        while(!q.empty()){
            int size=q.size();
            for(int s=0;s<size;s++){
                auto [r,c]=q.front();q.pop();
                if(r==n-1 && c==m-1)
                    return steps;
                for(int i=0;i<8;i++){
                    int nr=ro[i]+r;
                    int nc=co[i]+c;

                    if(nr >= 0 && nr<n && nc>=0 && nc<m && !vis[nr][nc] && grid[nr][nc]==0){
                        q.push({nr,nc});
                        vis[nr][nc]=true;
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};