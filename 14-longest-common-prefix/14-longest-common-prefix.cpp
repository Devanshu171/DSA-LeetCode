class Solution {
public:
    string longestCommonPrefix(vector<string>& str) {
        string pre=str[0];
        int n=str.size();
        for(int i=1;i<n;i++){
            string x=str[i];
            int j=0;
            while(j<x.size() && j<pre.size() && pre[j]==x[j]) j++;
            if(j!=0){
                pre=x.substr(0,j);
            }else{
                return "";
            }
        }
        return pre;
        
    }
};