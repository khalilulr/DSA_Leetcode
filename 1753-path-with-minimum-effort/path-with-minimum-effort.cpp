class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size(),m=heights[0].size();
        vector<vector<int>>dist(n,vector<int>(m,1e9));

        int ro[4] = {-1, 1, 0, 0};
        int co[4] = {0, 0, -1, 1};

        using T = tuple<int,int,int>;
        priority_queue<T, vector<T>, greater<>> q;
        q.push({0,0,0});
        dist[0][0]=0;

        while(!q.empty()){
            auto [eff,r,c]=q.top();q.pop();
            if(r==n-1 && c==m-1)
                return eff;


            for(int i=0;i<4;i++){
                int nr=ro[i]+r;
                int nc=co[i]+c;

                if(nr>=0 && nr<n && nc>=0 && nc<m){

                    int absD=abs(heights[r][c]-heights[nr][nc]);
                    int maxE=max(eff,absD);

                    if(maxE<dist[nr][nc]){
                        dist[nr][nc]=maxE;
                        q.push({maxE,nr,nc});
                    }
                }
            }
        } 
        return 0;

    }
};