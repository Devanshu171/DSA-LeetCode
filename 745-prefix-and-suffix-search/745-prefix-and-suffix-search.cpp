class WordFilter {
public:
    
unordered_map<string,int>mpp;
  WordFilter(vector<string> &words)
{
    for(int i=0;i<words.size();i++){
        string p="";
        for(int j=0;j<words[i].size();j++){
                 p+=words[i][j];
                    
                string s="";
             for(int k=words[i].size()-1;k>=0;k--){
                 s=words[i][k]+s;
                 mpp[p+'.'+s]=i;
             }         
        }
    }
}
    int f(string prefix, string suffix) {
        if(mpp.find(prefix+'.'+suffix)==mpp.end()) return -1;
    return mpp[prefix+'.'+suffix];
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */