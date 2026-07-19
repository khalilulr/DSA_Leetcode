class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        //3,1,2,4
        int n=arr.size();

        vector<int>pre,suf;
        stack<int>st;

        for(int i=0;i<n;i++){
            int num=arr[i];
            while(!st.empty() && arr[st.top()] >= num)
                st.pop();
            if(st.empty())
                pre.push_back(-1);
            else pre.push_back(st.top());

            st.push(i);
        }
        while(!st.empty())
            st.pop();

        for(int i=n-1;i>=0;i--){
              int num=arr[i];
            while(!st.empty() && arr[st.top()] > num)
                st.pop();
            if(st.empty())
                suf.push_back(n);
            else suf.push_back(st.top());

            st.push(i);
        }
        reverse(suf.begin(),suf.end());
        // int ans=0;

         long long ans = 0;
        const int MOD = 1e9 + 7;

        for (int i = 0; i < n; i++) {

            long long left = i - pre[i] ;
            long long right = suf[i] - i ;

            ans = (ans + 1LL * left * right*arr[i]) % MOD;
        }

        return (int)ans;
    }
};