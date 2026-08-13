class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int hr) {
        //m
        int n=piles.size(),maxi=*max_element(piles.begin(),piles.end());
        int l=1,h=maxi;
        int ans;

        while(l<=h){
            int mid=l + (h-l)/2;

            long long curH=0;
            for(int i=0;i<n;i++){

                curH+=piles[i]/mid;
                if(curH>hr)
                    break;
                if(piles[i]%mid!=0){
                    curH+=1;
                }

            }

            if((int)curH<=hr){
                ans=mid;
                h=mid-1;
            }else l=mid+1;
        }

        return ans;
    }
};