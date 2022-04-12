class Solution {
public:

    bool rotateString(string s, string goal) {
      if(s.size()!=goal.size()) return false;
        for(int i=0;i<s.size();i++){
            if(rotate(s,goal,i)){
                return true;
            }
        }
        return false;      
    }
    bool rotate(string s,string goal,int k){
        for(int i=0;i<s.size();i++){
            if(goal[i]!=s[(i+k)%s.size()])
                return false;
        }
        return true;
    }
};