class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int>f1(26,0),f2(26,0);
        int n=s1.size(),m=s2.size();

        if(n>m)
            return false;
        for(int i=0;i<n;i++){
            int idx=s1[i]-'a';
            f1[idx]++;
            f2[s2[i]-'a']++;
        }

        if(f1==f2)
            return true;

        for(int i=n;i<m;i++){
            f2[s2[i]-'a']++;
            f2[s2[i-n]-'a']--;

            if(f1==f2)
                return true;
        }


        return false;
    }
};