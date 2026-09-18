class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l=0;
        int n=nums.size();
        int ans=1e9;
        int curSum=0;

        for(int r=0;r<n;r++){
            curSum+=nums[r];
            while(l<n && curSum>=target){
                ans=min(ans,r-l+1);
                curSum-=nums[l];
                l++;
            }
        }

        return ans==1e9?0:ans;
    }
};