// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
	struct Node{
	    char data;
	    Node *next,*prev;
	    Node(char x){
	        data=x;
	        next=NULL;
	        prev=NULL;
	    }
	}*head=NULL,*tail=NULL;
	void insert(Node *k){
	    if(!head){
	        head=k;
	        tail=k;
	    }else{
	        k->prev=tail;
	        tail->next=k;
	        tail=k;
	    }
	}
	void removeNode(Node *temp){
	     if (head == NULL)
        return;

    if (head == temp)
        head = head->next;
    if (tail == temp)
        tail = tail->prev;
    if (temp->next != NULL)
        temp->next->prev = temp->prev;
    if (temp->prev != NULL)
        temp->prev->next = temp->next;

    delete (temp);
	}
		string FirstNonRepeating(string s){
		    // Code here
		    int count[26]={0};
		    unordered_map<char,Node*>mpp;
		    
		   
		    for(int i=0;i<s.size();i++){
		        char x=s[i];
		        count[x-'a']++;
		        if(count[x-'a']==1){
		            Node *temp=new Node(x);
		            insert(temp);
		            mpp[x]=temp;
		        }
		       else if(count[x-'a']>1 && mpp[x]!=NULL){
		            removeNode(mpp[x]);
		            mpp[x]=NULL;
		        }
		        
		        if(!head)
		        s[i]='#';
		        else
		        s[i]=head->data;
		    }
		    return s;
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends