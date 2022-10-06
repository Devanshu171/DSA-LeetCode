class TimeMap {
public:
    map<int,map<string,string>>mpp;
    map<string,set<int>>keyt;
    TimeMap() {

    }
    
    void set(string key, string value, int timestamp) {
        keyt[key].insert(timestamp);
        mpp[timestamp][key]=value;

    }
    
    
    string get(string key, int timestamp) {
        string ans="";
       if(keyt.find(key)!=keyt.end()){
           auto it=keyt[key].upper_bound(timestamp);
           if(it==keyt[key].begin()) return "";
           else{
               
               return mpp[*(--it)][key];
           }
       }else{
          return ""; 
       }
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */