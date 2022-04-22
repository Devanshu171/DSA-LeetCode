class Solution {
public:
    bool rotateString(string s, string goal) {
        
        if(s.size()!=goal.size())
            return false;
        for(int i=0;i<s.size();i++){
            if(check(i,s,goal))
                return true;
        }
        return false;
    }
    bool check(int r,string s,string goal){
        for(int i=0;i<goal.size();i++){
            if(s[(i+r)%s.size()]!=goal[i])
                return false;
        }
        return true;
    }
};