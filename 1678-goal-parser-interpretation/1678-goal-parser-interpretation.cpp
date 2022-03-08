class Solution {
public:
    string interpret(string str) {
           string s;
        int n=str.size();
        int i=0;
        while(i<n){
            if(str[i]=='G'){
                 s+='G';
                i++;
            }
            else{
                if((str[i+1])==')'){
                   s+='o';
                    i+=2;
                }
                   else {
                       s+="al";
                          i+=4; 
                   }
                
             }
                  
            }
                    return s;
    }
};