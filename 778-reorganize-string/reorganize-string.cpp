class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int>mp;
        int maxi=0,n=s.size();

        for(auto ch:s){
            mp[ch]++;
            maxi=max(maxi,mp[ch]);
        }

        if(maxi > (n+1)/2)
            return "";

        priority_queue<pair<int,char>>pq;

        for(auto [el,f]:mp)
            pq.push({f,el});

        string ans;
        char prevCh='#';
        int prevF=0;

        while(!pq.empty()){
            auto [f,ch]=pq.top();pq.pop();
            ans.push_back(ch);

            f=f-1;
            if(prevCh!=ch && prevCh!='#'){
                pq.push({prevF,prevCh});
            }
            if(f!=0){
                prevF=f;
                prevCh=ch;
            }else prevCh='#';
        }
        return ans;
    }
};