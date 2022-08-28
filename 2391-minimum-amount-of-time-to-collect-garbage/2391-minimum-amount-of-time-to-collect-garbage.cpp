class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int n=garbage.size();
        vector<int>pret(n,0);
        for(int i=1;i<n;i++){
            pret[i]=travel[i-1]+pret[i-1];
        }
            int countG=0,countM=0,countP=0;
            int lastG=-1,lastM=-1,lastP=-1;
        
        for(int i=0;i<n;i++){
            for(auto ch:garbage[i]){
                if(ch=='G'){
                    countG++;
                    lastG=i;
                }else if(ch=='P'){
                    countP++;
                    lastP=i;
                }else{
                    countM++;
                    lastM=i;
                }
            }   
        }
        int ans=0;
        if(countM!=0){
            ans+=countM;
            ans+=pret[lastM];
        }
         if(countP!=0){
            ans+=countP;
            ans+=pret[lastP];
        }
         if(countG!=0){
            ans+=countG;
            ans+=pret[lastG];
        }
        
        return ans;
    }
};