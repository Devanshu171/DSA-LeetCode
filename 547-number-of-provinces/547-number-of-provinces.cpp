class DSU{
    private: vector<int>parent,size;
    int count=0;
    public: DSU(int n){
        count=n;
        for(int i=0;i<n;i++){
            parent.push_back(i);
            size.push_back(1);
        }
    }
    public: int findParent(int node){
        if(parent[node]==node) return node;
        return parent[node]=findParent(parent[node]);
    }
   public: void Union(int u,int v){
        int up=findParent(u);
        int vp=findParent(v);
        
        if(up==vp) return ;
        else if(size[up]>size[vp]){
            parent[vp]=up;
            size[up]+=size[vp];
        }else{
             parent[up]=vp;
            size[vp]+=size[up];
        }
        count--;
    }
   public: int ans(){
        return count;
    }
};
class Solution {
public:
    int findCircleNum(vector<vector<int>>& arr) {
        int count=0;
        int n=arr.size();
        DSU dsu(n);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                cout<<i<<" "<<j<<endl;
                cout<<arr[i][j]<<" "<<endl;
            if(arr[i][j]==1){
              dsu.Union(i,j);
               }
            }       
        }
        return dsu.ans();
        return 0;
    }
};
