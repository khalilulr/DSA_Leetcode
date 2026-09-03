class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //1-->0
        queue<int>q;
        vector<int>inEdge(numCourses,0);
        unordered_map<int,vector<int>>adj;
        for(auto req:prerequisites){
            int u=req[0],v=req[1];
            adj[u].push_back(v);
            inEdge[v]++;
        }

        for(int i=0;i<numCourses;i++){
            if(inEdge[i]==0)
                q.push(i);
        }

        vector<int>ans;
        while(!q.empty()){
            int node=q.front();q.pop();
            ans.push_back(node);
            for(auto nei:adj[node]){
                inEdge[nei]--;
                if(inEdge[nei]==0)
                    q.push(nei);
            }
        }

        return ans.size()==numCourses?true:false;
    }
};