class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        //  . . a  b . .
        //  . . c  d 
        int n=nums1.size(),m=nums2.size();
        if(n>m)
            return findMedianSortedArrays(nums2,nums1);

        int size = n + m ;
        int midSize = (size+1) / 2;

        int l=0,h=n;

        while(l<=h){
            int mid1=l + (h-l) / 2 ;
            int mid2=midSize - mid1;

            int a=mid1!=0?nums1[mid1-1]:INT_MIN;
            int b=mid1!=n?nums1[mid1]:INT_MAX;

            int c=mid2!=0?nums2[mid2-1]:INT_MIN;
            int d=mid2<m?nums2[mid2]:INT_MAX;

            if(a<=d && b>=c){
                return size%2==0?(max(a,c)+ min(b,d)) / 2.0 : max(a,c) ;
            }

            if(a>d){
                h=mid1-1;
            }else l=mid1+1;
        }

        return 0.00;

    }
};