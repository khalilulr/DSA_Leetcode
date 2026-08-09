class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        //find a num, having min 
        sort(intervals.begin(),intervals.end());
        vector<pair<int,int>>q;
        int n=queries.size();

        for(int i=0;i<n;i++){
            q.push_back({queries[i],i});
        }
        sort(q.begin(),q.end());

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;
        vector<int>ans(n,0);
        int i=0;
        for(auto [qu,idx]:q){
            while(i<intervals.size() && intervals[i][0] <= qu){
                int l=intervals[i][0];
                int r=intervals[i][1];

                int size=r-l+1;
            
                pq.push({size,r});

                i++;
            }
            while(!pq.empty() && pq.top().second < qu)
                pq.pop();

            if(!pq.empty())
                ans[idx]=pq.top().first;
            else ans[idx]=-1; 
        }

        return ans;
    }
};