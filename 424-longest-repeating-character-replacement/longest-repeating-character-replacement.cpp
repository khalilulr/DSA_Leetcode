class Solution {
public:
    int characterReplacement(string s, int k) {
        // priority_queue<pair<int,char>>pq;
        vector<int>freq(26,0);
        int i=0;
        int ans=0;
        int n=s.size();
        for(int j=0;j<n;j++){
           int idx=s[j]-'A';
           freq[idx]++;
           int maxF=0;

           for(int i=0;i<26;i++)
                maxF=max(maxF,freq[i]);

            if(j-i+1 - maxF <= k)
                ans=max(ans,j-i+1);
            else{
                while(i<j && j-i+1 - maxF > k){
                    int idx=s[i]-'A';
                    freq[idx]--;
                    for(int i=0;i<26;i++)
                        maxF=max(maxF,freq[i]);
                    i++;
                }
            }
        }   
        return ans;
    }
};