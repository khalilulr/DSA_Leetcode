class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int>freq(26,0);
        int n=s.size(),m=t.size();
        if(n!=m)
            return false;
        for(int i=0;i<n;i++){
            int idx=s[i]-'a';
            int idx1=t[i]-'a';
            freq[idx]++;
            freq[idx1]--;
        }
        for(auto el:freq)
            cout<<el<<" ";
        for(int i=0;i<26;i++){
            if(freq[i]!=0)
                return false;
        }
        return true;
    }
};