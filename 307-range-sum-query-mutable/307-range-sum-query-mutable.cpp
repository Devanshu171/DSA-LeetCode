class NumArray {
public:
    struct Node{
      int sum,start,end;
        Node *left,*right;
    
        Node(int x,int y){
            sum=0;
            start=x;
            end=y;
            left=NULL;
            right=NULL;
        }
    };
    
    Node *root=NULL; 
    NumArray(vector<int>& nums) {
        root=makeTree(nums,0,nums.size()-1);
    }
    Node *makeTree(vector<int>&arr,int start,int end){
        if(start>end){
            return NULL;
        }else{
             Node *node=new Node(start,end);
            if(start==end){
            node->sum=arr[start];
              }else{
                 int mid=(start+end)/2;
                node->left=makeTree(arr,start,mid);
                 node->right=makeTree(arr,mid+1,end);
                node->sum=node->left->sum+node->right->sum;
            }
            return node;
        }
    }
    void updateTree(Node *node,int ind,int val){
        if(node->start==node->end){
            node->sum=val;
        }else{
            int mid=node->start+(node->end-node->start)/2;
            if(ind<=mid){
                updateTree(node->left,ind,val);
            }else{
                updateTree(node->right,ind,val);
            }
            
            node->sum=node->left->sum+node->right->sum;
        }
        
    }
    int sumRangeHelper(Node *node,int start,int end){
        if(node->start==start && node->end==end){
            return node->sum;
        }else{
            int mid=node->start+(node->end-node->start)/2;
            if(end<=mid){
                return sumRangeHelper(node->left,start,end);
            }else if(start>=mid+1){
                return sumRangeHelper(node->right,start,end);
            }else{
                return sumRangeHelper(node->left,start,mid)+sumRangeHelper(node->right,mid+1,end);
            }
        }
    }
    
    void update(int index, int val) {
        updateTree(root,index,val);
    }
    
    int sumRange(int left, int right) {
        return sumRangeHelper(root,left,right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */