class MyCalendarThree {
public:
    map<int,int>mpp;
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        mpp[start]++;
        mpp[end]--;
        int k=0;
        int ans=-1;
        for(auto it:mpp){
            k+=it.second;
            ans=max(k,ans);
        }
        return ans;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */