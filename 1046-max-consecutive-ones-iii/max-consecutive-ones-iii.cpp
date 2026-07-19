class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int cntOne=0;
        int n=nums.size();
        int left=0;
        int maxV=0;
        for(int right=0;right<n;right++){
            if(nums[right]==1)
                cntOne++;
            while(left<=right && right-left+1 - cntOne > k){
                if(nums[left]==1)
                    cntOne--;
                    left++;
            }
            maxV=max(maxV,right-left+1);
        }
        return maxV;
    }
};