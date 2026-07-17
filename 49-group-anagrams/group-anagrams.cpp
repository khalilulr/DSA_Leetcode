class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>mp;
        for(auto str:strs){
            string word=str;
            sort(str.begin(),str.end());
            mp[str].push_back(word);
        
        }
        vector<vector<string>>ans;
        for(auto el:mp){
            vector<string>temp;
            for(auto e:el.second){
                temp.push_back(e);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};