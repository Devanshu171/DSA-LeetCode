class WordFilter {
public:
    struct Node{
      Node *links[26];
        vector<int>indices;
        
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
            // flag=true;
        }
    };
    
    class Trie{
      private: Node *root;
      
      public:
        
        Trie(){
            root=new Node();
        }
        
        void insert(string s,int ind){
            Node* node=root;
            for(int i=0;i<s.size();i++){
            char ch=s[i];
                if(!node->containsKey(ch)){
                    node->put(ch,new Node());
                }
                node->indices.push_back(ind);
                node=node->get(ch);
            }
             node->indices.push_back(ind);
           
        }
        vector<int> search(string prefix, string suffix){
            Node *node=root;
            for(int i=0;i<prefix.size();i++){
                if(!node->containsKey(prefix[i])) return {};
                node=node->get(prefix[i]);
            }
          return node->indices; 
        }
        
    };
    Trie t;
    vector<string>ws;
    WordFilter(vector<string>& words) {
     for(int i=0;i<words.size();i++){
         t.insert(words[i],i);
     }   
        ws=words;
    }
    
    int f(string prefix, string suffix) {
        
        vector<int>indi=t.search(prefix,suffix);
        
        for(int i=indi.size()-1;i>=0;i--){
            int j=suffix.size()-1,k=ws[indi[i]].size()-1;
            while(j>=0 && k>=0 && suffix[j]==ws[indi[i]][k]){
                k--;j--;
            }
            if(j==-1) return indi[i];
            
        }
        return -1;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */