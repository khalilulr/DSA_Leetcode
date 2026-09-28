class Solution {
public:
    string frequencySort(string s) {
        priority_queue<pair<int,char>>pq;
        unordered_map<char,int>mp;

        for(auto ch:s)
            mp[ch]++;

        for(auto [el,freq]:mp){
            pq.push({freq,el});
        }

        string ans="";

        while(!pq.empty()){
            char ch=pq.top().second;
            int freq=pq.top().first;

            for(int i=0;i<freq;i++)
                ans+=ch;
            pq.pop();
        }

        return ans;
    }
};