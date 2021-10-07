class Solution {
public:
    void reverseString(vector<char>& s) {
     
        return helper(s,0);
        
    }
    void helper(vector<char>&s,int i)
    {
        int n=s.size();
        if(i>=n/2)
            return;
        
        else{
            swap(s[i],s[n-i-1]);
            return helper(s,i+1);
        }
        
    }
};