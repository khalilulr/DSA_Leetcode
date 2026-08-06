class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // x y | z
        // p q | r

        //y<r && z>q
        //y>r==> 


        int n=nums1.size(),m=nums2.size();
        if(n>m)
           return findMedianSortedArrays(nums2,nums1);

        int totalMid= (n + m + 1) /2;
        int l=0,h=n;

        while(l<=h){
            int mid1=l + (h-l)/2;
            int mid2=totalMid-mid1;

            int y=mid1==0?INT_MIN:nums1[mid1-1];
            int z=mid1==n?INT_MAX:nums1[mid1];
            int q=mid2==0?INT_MIN:nums2[mid2-1];
            int r=mid2==m?INT_MAX:nums2[mid2];


            if(y<=r && z>=q){
                if((n+m)%2==0){
                    return double(max(y,q) + min(z,r)) /2.0;
                }else{
                    return max(y,q)/1.0;
                }
            }

            if(y>r)
                h=mid1-1;
            else l=mid1+1;
        }
        return 0.00;
    }
};