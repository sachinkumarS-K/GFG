class Solution {
public:
    vector<int> findUnion(vector<int>& a, vector<int>& b) {
        int i = 0, j = 0;
        vector<int> ans;
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        while (i < a.size() && j < b.size()) {
            if (a[i] < b[j]) {
                if (ans.empty() || ans.back() != a[i])
                    ans.push_back(a[i]);
                i++;
            } 
            else if (a[i] > b[j]) {
                if (ans.empty() || ans.back() != b[j])
                    ans.push_back(b[j]);
                j++;
            } 
            else { 
                if (ans.empty() || ans.back() != a[i])
                    ans.push_back(a[i]);
                i++; j++;
            }
        }

        while (i < a.size()) {
            if (ans.empty() || ans.back() != a[i])
                ans.push_back(a[i]);
            i++;
        }

        while (j < b.size()) {
            if (ans.empty() || ans.back() != b[j])
                ans.push_back(b[j]);
            j++;
        }

        return ans;
    }
};
