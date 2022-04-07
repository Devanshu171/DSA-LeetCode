class Solution {
public:
    int compress(vector<char>& chars) {
        string ans="";
        int n=chars.size();
        for(int i=0;i<n;i++){
            int count=1;
            while(i<n-1 && chars[i]==chars[i+1]){
                i++;
                count++;
            }
            
            ans.push_back(chars[i]);
            if(count>1)
                ans+=to_string(count);
        
        }
        for(int i=0;i<ans.size();i++)
            chars[i]=ans[i];
        cout<<ans<<endl;
        return ans.size();
    }
};