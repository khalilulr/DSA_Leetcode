class Solution {
public:
    void findMaxSize(int l,int r,string s,int &size,int &startIdx){
            int curCnt=1;
            int n=s.size();
            while(l>=0 && r<n && s[l]==s[r]){
                curCnt+=2;
                if(r-l+1 > size){
                    size=r-l+1;
                    startIdx=l;
                }
                l--;
                r++;
            }
    }
    string longestPalindrome(string s) {
        int n=s.size();
        if(n==0)
            return "";
        int startIdx=0,size=1;
        for(int i=0;i<n;i++){
            int l=i-1,r=i+1;
            findMaxSize(l,r,s,size,startIdx);
            l=i;
            r=i+1;
            findMaxSize(l,r,s,size,startIdx);
        }
        
        return s.substr(startIdx,size);
    }
};