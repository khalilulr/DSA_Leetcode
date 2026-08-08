class Solution {
public:
    int jump(vector<int>& nums) {
        //2 3 1 | 1| 4|
        int n=nums.size();
        int currentEnd=0;
        int farthest=0;
        int jump=0;

        
        for(int i=0;i<n-1;i++){
            farthest=max(farthest,i+nums[i]);

            if(i==currentEnd){
                jump++;
                currentEnd=farthest;
            }
        }

        return jump;
    }
};