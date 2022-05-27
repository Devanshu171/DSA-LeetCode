/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        unordered_map<int,Node*>mpp;
        if(!node)
            return NULL;
        queue<Node*>q;
        vector<bool>vis(101,0);
        q.push(node);
        vis[1]=1;
        while(!q.empty()){
            int val=q.front()->val;
            auto list=q.front()->neighbors;
            q.pop();
            vector<Node*>vec;
            for(auto it:list){
                if(mpp.find(it->val)!=mpp.end()){
                    vec.push_back(mpp[it->val]);
                }else{
                    mpp[it->val]=new Node(it->val);
                    vec.push_back(mpp[it->val]);
                }
            }
            if(mpp.find(val)==mpp.end()){
            Node *temp=new Node(val,vec);
            mpp[val]=temp;
            }else{
                // for(int i=0;i<vec.size();i++){
                //     mpp[val]->neighbors.push_back(vec[i]);
                // }
                 mpp[val]->neighbors=vec;
            }
           
            for(auto it:list){
                if(!vis[it->val]){
                     vis[it->val]=1;
                    q.push(it);
                }
            }
            
            
            }
        return mpp[1];
    }
};