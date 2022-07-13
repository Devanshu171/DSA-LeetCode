class Solution {
public:
    bool solveRec(int ind,vector<int>&arr,vector<int>&sides){
        if(ind==-1 && sides[0]==0 && sides[1]==0 && sides[2]==0 && sides[3]==0) return true;
                   
        if(ind==-1) return false;
        
        for(int i=0;i<4;i++){
             if(sides[i]-arr[ind]>=0){
                sides[i]-=arr[ind];
                if(solveRec(ind-1,arr,sides)) return true;
                sides[i]+=arr[ind];
            }
        }
        
    
        return false;
    }

    bool makesquare(vector<int>& arr) {
        int n=arr.size();
        int sum=0;
        for(auto it:arr) sum+=it;
        if(sum%4!=0) return false;
        cout<<sum<<endl;
        sort(arr.begin(),arr.end());
        vector<int>sides(4,sum/4);
        return solveRec(n-1,arr,sides);
    }
};