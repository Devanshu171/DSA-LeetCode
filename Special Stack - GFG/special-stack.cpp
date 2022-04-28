// { Driver Code Starts
#include<iostream>
#include<stack>
using namespace std;
void push(stack<int>& s,int a);
bool isFull(stack<int>& s,int n);
bool isEmpty(stack<int>& s);
int pop(stack<int>& s);
int getMin(stack<int>& s);
//This is the STL stack (http://quiz.geeksforgeeks.org/stack-container-adaptors-the-c-standard-template-library-stl/).
stack<int> s;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,a;
		cin>>n;
		while(!isEmpty(s)){
		    pop(s);
		}
		while(!isFull(s,n)){
			cin>>a;
			push(s,a);
		}
		cout<<getMin(s)<<endl;
	}
}// } Driver Code Ends


int mini=0;
void push(stack<int>& s, int a){
	// Your code goes here
        if(s.empty()){
            s.push(a);
        mini=a;
        }else if(mini<=a){
            s.push(a);
        }else{
            s.push(2*a-mini);
            mini=a;
        }
	
}

bool isFull(stack<int>& s,int n){
	// Your code goes here
	return s.size()==n;
}

bool isEmpty(stack<int>& s){
	// Your code goes here
	return s.empty();
}

int pop(stack<int>& s){
	// Your code goes here
	int a;
	if(s.top()>=mini){
	    a=s.top();
	    s.pop();
	}else{
	    a=mini;
	    mini=2*mini-s.top();
	    s.pop();
	}
	return a;
}

int getMin(stack<int>& s){
	// Your code goes here
	if(!s.empty())
	return mini;
	else{
	    return -1;
	}
}