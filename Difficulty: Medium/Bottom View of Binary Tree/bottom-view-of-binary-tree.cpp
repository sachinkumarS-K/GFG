/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    vector<int> bottomView(Node *root) {
        // code here
        vector<int>ans;
        queue<pair<Node*,int>>que;
        que.push({root , 0});
        int minDist = INT_MAX , maxDist = INT_MIN;
        unordered_map<int , Node*>distMap;
        
        while(!que.empty()){
            pair<Node*,int>curr = que.front();
            que.pop();
            int hd = curr.second;
            minDist = min(minDist , hd);
            maxDist = max(maxDist , hd);
           
            distMap[hd] = curr.first;
            
            if(curr.first->left)
                que.push({curr.first->left , hd-1});
            if(curr.first->right)
                que.push({curr.first->right , hd+1});
        }
        for(int i = minDist ; i<= maxDist ; i++)
            ans.push_back(distMap[i]->data);
        
        return ans;
    }
};