class WordDictionary {
public:
    struct Node{
     Node *links[26];
        bool flag=false;
        
        bool containsKey(char ch){
            return (links[ch-'a']!=NULL);
        }
        Node *get(char ch){
            return links[ch-'a'];
        }
        void put(char ch,Node *node){
            links[ch-'a']=node;
        }
        void setEnd(){
            flag=true;
        }
    };
    
    class Trie{
      
        private:  Node *root;
        
        public:
      
        Trie(){
            root=new Node();
        }

        void insert(string s){
            Node *node=root;
            
            for(int i=0;i<s.size();i++){
                char ch=s[i];
                if(!node->containsKey(ch)){
                    node->put(ch,new Node());
                }
                node=node->get(ch);
            }
            node->setEnd();
        }
     
     
        bool searchAll(string &s,Node *node,int i){

           for(;i<s.size();i++){
               char ch=s[i];
              if(ch=='.'){
                  for(int j='a';j<='z';j++){
                      if(node->containsKey(j)){
                          if(searchAll(s,node->get(j),i+1))
                              return true;
                      }
                  }
                  return false;
                  
              }else{
                  
               if(node->containsKey(ch)){
                   node=node->get(ch);
               }else{
                   return false;
               }
                  
             }
          }
            
                       if(i==s.size()) return node->flag;
                     else    return false;
            
    }
        bool search(string &word){
            Node *node=root;
            return searchAll(word,root,0);
        }
    };
    Trie t;
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        t.insert(word);
    }
    
    bool search(string word) {
        // Node *node=getRoot();
        return t.search(word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */