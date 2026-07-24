class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        //1,1,2,3,3,4,4,8,8
        //(0 1) (3 4) (5 6) (7 8)
        //midIdx=4 idx(4== 3) (0..2) (5..8)
        //0 1 2    5 6 7 8

        //3 3 7 8 8

        int n=nums.size();
        if(n==1)
            return nums[0];

        if(n>1){
            if(nums[0]!=nums[1])
                return nums[0];

            if(nums[n-2]!=nums[n-1])
                return nums[n-1];
        }

        int l=0,h=n-1;

        while(l<=h){
            int mid=l + (h-l)/2;

            if(nums[mid-1]!=nums[mid]  && nums[mid]!=nums[mid+1])
                return nums[mid];

            if((mid%2!=0 && nums[mid]==nums[mid+1]) || (mid%2==0 && nums[mid-1]==nums[mid]))
                h=mid-1;
            else l=mid+1;
        }

        return -1;
    }
};