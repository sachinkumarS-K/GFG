class Solution {
  public:
    // Function to check if b is a subset of a
    bool isSubset(vector<int> &a, vector<int> &b) {
        // Your code here
        int count = 0;
        unordered_map<int,int>mp;
        for(int i : b)
            mp[i]++;
        for(int i : a){
            if(mp.find(i) != mp.end()){
                mp[i]--;
                if(mp[i] == 0)
                    mp.erase(i);
            }
        }
        return mp.size() == 0;
    }
};