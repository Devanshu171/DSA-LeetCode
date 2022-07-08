class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        vector<int>vec;
        while(x){
            vec.push_back(x%10);
            x/=10;
        }
        for(int i=0;i<vec.size();i++){
            if(vec[i]!=vec[vec.size()-i-1]) return false;
        }
        return true;
    }
};