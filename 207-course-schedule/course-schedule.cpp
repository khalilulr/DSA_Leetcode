class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // b-->a
        unordered_map<int,vector<int>>adj;
        vector<int>inEdge(numCourses,0);
        for(auto pre:prerequisites){
            int u=pre[0],v=pre[1];
            //v-->u
            inEdge[u]++;
            adj[v].push_back(u);
        }
        queue<int>q;
        vector<int>ord;
        for(int i=0;i<numCourses;i++){
            if(inEdge[i]==0)
                q.push(i);
        }
        while(!q.empty()){
            int course=q.front();q.pop();
            ord.push_back(course);
            for(auto ne:adj[course]){
                inEdge[ne]--;
                if(inEdge[ne]==0)
                    q.push(ne);
            }
        }
        return ord.size()==numCourses;
    }
};