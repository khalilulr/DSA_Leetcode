class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0,n=nums.size();

        for(int i=0;i<n;i++)
            sum+=nums[i];
        
        int target;
        if(sum%2==0)
            target=sum/2;
        else return false;

        // vector<vector<bool>>dp(n,vector<bool>(target+1,false));
        vector<bool>prev(target+1,false);
        vector<bool>cur(target+1,false);

            prev[0]=true;

        if(nums[0]<=target)
            prev[nums[0]]=true;

        for(int i=1;i<n;i++){
            cur[0]=true;
            for(int j=1;j<=target;j++){
                bool notTake=prev[j];
                bool take=false;


                if(j-nums[i]>=0)
                    take=prev[j-nums[i]];

                cur[j]=take | notTake;
            }
            prev=cur;
        }
        
        return cur[target];
    }
};