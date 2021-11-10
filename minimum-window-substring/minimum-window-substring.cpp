class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>mpp;
        for(auto it:t)
            mpp[it]++;
        int i=0,j=0,count=mpp.size(),minlen=INT_MAX,start;
        while(j<s.size()){
            if(mpp.find(s[j])!=mpp.end()){
                mpp[s[j]]--;
                if(mpp[s[j]]==0)
                    count--;
            }
            if(count>0)
                j++;
            else if(count==0){
                while(count==0){
                if(minlen>j-i+1){
                    start=i;
                    minlen=j-i+1;
                }
                if(mpp.find(s[i])!=mpp.end()){
                        mpp[s[i]]++;
                    if(mpp[s[i]]==1)
                        count++;  
                }
                i++;
                }
                j++;
            }
            
        }
        return minlen!=INT_MAX? s.substr(start,minlen):"";
    }
};