class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l=1,h=*max_element(nums.begin(),nums.end());
        int ans=-1;
        while(l<=h){
            int mid= l + (h-l)/2;

            int curVal=0;

            for(auto num:nums){
                if(num%mid==0){
                    curVal+=num/mid;
                }else{
                    curVal+= (num/mid)+1;
                }
            }

            if(curVal<=threshold){
                ans=mid;
                h=mid-1;
            }else l=mid+1;
        }

        return ans;
    }
};