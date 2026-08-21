class Solution {
public:
    vector<int> countBits(int n) {
        // vector<int>ans;
        // for(int i=0;i<=n;i++){
        //     int num=i;
        //     int cnt_bit=0;
        //     while(num){
        //         cnt_bit += (num&1);
        //         num=num>>1;
        //     }
        //     ans.push_back(cnt_bit);
        // }
        // return ans;
         vector<int>dp(n+1);
        int offset=1;
        for(int i=1;i<=n;i++){
            if(offset*2==i)
                offset=i;
            dp[i]=1+dp[i-offset];
        }
        return dp;
    }
};