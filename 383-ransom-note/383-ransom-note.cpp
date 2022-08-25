class Solution {
public:
    bool canConstruct(string r, string m) {
        int count[26]={0};
        for(int i=0;i<m.size();i++){
            count[m[i]-'a']++;
        }
        for(int i=0;i<r.size();i++){
            if(count[r[i]-'a']<=0) return false;
                    count[r[i]-'a']--;
        }
        return true;
    }
};