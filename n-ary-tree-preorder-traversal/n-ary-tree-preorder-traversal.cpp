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
void helper(Node *root,vector<int>&vec){
    if(root==NULL)
        return;
    vec.push_back(root->val);
    for(auto it:root->children)
        helper(it,vec);
}
class Solution {
public:
    vector<int> preorder(Node* root) {
     vector<int>vec;
        helper(root,vec);
        return vec;
    }
};