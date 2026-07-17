class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int cntFreshO=0;
        queue<pair<int,pair<int,int>>>q;
        int n=grid.size(),m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1)
                    cntFreshO++;
                else if(grid[i][j]==2)
                    q.push({0,{i,j}});
            }
        }
        if(cntFreshO==0)
            return 0;
        int ro[4]={-1,1,0,0};
        int co[4]={0,0,-1,1};
        int maxi=0;
        while(!q.empty()){
            auto [time,r_c]=q.front();q.pop();
            maxi=max(maxi,time);
            auto [r,c]=r_c;
            for(int i=0;i<4;i++){
                int nr=ro[i]+r;
                int nc=co[i]+c;
                if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==1){
                    cntFreshO--;
                    q.push({time+1,{nr,nc}});
                    grid[nr][nc]=2;
                }
            }
        }
        return cntFreshO!=0?-1:maxi;
    }
};