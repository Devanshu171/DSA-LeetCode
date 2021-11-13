/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>>ans;
        if(root==NULL)
            return ans;
        
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            vector<int>vec;
            while(n--){
                Node*t=q.front();
                q.pop();
                vec.push_back(t->val);
                
                 for (Node* child : t->children) {
                    q.push(child);
                }
                
            }
            ans.push_back(vec);
        }
        return ans;
    }
};