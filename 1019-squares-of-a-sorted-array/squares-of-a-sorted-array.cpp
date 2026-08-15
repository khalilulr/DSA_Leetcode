class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int r=0;
        int n=nums.size();
        vector<int>ans;
        
        while(r<n && nums[r]<0)
            r++;

        int l=r-1;

        while(l>=0 && r<n){
            int lSq=nums[l]*nums[l];
            int rSq=nums[r]*nums[r];

            if(lSq<=rSq){
                ans.push_back(lSq);
                l--;
            }else{
                ans.push_back(rSq);
                r++;
            }
        }

        while(l>=0){
            int lSq=nums[l]*nums[l];
            ans.push_back(lSq);
            l--;
        }

        while(r<n){
            int rSq=nums[r]*nums[r];
            ans.push_back(rSq);
            r++;
        }

        return ans;
        
    }
};