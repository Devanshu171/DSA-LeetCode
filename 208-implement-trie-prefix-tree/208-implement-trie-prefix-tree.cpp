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

class Trie {
    
    private:Node *root;
    
public:
    
    Trie() {
        
        root=new Node();
        
    }
    
    void insert(string word) {
        Node *node=root;
        for(int i=0;i<word.size();i++){
            if(!node->containsKey(word[i])){
                
                node->put(word[i],new Node());
            }
            node=node->get(word[i]);
            
            }
        node->setEnd();
        
    }
    
    bool search(string word) {
        Node *node=root;
        
        for(int i=0;i<word.size();i++){
            if(node->containsKey(word[i])){
                node=node->get(word[i]);
            }else{
                return false;
            }
        }
        if(node->flag) return true;
        else return false;
    }
    
    bool startsWith(string prefix) {
        Node *node=root;
        for(int i=0;i<prefix.size();i++){
            if(node->containsKey(prefix[i])){
                node=node->get(prefix[i]);
            }else{
                return false;
            }
        }
       if(node) return true;
        else return false;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */