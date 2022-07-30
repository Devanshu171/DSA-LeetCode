class Solution {
public:
    
    bool match(string & s1,unordered_map<char,int>&mpp2){
      unordered_map<char,int>mpp1;
        for(int i=0;i<s1.size();i++){
            mpp1[s1[i]]++;
        }
       
        
        for(auto it2:mpp2){
            
            if(mpp1.find(it2.first)==mpp1.end() || mpp1[it2.first]<it2.second){
                return false;
            }
        }
        return true;
    }
    vector<string> wordSubsets(vector<string>& words1, vector<string>& word2) {
        
        vector<string>ans;
        int n=words1.size();
        
                  unordered_map<char,int>mpp2;
        for(int i=0;i<word2.size();i++){
                unordered_map<char,int>mpp3;
            for(int j=0;j<word2[i].size();j++){
                mpp3[word2[i][j]]++;
            }
            for(auto it:mpp3){
                if(mpp2.find(it.first)==mpp2.end()){
                    mpp2[it.first]=it.second;
                }else{
                    mpp2[it.first]=max(mpp2[it.first],it.second);
                }
            }
        }
        
        for(int i=0;i<n;i++){
            if(match(words1[i],mpp2)){
                ans.push_back(words1[i]);
            }
        }
        
        return ans;
    }
};