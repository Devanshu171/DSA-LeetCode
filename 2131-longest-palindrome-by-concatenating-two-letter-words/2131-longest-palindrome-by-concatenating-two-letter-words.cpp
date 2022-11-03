class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int>mpp;
        for(int i=0;i<words.size();i++){
          mpp[words[i]]++;
        }
        bool flag=false;
        int ans=0;
        for(int i=0;i<words.size();i++){
            if(mpp[words[i]]>0){
               
                string rev=words[i];
                reverse(rev.begin(),rev.end());
                if(rev==words[i]){
                    if(mpp[rev]>1){
                        if(mpp[rev]%2==0){
                             ans+=mpp[rev]*2;
                                 mpp[rev]=0;

                        }
                    
                        else{
                                ans+=(mpp[rev]-1)*2;
                            mpp[rev]=1;
                        }
                        
                    }else if(words[i]==rev && !flag){
                           ans+=2;
                     flag=true;
                    }
                }else{
                     ans+=min(mpp[words[i]],mpp[rev])*4;
                     mpp[words[i]]=0;
                     mpp[rev]=0;
                    
                }
            }
           
        }
        return ans;
    }
};