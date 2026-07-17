class Solution {
public:
    int maxArea(vector<int>& height) {
        //
        int i=0,n=height.size(),j=n-1;
        int maxi=0;
        while(i<=j){
            int area=(j-i) * min(height[i],height[j]);
            maxi=max(maxi,area);
            if(height[i]>height[j])
                j--;
            else i++;
        }
        return maxi;
    }
};