class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.size(),m=t.size();
        if(m>n)
            return "";

        unordered_map<char,int>mpt;
        unordered_map<char,int>mps;

        for(auto ch:t)
            mpt[ch]++;
        
        int freq=mpt.size();
        int reqF=0;

        int left=0;
        int startIdx=-1,size=1e9;
        for(int right=0;right<n;right++){
            char curChar=s[right];
            mps[curChar]++;
            if(mps[curChar]==mpt[curChar]){
                reqF++;
                while(left <= right && reqF==freq){
                    if(size > right-left+1){
                        size= right - left + 1;
                        startIdx=left;
                    }
                    mps[s[left]]--;
                    if(mps[s[left]]<mpt[s[left]])
                        reqF--;
                    left++;
                }
            }
        }
        
        return size==1e9?"":s.substr(startIdx,size);
    }
};