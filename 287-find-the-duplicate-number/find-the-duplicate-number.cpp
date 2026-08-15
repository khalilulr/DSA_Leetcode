class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        //1^2^3^4^1^3^4^2^2
        //0-->1-->2-->4--->2
        //1,n = n(n+1)/2
        int s=0,f=0;
        int n=nums.size();

        while(f<n && nums[f]<n){
            s=nums[s];
            f=nums[nums[f]];
            if(s==f)
                break;
        }

        s=0;
        while(s != f){
            s=nums[s];
            f=nums[f];
        }

        return s;    
    }
};