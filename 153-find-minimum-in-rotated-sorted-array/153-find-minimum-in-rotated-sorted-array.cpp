class Solution {
public:
    int findMin(vector<int>& arr) {
        int n=arr.size();
        if(n<=1)
            return arr[0];
        
        int s=0,e=n-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            int right=arr[(mid+1)%n];
            int left=arr[(mid-1+n)%n];
            if(arr[mid]>=right)
                return right;
          else if(arr[mid]<=left)
                return arr[mid];
            
            else if(arr[mid]>=arr[s]) 
                s=mid+1;
            else if(arr[mid]<=arr[e])
                e=mid-1;
        }
        return -1;
        
    }
};