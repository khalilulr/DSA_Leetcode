class Solution {
public:
    bool isNeiSameColor(int i,vector<int>&color,vector<bool>&vis,vector<vector<int>>&graph){
        vis[i]=true;
        for(auto nei:graph[i]){
            if(!vis[nei]){
                color[nei]=1-color[i];
                if(isNeiSameColor(nei,color,vis,graph))
                    return true;
            }else if(color[nei]==color[i]){
                return true;
            }
        }
        return false;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>color(n,0);
        vector<bool>vis(n,false);

        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(isNeiSameColor(i,color,vis,graph))
                    return false;
            }
        }
        return true;
    }
};