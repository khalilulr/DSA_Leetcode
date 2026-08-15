class Solution {
public:
    bool check(vector<int>& nums) {
        //if arr sorted and rotated , only one violation of next el < cur;

        int cnt=0,n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]>nums[(i+1)%n])
                cnt++;
            if(cnt>1)
                return false;
        }

        return true;
    }
};