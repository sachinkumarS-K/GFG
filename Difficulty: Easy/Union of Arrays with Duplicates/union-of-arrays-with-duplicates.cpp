class Solution {
  public:
    vector<int> findUnion(vector<int>& a, vector<int>& b) {
        // code here
        vector<int>ans;
        unordered_set<int>st;
        int i = 0 , j = 0 ;
        
        while(i < a.size() || j < b.size()){
            if(i < a.size() && st.find(a[i]) == st.end()){
                st.insert(a[i]);
                ans.push_back(a[i]);
            }
            if(j < b.size() && st.find(b[j]) == st.end()){
                st.insert(b[j]);
                ans.push_back(b[j]);
            }
            i++;
            j++;
        }
        
        return ans;
    }
};