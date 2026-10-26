class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0,n=s.size(),ans=0;
        priority_queue<pair<int,char>>pq;
        unordered_map<char,int>mp;

        for(int r=0;r<n;r++){
            char ch=s[r];
            mp[ch]++;;
            pq.push({mp[ch],ch});


            while(l<r && r-l+1-pq.top().first > k ){
                mp[s[l]]--;
                l++;
                vector<pair<char,int>>temp;
                while(!pq.empty())
                    pq.pop();
                for(auto [el,fr]:mp)
                    pq.push({fr,el});
            }

            ans=max(ans,r-l+1);
        }

        return ans;
    }
};