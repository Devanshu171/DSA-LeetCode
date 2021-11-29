class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        if(m==0&& n==0)
            return 0;
        
        
        DSU dsu(n*m);
        
   
        for(int i=0;i<n;i++){
            
            for(int j=0;j<m;j++){
                
                int ind=i*m+j;
                if(grid[i][j]=='0')
                    dsu.dec();
                else if(grid[i][j]=='1'){
                    if(i-1>=0 && grid[i-1][j]=='1') dsu.UN(ind,(i-1)*m+j);
                    if(j-1>=0 && grid[i][j-1]=='1') dsu.UN(ind,i*m+(j-1));
                }
               
            }
        }
        return dsu.numland();
    }
    class DSU
{
private:
  vector<int> parent, size;
    int count;
public:
  DSU(int n)
  {
      count=n;
    for (int i = 0; i < n; i++)
    {
      parent.push_back(i);
      size.push_back(1);
    }
  }

  int findParent(int u)
  {
    if (parent[u] == u)
      return u;
    else
      return parent[u] = findParent(parent[u]);
  }

  void UN(int u, int v)
  {
    u = findParent(u);
    v = findParent(v);

    if (u == v)
      return;

    else
    {
      if (size[u] > size[v])
      {
        parent[v] = u;
        size[u] += size[v];
      }
      else
      {
        parent[u] = v;
        size[v] += size[u];
      }
        count--;
    }
  }
        void dec(){
            count--;
        }
        int numland(){
           
            return count;
        }
};
};