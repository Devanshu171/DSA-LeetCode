class RandomizedSet {
    private:
    unordered_map<int,int>mpp;
    vector<int>arr;
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mpp.find(val)!=mpp.end()){
            return false;
        }
         mpp[val]=arr.size();
          arr.push_back(val);
           
          
        return true;
    }
    
    bool remove(int val) {
      
              if(mpp.find(val)==mpp.end())
            return false;
        
	       
            int last=arr.back(); 
             mpp[last]=mpp[val];
            arr[mpp[val]]=last; 
            mpp.erase(val);
         arr.pop_back();	
            return true;
        
        
    }
    
    int getRandom() {
        return arr[rand() % arr.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */