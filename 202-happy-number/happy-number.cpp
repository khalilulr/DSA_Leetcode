class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int,bool>mp;
        while(n!=1){
            int curN=n;
            long long sum=0;
            while(curN){
                int rem=curN%10;
                sum+=(long long)rem*rem;
                curN=curN/10;
            }
            n=int(sum);
            if(mp[sum])
                return false;
            mp[sum]=true;
        }

        return n==1;

    }
};