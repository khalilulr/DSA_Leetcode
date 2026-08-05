class Solution {
public:
    bool isEqual(string s1,string s2){
        vector<int>freq(26,0);
        for(int i=0;i<s1.size();i++){
            int idx1=s1[i]-'a';
            int idx2=s2[i]-'a';
            freq[idx1]++;
            freq[idx2]--;
        }

        for(int i=0;i<26;i++){
            if(freq[i]!=0)
                return false;
        }

        return true;
    }
    bool checkInclusion(string s1, string s2) {
        int n=s1.size(),m=s2.size();
        if(n>m)
            return false;
        for(int i=0;i<m-n+1;i++){
            string curStr=s2.substr(i,n);
            // cout<<curStr<<endl;
            if(isEqual(s1,curStr))
                return true;
        }
        return false;
    }
};