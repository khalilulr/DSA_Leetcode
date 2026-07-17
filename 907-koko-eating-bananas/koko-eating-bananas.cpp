class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        //1,2,3,4
        //1,2,2,3
        int maxi=*max_element(piles.begin(),piles.end());
        int l=1,hi=maxi;
        int ans=1e9;
        while(l<=hi){
            int mid=l + (hi-l)/2;
            long long curH=0;
            for(auto pile:piles){
                if(pile%mid==0){
                    curH+=pile/mid;
                }else{
                    curH+=pile/mid + 1;
                }
            }
            if(curH<=h){
                ans=min(mid,ans);
                hi=mid-1;
            }else l=mid+1;
        }
        return ans;
    }
};