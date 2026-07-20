class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // int n=flights.size();
        unordered_map<int,vector<pair<int,int>>>adj;
        
        for(auto flight:flights){
            int src=flight[0],dest=flight[1],cost=flight[2];
            adj[src].push_back({dest,cost});
        }

        queue<tuple<int,int,int>>pq;
        vector<int>dist(n,1e9);

        pq.push({0,src,0});  //stops , node, node;
        dist[src]=0;

        while(!pq.empty()){
            auto [stops,node,cost]=pq.front();pq.pop();
            // if(node==dst)
            //     return cost;


            if(stops>k)
                continue;

            for(auto [neiNode,neiCost]:adj[node]){
                if(neiCost + cost < dist[neiNode]){
                    dist[neiNode]=neiCost + cost;
                    pq.push({stops+1,neiNode,dist[neiNode]});
                }
            }
        }

        return dist[dst]==1e9?-1:dist[dst];
    }
};