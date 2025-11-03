// User function Template for C++

class Solution {
  public:
    int toyCount(int N, int k, vector<int> arr) {
        // code here
        sort(arr.begin() , arr.end());
        int count = 0;
        for(int i : arr){
            if(i > k)
                break;
            count++;
            k -= i;
        }
        return count;
    }
};