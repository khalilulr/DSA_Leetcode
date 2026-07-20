class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n=arr.size();
        int l=0,r=n-k;
        //[x---y] here y is not present
        //[x+1....y+1] here x is not preset
        //X-x < Y+1-x 
        while(l<r){
            int mid= l + (r-l)/2;
            if(x-arr[mid] > arr[mid+k]-x)
                l=mid+1;
            else r=mid;
        }
        vector<int>ans;
        for(int i=l;i<l + k;i++)
            ans.push_back(arr[i]);

        return ans; 
    }
};