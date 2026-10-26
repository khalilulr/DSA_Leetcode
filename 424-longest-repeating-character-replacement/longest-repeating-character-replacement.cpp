class Solution {
public:
   int characterReplacement(string s, int k) {
    int l = 0, ans = 0, maxFreq = 0;
    unordered_map<char, int> mp;

    for (int r = 0; r < s.size(); r++) {
        maxFreq = max(maxFreq, ++mp[s[r]]);

        while ((r - l + 1) - maxFreq > k) {
            mp[s[l]]--;
            l++;
        }

        ans = max(ans, r - l + 1);
    }

    return ans;
}
};