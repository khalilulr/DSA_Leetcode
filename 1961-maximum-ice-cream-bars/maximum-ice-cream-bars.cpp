class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        int sum=0;
        int size=0;
        for(auto num:costs){
            if(num+sum>coins)
                return size;
            sum+=num;
            size++;
        }
        return size;
    }
};