class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int mini=*min_element(bloomDay.begin(),bloomDay.end());
        int maxi=*max_element(bloomDay.begin(),bloomDay.end());

        int n=bloomDay.size();
        int l=mini,h=maxi;

        int ans=-1;

        while(l<=h){
            int mid=l + (h-l)/2;

            int bouqCnt=0;
            int curAdj=0;
            int x=1;
             
            for(int i=0;i<n;i++){
                if(bloomDay[i]<=mid){
                    curAdj++;
                    if(curAdj>=x*k){
                        bouqCnt++;
                        x++;
                    }
                }else {
                    curAdj=0;
                    x=1;
                }
            }
            cout<<"mid: "<<mid<<" bouqCnt: "<<bouqCnt<<endl;
            if(bouqCnt>=m){
                ans=mid;
                h=mid-1;
            }

            if(bouqCnt <m){
                l=mid+1;
            }else h=mid-1;



        }
            return ans;

    }
};