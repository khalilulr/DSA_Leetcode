class Solution {
public:
    int numDecodings(string s) {
        int n=s.size();
        vector<int>dp(n+1,0);
        
        if(s[0]=='0')
            return 0;

        dp[0]=1;
        dp[1]=1;
       

        for(int i=2;i<=n;i++){
            int firstD=s[i-2]-'0';
            int secD=s[i-1]-'0';

           
            int num=firstD*10 + secD;
            if(secD>0)
                dp[i]+=dp[i-1];
            
            if(num>=10 && num<=26)
                dp[i]+=dp[i-2];
        }

        for(auto el:dp)
            cout<<el<<" ";

        return dp[n];
    }
};