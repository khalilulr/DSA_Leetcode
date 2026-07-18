class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
       //[a,b]  b a
       // 
       int n=numCourses;
       unordered_map<int,vector<int>>mp;
       vector<int>inEdge(n,0);
       for(auto pre:prerequisites){
        int u=pre[0],v=pre[1];
        mp[v].push_back(u);
        inEdge[u]++;
       }

       queue<int>q;
       vector<int>order;
       for(int i=0;i<n;i++){
        if(inEdge[i]==0)
            q.push(i);
       }

       while(!q.empty()){
         int node=q.front();q.pop();
         order.push_back(node);
         for(auto nei:mp[node]){
            inEdge[nei]--;
            if(inEdge[nei]==0)
                q.push(nei);
         }
       }

       return order.size()==n?order:vector<int>{};
    }
};