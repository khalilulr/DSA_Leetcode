class Solution {
public:
    int maxProduct(vector<int>& nums) {
        long long pref=1,suff=1;
        int n=nums.size();
        long long ans=INT_MIN;
        for(int i=0;i<n;i++){
            pref*=nums[i];
            suff*=nums[n-1-i];
            ans=max({ans,pref,suff});
            if(pref==0)
                pref=1;
            if(suff==0)
                suff=1;
        }
        return (int)ans;
    }
};