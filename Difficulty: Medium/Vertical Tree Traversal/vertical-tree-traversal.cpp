/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    vector<vector<int>> verticalOrder(Node *root) {
        // code here
        unordered_map<int , vector<int>>mp;
        queue<pair<Node*,int>>que;
        que.push({root , 0});
        vector<vector<int>>ans;
        int minDist = INT_MAX , maxDist = INT_MIN;
        
        while(!que.empty()){
            pair<Node*,int>curr = que.front();
            que.pop();
            int hd = curr.second;
            minDist = min(minDist , hd);
            maxDist = max(maxDist , hd);
            
            mp[hd].push_back(curr.first->data);
            
            if(curr.first->left)
                que.push({curr.first->left , hd-1});
            if(curr.first->right)
                que.push({curr.first->right , hd+1});
            
        }
        for(int i = minDist ; i<= maxDist ; i++){
            ans.push_back(mp[i]);
        }
        return ans;
    }
};