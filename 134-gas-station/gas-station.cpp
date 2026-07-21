class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        //a---3--b--4--c--5--d--1--e--2--f
        //gas(i) < cost(i)
        //remGas=cost(i)-gas(i)>=0
        int totalG=0,totalD=0,remG=0,sIdx=0;
        int n=cost.size();
        for(int i=0;i<n;i++){
            totalG+=gas[i];
            totalD+=cost[i];

            remG+=gas[i]-cost[i];
            if(remG<0){
                sIdx=i+1>=n?-1:i+1;
                remG=0;
            }
        }
        return totalG>=totalD?sIdx:-1;
    }
};