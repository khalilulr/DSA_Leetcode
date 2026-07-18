class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        //1 2 5   //3 4 
        //1 2 3 4 5 6
        //1 2=a  5=b size= 2
        //3=c    4=d 
        int n=nums1.size(),m=nums2.size();
        if(n>m)
           return findMedianSortedArrays(nums2,nums1);
        int size=(n + m +1 )/2;
        int l=0,h=n;
        while(l<=h){
            int mid1=l + (h-l)/2;
            int mid2=size-mid1;
            int a,b,c,d;
            
            a=mid1==0?INT_MIN:nums1[mid1-1];
            b=mid1==n?INT_MAX:nums1[mid1];
            c=mid2==0?INT_MIN:nums2[mid2-1];
            d=mid2==m?INT_MAX:nums2[mid2];

            if(a<=d && b>=c){
                if((n+m)%2==0){
                    return double((max(a,c)+min(b,d))/2.0);
                }
                return max(a,c)/1.0;
            }
            if(a>d)
                h=mid1-1;
            else l=mid1+1;

        }
        return 0.00;
    }
};