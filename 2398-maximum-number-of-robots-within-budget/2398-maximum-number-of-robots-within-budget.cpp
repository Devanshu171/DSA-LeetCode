class Solution {
public:
    
    bool isValid(vector<int>& ct,vector<int>& rc, long long budget,long long k){
        deque<int>q;
        if(k==0) return true;
        long long i=0,j=0,n=ct.size();
        long long curSum=0;
        while(j<n){
            curSum+=rc[j];
            
            while(!q.empty() && ct[q.back()]<ct[j]){
                q.pop_back();
            }
            q.push_back(j);
            if(j-i+1==k){
                if(ct[q.front()]+k*1l*curSum<=budget){
                    return true;
                }

                if(ct[q.front()]==ct[i]){
                    q.pop_front();
                }
                   curSum-=rc[i++];
            }
            j++;
        }
        return false;
    }
    int maximumRobots(vector<int>& ct, vector<int>& rc, long long budget) {
        
        
        int n=ct.size();
        
        int s=1,e=n,ans=0;
        vector<long long>pre(n,0);
        pre[0]=rc[0];
        for(int i=1;i<n;i++){
            pre[i]=pre[i-1]+rc[i];
        }
        while(s<=e){
            int mid=s+(e-s)/2;
            cout<<mid<<endl;
            if(isValid(ct,rc,budget,mid)){
                ans=mid;
                s=mid+1;
            }else{
                e=mid-1;
            }
        }
        return ans;
        
    }
};