class MyCalendar {
public:
    map<int,int>mpp;
    MyCalendar() {
        // start.resize(1000+1);
        // end.resize(1000+1);
    }
    
    bool book(int start, int end) {
     mpp[start]++;
        mpp[end]--;
        int sum=0;
        bool flag=true;
        for(auto it:mpp){
            sum+=it.second;
            if(sum>1) {
                flag=false;
                break;
            }
        }
        if(!flag){
            mpp[start]--;
            mpp[end]++;
        }
        return flag;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */