class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int>ans;
        int n=nums.size();
        int l=-1,r=0;
        
        while(r<n && nums[r]<0)
            r++;
        l=r-1;

        while(l>=0 && r<n){
            int sqL=nums[l]*nums[l];
            int sqR=nums[r]*nums[r];
            if(sqL<sqR){
                ans.push_back(sqL);
                l--;
            }else{
                ans.push_back(sqR);
                r++;
            }
        }

        while(l>=0){
            int sqL=nums[l]*nums[l];
            ans.push_back(sqL);
            l--;
        }

        while(r<n){
            int sqR=nums[r]*nums[r];
            ans.push_back(sqR);
            r++;
        }


        return ans;
    }
};