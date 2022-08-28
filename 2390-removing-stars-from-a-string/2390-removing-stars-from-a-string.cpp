class Solution {
public:
    string removeStars(string s) {
        
        int star=0;
        
       string ans="";
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]=='*') star++;
            else if(star==0){
                ans+=s[i];
            }else{
                star--;
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};