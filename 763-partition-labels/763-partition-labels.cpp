class Solution {
public:
    vector<int> partitionLabels(string s) {
       vector<vector<int>>chars(26,vector<int>(2,-1));
        for(int i=0;i<s.size();i++){
            
                if(chars[s[i]-'a'][0]!=-1){
                    chars[s[i]-'a'][1]=i;
                }else{
                    chars[s[i]-'a'][0]=i;
                      chars[s[i]-'a'][1]=i;
                }
            
        }
        vector<int>vec(s.size(),0);
    vector<int>ans;
        for(auto it:chars){
            
            // cout<<it[0]<<endl;
            if(it[0]!=-1){
                vec[it[0]]++;
            vec[it[1]]--;
            }
            
        }
       int prev=0;
        for(int i=0;i<vec.size();i++){
            if(i!=0){
                vec[i]+=vec[i-1];
            }
            if(vec[i]==0){
                ans.push_back(i-prev+1);
                prev=i+1;
            }
        }
        return ans;
    }
};