class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
     //subarray 
     //-ve number
     //take , 0 
     //1 2 3
     //1 3 6  
     unordered_map<int,int>mp;
     int sum=0,cnt=0;
     mp[0]=1;
     for(auto num:nums){
         sum+=num;
        int req=sum-k;
        if(mp.count(req))
            cnt+=mp[req];
        mp[sum]++;
     }
     return cnt;
    }
};