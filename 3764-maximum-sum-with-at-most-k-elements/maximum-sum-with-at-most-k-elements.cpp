class Solution {
public:
    long long maxSum(vector<vector<int>>& grid, vector<int>& limits, int k) {
        priority_queue<int,vector<int>,greater<>>pq1,pq2;
        int n=grid.size();
        for(int i=0;i<n;i++){
            vector<int>el=grid[i];
            for(auto e:el){
                pq1.push(e);
                if(pq1.size()>limits[i])
                    pq1.pop();
            }
            while(!pq1.empty()){
                pq2.push(pq1.top());
                pq1.pop();
                if(pq2.size()>k)
                    pq2.pop();
            }
        }
        long long ans=0;
        while(!pq2.empty()){
            ans+=pq2.top();
            pq2.pop();
        }

        return ans;
    }
};