class Solution {
  public:
    vector<int> findUnion(vector<int>& a, vector<int>& b) {
        // code here
        vector<int>ans;
        sort(a.begin() , a.end());
        sort(b.begin() , b.end());
        
        int i = 0 , j = 0 ;
        
        while(i < a.size() && j < b.size()){
            if(a[i] < b[j]){
                ans.push_back(a[i]);
                i++;
            }
            else{
                ans.push_back(b[j]);
                j++;
            }
            while( i < a.size() && ans.back() == a[i])i++;
            while( j < b.size() && ans.back() == b[j])j++;
        }
        while(i < a.size()){
           ans.push_back(a[i++]);
            while(i<a.size() && ans.back() == a[i])i++;
        }
         while(j < b.size()){
            ans.push_back(b[j++]);
            while(j < b.size() && ans.back() == b[j]) j++;  
        }
        return ans;
    }
};