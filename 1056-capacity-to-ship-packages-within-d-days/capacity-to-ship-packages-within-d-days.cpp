class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
         int sum=0,maxi=0;
         for(auto wt:weights){
            sum+=wt;
            maxi=max(maxi,wt);
        }

        int l=maxi,h=sum;
        int ans=sum;

        while(l<=h){
             int mid=l + (h-l)/2;


             int reqD=1;
             int val=0;

             for(auto wt:weights){
                if(val + wt>mid){
                    reqD++;
                    val=0;
                }
                val+=wt;
             }
             if(reqD<=days){
                ans=mid;
                h=mid-1;
             }else l=mid+1;
        }   

        return ans;
    }
};