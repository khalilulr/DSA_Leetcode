class Solution {
public:
    vector<bool>isPrime;
    void findPrime(int maxE){
        isPrime.resize(maxE+1,true);

        isPrime[0]=false;
        isPrime[1]=false;

        for(int i=2;i*i<=maxE;i++){
            if(isPrime[i]){
                for(int j=i*i;j<=maxE;j+=i){
                    isPrime[j]=false;
                }
            }
        }

    }
    int minJumps(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
            return 0;
        unordered_map<int,vector<int>>mp;
        int maxE=INT_MIN;

        for(int i=0;i<n;i++){
            mp[nums[i]].push_back(i);
            maxE=max(maxE,nums[i]);
        }

        findPrime(maxE);

        queue<int>q;
        vector<bool>vis(n,false);
        unordered_set<int>seenPrime;
        q.push(0);
        vis[0]=true;
        
        int steps=0;

        while(!q.empty()){
            int size=q.size();
            
            for(int i=0;i<size;i++){
                int idx=q.front();q.pop();

                if(idx==n-1)
                    return steps;
                
                if(idx-1>=0 && !vis[idx-1]){
                    q.push(idx-1);
                    vis[idx-1]=true;
                }
                if(idx+1<n && !vis[idx+1]){
                    q.push(idx+1);
                    vis[idx+1]=true;
                }

                if(!isPrime[nums[idx]] || seenPrime.find(nums[idx])!=seenPrime.end())
                    continue;

                for(int j=nums[idx];j<=maxE;j+=nums[idx]){
                    if(mp.find(j)==mp.end())
                        continue;
                    
                    for(auto el:mp[j]){
                        if(!vis[el]){
                            q.push(el);
                            vis[el]=true;
                        }
                    }
                }
                seenPrime.insert(nums[idx]);
            }
            steps++;
        }

        return steps;
    }
};