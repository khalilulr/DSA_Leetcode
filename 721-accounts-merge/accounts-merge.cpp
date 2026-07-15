class Solution {
public:
//find parent
    int find(int x, vector<int>& parents){
    if (parents[x] == x)
        return x;
    return parents[x] = find(parents[x], parents); 
}
    void unite(vector<int>&parents,int x,int y){
        int px=find(x,parents);
        int py=find(y,parents);
        if (px != py) parents[px] = py;
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        vector<int>parents(n,0);
        for(int i=0;i<n;i++)
            parents[i]=i;
        unordered_map<string,int>mp;
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                string email=accounts[i][j];
                if(mp.find(email)!=mp.end()){
                    unite(parents,i,mp[email]);
                }else
                    mp[email]=i;
            }
        }

        unordered_map<int,set<string>>acc;
        for(int i=0;i<n;i++){
            int root=find(i,parents);
            for(int j=1;j<accounts[i].size();j++)
                acc[root].insert(accounts[i][j]);
        }

        vector<vector<string>>ans;
        for(auto el:acc){
            string name=accounts[el.first][0];
            vector<string>temp;
            temp.push_back(name);
            for(auto e:el.second){
                temp.push_back(e);
            }
            ans.push_back(temp);
        }
        return ans;

    }
};