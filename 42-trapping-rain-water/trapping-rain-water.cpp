class Solution {
public:
    int trap(vector<int>& height) {
        //min(max_left , max_right)-curHt 
        int n=height.size();
        vector<int>preMax(n,0);
        vector<int>sufMax(n,0);
        int curMax=0;
        int curMaxS=0;
        for(int i=0;i<n;i++){
            curMax=max(curMax,height[i]);
            curMaxS=max(curMaxS,height[n-1-i]);
            preMax[i]=curMax;
            sufMax[n-1-i]=curMaxS;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            int leftM=preMax[i];
            int rightM=sufMax[i];
            int ht=min(leftM,rightM);
            int waterH=height[i]>=ht?0:ht-height[i];
            ans+=waterH;
        }
        return ans;

    }
};