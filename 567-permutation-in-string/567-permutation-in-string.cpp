class Solution {
public:
    bool comp(vector<int>a,vector<int>b){
        for(int i=0;i<26;i++)
            if(a[i]!=b[i])
                return false;
        
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        int n=s2.size();
        int m=s1.size();
        if(m>n) return false;
        vector<int>count1(26,0),count2(26,0);
        for(int i=0;i<m;i++){
            count1[s1[i]-'a']++;
        }
 // cout<<n<<m<<endl;
        int i=0,j=0;
     
       while(j<n){
           count2[s2[j]-'a']++;
           if(j-i+1==m){
               if(comp(count1,count2))
                   return true;
           }
            if(j-i+1<m) j++;
           else{
               count2[s2[i]-'a']--;
               j++;
               i++;
           }
       }
        return false;
    }
};
