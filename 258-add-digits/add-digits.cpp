class Solution {
public:
    int addDigits(int num) {
        int ans=0;
        while(num/10!=0){
            int curSum=0;
            while(num){
                curSum+=num%10;
                num=num/10;
            }
            num=curSum;
        }
        return num;
    }
};