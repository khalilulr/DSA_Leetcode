class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n=hand.size();
        if(n%groupSize!=0)
            return false;
            
        map<int,int>mp;
        for(auto num:hand)
           mp[num]++;
        
        while(!mp.empty()){
            int sNum=mp.begin()->first;

            for(int i=0;i<groupSize;i++){
                if(mp.find(sNum+i)==mp.end())
                    return false;
                mp[sNum+i]--;
                if(mp[sNum+i]==0)
                    mp.erase(sNum+i);
            }
        }
        return true;


    }
};