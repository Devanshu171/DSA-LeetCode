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

// stack<int>st;
stack<int>ss;
void push(stack<int>& st, int a){
	// Your code goes here
	st.push(a);
	if(ss.empty() || ss.top()>a) ss.push(a);
	
}

bool isFull(stack<int>& st,int n){
	// Your code goes here
	return st.size()==n;
	
}

bool isEmpty(stack<int>& st){
	// Your code goes here
	return st.empty();
}

int pop(stack<int>& st){
	// Your code goes here
	if(st.empty()) return -1;
	if(!ss.empty()&&ss.top()==st.top()) {
	    ss.pop();
	    
	}
int x=st.top();
st.pop();
return x;
}

int getMin(stack<int>& s){
	// Your code goes here
	
	return ss.top();
}