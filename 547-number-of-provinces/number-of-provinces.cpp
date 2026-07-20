class Solution {
public:
    int ulp(int node,vector<int>&parent){
        if(node==parent[node])
            return node;
        return parent[node]=ulp(parent[node],parent);
    }

    void unionG(int x,int y,vector<int>&parent,vector<int>&rank){
        int ulpX=ulp(x,parent);
        int ulpY=ulp(y,parent);

        if(rank[ulpX] > rank[ulpY]){
            parent[ulpY]=ulpX;
        }else{
            parent[ulpX]=ulpY;
            if(rank[ulpX]==rank[ulpY])
                rank[ulpX]++;
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();

        vector<int>parent(n,-1);
        vector<int>rank(n,-1);

        for(int i=0;i<n;i++)
            parent[i]=i;

        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]){
                    int px=i;
                    int py=j;

                    if(ulp(px,parent)!=ulp(py,parent)){
                        unionG(px,py,parent,rank);
                        // cnt++;
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            if(parent[i]==i)
                cnt++;
        }
        return cnt;
    }
};