class Solution {
public:
    bool reorderedPowerOf2(int n) {
//         int count[10]={0};
        
//         int m=n;
//         while(n){
//             count[n%10]++;
//             n/=10;
//         }
//         // cout<<pow(2,20)<<endl;
//         bool flag=true;
//         for(int i=0;i<31;i++){
//             int k=pow(2,i);
//             // cout<<k<<endl;
//            vector<int>count2(10,0);
//             while(k){
//                 count2[k%10]++;
//                 k/=10;
//             }
//             for(int i=0;i<10;i++){
//                 // cout<<i<<" "<<count[i]<<" - "<<count2[i]<<endl;
//                 if(count[i]!=count2[i]){
//                     flag=false;
//                     break;
//                 }
//             }
//             if(flag) return true;
//             flag=true;
//         }
//         return false;
        string sortedNum=getSor(n);
        
        for(int i=0;i<32;i++){
            if(sortedNum==getSor(1<<i)) return true;
        }
        return false;
    }
    
    string getSor(int n){
        string ans=to_string(n);
        sort(ans.begin(),ans.end());
        return ans;
    }
};