class Solution {
public:
    bool cmp(string &a, string &b) {

    if (a.size() + 1 != b.size())
        return false;

    int i = 0, j = 0;

    while (i < a.size() && j < b.size()) {

        if (a[i] == b[j]) {
            i++;
            j++;
        } else {
            j++; // skip one character from longer string
        }
    }

    return i == a.size();
}
    int longestStrChain(vector<string>& words) {
        int n=words.size();
        sort(words.begin(),words.end(),[](const string &a,const string &b){
            return a.size()<b.size();
        });
        vector<int>dp(n,1);
        int maxi=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(cmp(words[j],words[i]) && dp[i]<dp[j]+1){
                    dp[i]=1+dp[j];
                }
            }
            if(dp[i]>maxi){
                maxi=dp[i];
            }
        }
        return maxi;
    }
};