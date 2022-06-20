class Solution {
public:
    
    struct Node{
      Node *links[26];
        bool flag=false;
        
        bool containsKey(char ch){
            return (links[ch-'a']!=NULL);
        }
        
        void put(char ch,Node *node){
            links[ch-'a']=node;
        }
        
        Node *get(char ch){
            return links[ch-'a'];
        }
        void setEnd(){
            flag=true;
        }
    };
    
    class Trie{
      private: Node *root;
      
      public:
        
        Trie(){
            root=new Node();
        }
        
        void insert(string s){
            Node* node=root;
            for(int i=0;i<s.size();i++){
            char ch=s[i];
                if(!node->containsKey(ch)){
                    node->put(ch,new Node());
                }
                node=node->get(ch);
            }
            node->setEnd();
        }
        void dfs(Node *node,string s,vector<string>&temp){
            if(temp.size()==3) return;
            if(!node) return;
            
            if(node->flag) temp.push_back(s);
            for(char i='a';i<='z';i++){
                if(node->containsKey(i)){
                    dfs(node->get(i),s+i,temp);
                }
            }
        }
        vector<string> getWords(string s){
            Node *node=root;
            for(int i=0;i<s.size();i++){
                if(node->containsKey(s[i]))
                node=node->get(s[i]);
                else return {};
            }
            vector<string>temp;
            dfs(node,s,temp);
            return temp;
        }
    };
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        int n=products.size();
                        Trie t;
                for(int i=0;i<n;i++){
                        t.insert(products[i]);
                }
        vector<vector<string>>ans;
        for(int i=0;i<searchWord.size();i++){
            ans.push_back(t.getWords(searchWord.substr(0,i+1)));
        }
        return ans;
        
    }
};