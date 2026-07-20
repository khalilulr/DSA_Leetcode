class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size();
        queue<pair<int,int>>q;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({i,j});
                }else mat[i][j]=1e9;
            }
        }

        int ro[4]={-1,1,0,0};
        int co[4]={0,0,-1,1};

        while(!q.empty()){
            auto [r,c]=q.front();q.pop();
            for(int i=0;i<4;i++){
                int nr=ro[i]+r;
                int nc=co[i]+c;
                if(nr>=0 && nr<n && nc>=0 && nc<m && mat[nr][nc] > 1 + mat[r][c]){
                    mat[nr][nc]=1+mat[r][c];
                    q.push({nr,nc});
                }
            }
        }
        return mat;
    }
};