class Solution {
public:
    bool canJump(vector<int>& nums) {
       //4
       //canR=3
       // canR-curIdx<=nums[curIdx] ==> canR=curIdx
       int n=nums.size();
       int canR=n-1;

       for(int i=n-2;i>=0;i--){
            int curIdx=i;
            int jumpNeeded=canR-curIdx;
            if(jumpNeeded <= nums[curIdx])
                canR=curIdx;
       }
       return canR==0;
    }
};