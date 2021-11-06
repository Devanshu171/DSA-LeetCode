class StockSpanner {
public:
    stack<pair<int,int>>st;
    int ind=0;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int res=1;
    
        if(price==NULL)
            return NULL;
        while(!st.empty() && st.top().first<=price ) 
       {
            res+=st.top().second;
         st.pop();  
       }
        st.push(make_pair(price,res));
        return res;
        
        
        }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */