class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        //3 0 0 0 0 3 5 6
        //
        int l=0,n=nums.size();
        // int n=
        for(int r=0;r<n;r++){
            if(nums[r]!=0){
                swap(nums[l],nums[r]);
                l++;
            }
        }

       
    }
};