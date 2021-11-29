
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        DSU dsu(1000);
        for(auto it:edges){
           if(dsu.UN(it[0],it[1])==false) 
               return it;
        }
        
        return {};
        
    }    
class DSU
{
private:
  vector<int> parent, size;

public:
  DSU(int n)
  {
    for (int i = 0; i <=n; i++)
    { parent.push_back(i);
      size.push_back(1); }
      
  }

  int findParent(int u)
  {
    if (parent[u] == u)
      return u;
    else
      return parent[u] = findParent(parent[u]);
  }

    
  bool UN(int u, int v)
  {
     
    u = findParent(u);
    v = findParent(v);

    if (u == v)  return false;
      
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
    }
      return true;
  }
    
};
};