class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0,n=s.size(),ans=0;
        unordered_map<char,int>mp;

        for(int r=0;r<n;r++){
            char curChar=s[r];
            mp[curChar]++;
            
            while(mp[curChar]>1){
                mp[s[l]]--;
                l++;
                if(mp[s[l]]==0)
                    mp.erase(s[l]);
            }
            ans=max(ans,r-l+1);
        }

        return ans;
    }
};