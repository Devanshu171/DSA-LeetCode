class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int n=garbage.size();
        vector<int>pret(n-1,0);
        pret[0]=travel[0];
        for(int i=1;i<travel.size();i++){
            pret[i]=travel[i]+pret[i-1];
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
            if(lastM!=0)
            ans+=pret[lastM-1];
        }
         if(countP!=0){
            ans+=countP;
              if(lastP!=0)
            ans+=pret[lastP-1];
        }
         if(countG!=0){
            ans+=countG;
              if(lastG!=0)
            ans+=pret[lastG-1];
        }
        
        return ans;
    }
};