class Solution {
public:
    int mah(int a[],int n){
        stack<int>st;
        vector<int>left;
        vector<int>right(n);
        
        for(int i=0;i<n;i++){
            while(!st.empty() && a[st.top()]>=a[i]) st.pop();
            if(!st.empty()) left.push_back(st.top());
            else left.push_back(-1);
            st.push(i);
        }
        
        while(!st.empty()) st.pop();
        int k=n-1;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && a[st.top()]>=a[i]) st.pop();
            if(!st.empty()) right[k--]=st.top();
            else right[k--]=n;
            st.push(i);
        }
        int ans=-10000;
        
        for(int i=0;i<n;i++){
            int area=(right[i]-left[i]-1)*a[i];
            ans=max(area,ans);
        }
        return ans;
        
    }
    int maximalRectangle(vector<vector<char>>& mat) {
    
          if(mat.size()==NULL)
            return NULL;
        int n=mat.size(); int m=mat[0].size();
      
        int hight[m];
        for(int i=0;i<m;i++)
            hight[i]=0;
        int i=0; int ans=-10000;
        
        while(i<n){
            
            for(int j=0;j<m;j++){
                
                char y=mat[i][j];
                int x=y-'0';
                if(x!=0)
                    hight[j]+=x;
                else
                    hight[j]=0;
            }
            
            int area=mah(hight,m);
            ans=max(area,ans);
            i++;
        }
        return ans;
        
    }
};