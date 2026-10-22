class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int lIdx=n-1;
        for(int i=n-2;i>=0;i--){
            if(lIdx-i <= nums[i])
                lIdx=i;
        }

        return lIdx==0;

    }
};