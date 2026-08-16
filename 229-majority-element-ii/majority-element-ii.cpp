class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int a=0,b=0,cnt1=0,cnt2=0,n=nums.size();

        for(int x:nums){
            if(x==a)
                cnt1++;
            else if(x==b)
                cnt2++;
            else if(cnt1==0){
                a=x;
                cnt1=1;
            }else if(cnt2==0){
                b=x;
                cnt2=1;
            }else {
                cnt1--;
                cnt2--;
            }
        }

         cnt1=0;
         cnt2=0;

        for(auto x:nums){
            if(x==a)
                cnt1++;
            else if(x==b)
                cnt2++;
        }

        vector<int>ans;

        if(cnt1>n/3)
            ans.push_back(a);
        if(cnt2>n/3)
            ans.push_back(b);

        return ans;
    }
};