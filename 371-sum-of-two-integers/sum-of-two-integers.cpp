class Solution {
public:
    int getSum(int a, int b) {
        while(b){
            int carry = (a&b)<<1;
            a=a^b;
            // a=ans;
            b=carry;
        }

        return a;
    }
};