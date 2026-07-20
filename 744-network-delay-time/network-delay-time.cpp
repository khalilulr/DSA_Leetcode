class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        unordered_map<int, vector<pair<int,int>>> adj;

        for(auto &el : times){
            int u = el[0];
            int v = el[1];
            int t = el[2];

            adj[u].push_back({v,t});
        }

        // vector<int> dist(n+1, 1e9);

       queue<pair<int,int>> q;
        vector<int> dist(n+1,1e9);
        int src=k;
        dist[src]=0;
        q.push({src,0});

    while(!q.empty()){

        auto [u,time]=q.front();
        q.pop();

        for(auto [v,w]:adj[u]){

            if(time+w<dist[v]){
                dist[v]=time+w;
                q.push({v,dist[v]});
            }
        }
    }

        int ans = 0;

        for(int i=1;i<=n;i++){

            if(dist[i] == 1e9)
                return -1;

            ans = max(ans, dist[i]);
        }

        return ans;
    }
};