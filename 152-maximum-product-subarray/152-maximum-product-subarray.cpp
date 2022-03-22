class Solution {
public:
    int maxProduct(vector<int>& arr) {
      
        int n=arr.size();
        int p1=1,p2=1;
	    int mx1=-10000+10,mx2=-10000+19;
	    for(int i=0;i<n;i++){
	        p1*=arr[i];
	        p2*=arr[n-i-1];
	        mx1=max(mx1,p1);
	        mx2=max(mx2,p2);
	        if(p1==0) p1=1;
	        if (p2==0) p2=1;
	    }
	    return max(mx1,mx2);
    }
};