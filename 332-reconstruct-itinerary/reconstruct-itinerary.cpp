class Solution {
    unordered_map<string,priority_queue<string,vector<string>,greater<>>>adj;
public:
    void solve(string node,vector<string>&result){
        while(!adj[node].empty()){
            string nei=adj[node].top();
            adj[node].pop();
            solve(nei,result);
        }
            result.push_back(node);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {

        for(auto ticket:tickets){
            string src=ticket[0],dest=ticket[1];
            adj[src].push(dest);
        }

        vector<string>result;
        solve("JFK",result);
        reverse(result.begin(),result.end());
        return result;

    }
};