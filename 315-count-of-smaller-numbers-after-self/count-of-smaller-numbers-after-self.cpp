class Solution {
public:
    void merge(int l,int mid,int r,
           vector<pair<int,int>>& arr,
           vector<int>& cnt){

    vector<pair<int,int>> temp;

    int left=l;
    int right=mid+1;

    int rightCount=0;

    while(left<=mid && right<=r){

        if(arr[left].first<=arr[right].first){
           
            cnt[arr[left].second]+=rightCount;
            temp.push_back(arr[left++]);

        }else{
            rightCount++;
            temp.push_back(arr[right++]);
        }
    }

    while(left<=mid){

        cnt[arr[left].second]+=rightCount;
        temp.push_back(arr[left++]);
    }

    while(right<=r){

        temp.push_back(arr[right++]);
    }

    for(int i=l;i<=r;i++)
        arr[i]=temp[i-l];
}

    void mergeSort(int l,int r,vector<pair<int,int>>&arr,vector<int>&cnt){
        if(l>=r)
            return ;
        int mid=l + (r-l)/2 ;

        mergeSort(l,mid,arr,cnt);
        mergeSort(mid+1,r,arr,cnt);
        merge(l,mid,r,arr,cnt);

         
    }
    vector<int> countSmaller(vector<int>& nums) {
        vector<pair<int,int>>arr;
        int n=nums.size();

        for(int i=0;i<n;i++){
            arr.push_back({nums[i],i});
        }

        vector<int>cnt(n,0);
        mergeSort(0,n-1,arr,cnt);
        return cnt;
    }
};