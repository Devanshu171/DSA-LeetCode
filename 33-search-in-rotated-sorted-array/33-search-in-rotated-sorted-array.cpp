class Solution {
public:
    int pivot(vector<int>&arr,int n){
        
        int start=0,end=n-1;
        
        if(arr[0]<=arr[n-1]) return 0;
    
        while(start<=end){
            
            int mid=start+(end-start)/2;
            int next=arr[(mid+1)%n],prev=arr[(mid-1+n)%n];
            
            if(arr[mid]<=next && arr[mid]<=prev)
                return mid;
             else if(arr[mid] <= arr[end])  
                end=mid-1;
            else if(arr[mid] >=arr[start]) 
                start=mid+1;
           
        }
        return -1;
                      
    }
    
    int bs(vector<int>&arr,int start,int end,int x){
        int n=arr.size();
        while(start<=end){
            
            int mid=start+(end-start)/2;
            if(arr[mid]==x) return mid;
            else if(arr[mid]>x) end=mid-1;
            else start=mid+1;
            
        }
        return -1;
    }
    int search(vector<int>& arr, int x) {
        int n=arr.size();
        int pvt=pivot(arr,n);
         cout<<pvt;
        int ans=bs(arr,0,pvt-1,x) ;
       
        if(ans!=-1)return ans;
            else return  bs(arr,pvt,n-1,x); ;
        
        
    }
};