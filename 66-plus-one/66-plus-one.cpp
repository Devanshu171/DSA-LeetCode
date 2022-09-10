class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int>ans;
        int c=1;
        for(int i=digits.size()-1;i>=0;i--){
            int val=c+digits[i];
            cout<<val<<endl;
            ans.push_back(val%10);
            c=val/10;
        }
        if(c>0) ans.push_back(c);
         reverse(begin(ans),end(ans));
        return ans;
    }
};