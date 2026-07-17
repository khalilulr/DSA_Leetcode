class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0,mini=prices[0];
        for(auto price:prices){
            int todayP=price-mini;
            ans=max(ans,todayP);
            mini=min(mini,price);
        }
        return ans;
    }
};