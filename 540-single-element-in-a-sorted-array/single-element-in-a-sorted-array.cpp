class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        // all the elem dublicate except one
        //(0,1) (1,2) ... (n-2,n-1);
        // 0......x......n-1
        //at x idx, x-1 idx value are same
        //ideal case
        //x->odd idx and x-1 is obv even idx
        //x->even idx and x-1 is obv odd idx

        //if x idx is even && x+1 is the next same value as of x idx  || x idx is odd and x-1 is 



        int n=nums.size();
          if(n==1)
            return nums[0];

        if(n>1){
            if(nums[0]!=nums[1])
                return nums[0];

            if(nums[n-2]!=nums[n-1])
                return nums[n-1];
        }
        int l=0,h=n-1,ans=-1;

        while(l<=h){
            int mid=l + (h-l)/2;
            if(nums[mid-1]!=nums[mid] && nums[mid]!=nums[mid+1])
                return nums[mid];
            if((mid%2==1 && nums[mid+1]==nums[mid]) || (mid%2==0 && nums[mid-1]==nums[mid]))
                h=mid-1;
            else l=mid+1;
        }
            return -1;
    }
};