/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<int> topView(Node *root) {
        // code here
        unordered_map<int,Node*>distMap;
        queue<pair<Node*,int>>que;
        que.push({root , 0});
        int minDist = INT_MAX , maxDist = INT_MIN;
        while(!que.empty()){
            pair<Node*,int>curr = que.front();
            que.pop();
            int hd = curr.second;
            minDist = min(minDist , hd);
            maxDist = max(maxDist , hd);
            if(!distMap.count(hd)){
                distMap[hd] = curr.first;
            }
            if(curr.first->left)
                que.push({curr.first->left , hd-1});
                
            if(curr.first->right)
                que.push({curr.first->right , hd+1});
        }
        vector<int>ans;
        for(int i= minDist ; i<= maxDist ; i++){
            ans.push_back(distMap[i]->data);
        }
        return ans;
    }
};


