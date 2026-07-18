class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int curE=nums[0],curC=0;
        for(auto num:nums){
            if(num==curE)
                curC++;
            else{
                curC--;
                if(curC==0){
                    curE=num;
                    curC=1;
                }
            }
        }
        // cout<<curE<<endl;
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==curE)
                cnt++;
        }
        return cnt>=(nums.size()/2)?curE:-1;
    }
};