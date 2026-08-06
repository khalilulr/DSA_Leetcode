class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        multiset<int>st;
        for(auto el:nums1)
            st.insert(el);
        for(auto el:nums2)
            st.insert(el);
        int n = st.size();

        if (n % 2 == 1) {

            int cnt = 0;

            for (int x : st) {
                if (cnt == n / 2)
                    return x;
                cnt++;
            }

        }
        else {

            int cnt = 0;
            int first = 0, second = 0;

            for (int x : st) {

                if (cnt == n / 2 - 1)
                    first = x;

                if (cnt == n / 2) {
                    second = x;
                    break;
                }

                cnt++;
            }

            return (first + second) / 2.0;
        }
        return 0.00;
    }
};