class Solution {
public:
    string customSortString(string a, string s) {
        unordered_map<char,int>mpp;
        
        for(auto it:s)
            mpp[it]++;
        int k=0;
        
        for(int i=0;i<a.size();i++)
        {
            while(mpp[a[i]]-->0)  s[k++]=a[i];
        }
        
        for(auto i:mpp)
        {
            while(i.second-->0) s[k++]=i.first;
        }
        return s;
    }
};