class Solution {
public:
    vector<int> getlps(string s){
        vector<int>ans(s.size());
        ans[0]=0;
        int i=1,j=0;
        while(i<s.size()){
            if(s[i]==s[j]){
                ans[i]=j+1;
                i++;j++;
            }else{
                if(j!=0){
                    j=ans[j-1];
                }else{
                    ans[i]=0;
                    i++;
                }
            }
        }
        return ans;
        
    }
    bool rotateString(string s, string goal) {
      if(s.size()!=goal.size()) return false;
        s=s+s;
        vector<int>lps(goal.size());
        lps=getlps(s);
        int j=0,i=0;
        while(i<s.size() && j<goal.size()){
            if(s[i]==goal[j]){
                i++;j++;
            }else{
                if(j!=0)
                j=lps[j-1];
                else{
                    i++;
                }
            }
        }
        return j==goal.size();
        
    }
};