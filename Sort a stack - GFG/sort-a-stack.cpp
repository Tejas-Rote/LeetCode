//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

class SortedStack{
public:
	stack<int> s;
	void sort();
};

void printStack(stack<int> s)
{
    while (!s.empty())
    {
        printf("%d ", s.top());
       	s.pop();
    }
    printf("\n");
}

int main()
{
int t;
cin>>t;
while(t--)
{
	SortedStack *ss = new SortedStack();
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
	int k;
	cin>>k;
	ss->s.push(k);
	}
	ss->sort();
	printStack(ss->s);
}
}
// } Driver Code Ends


/*The structure of the class is
class SortedStack{
public:
	stack<int> s;
	void sort();
};
*/

/* The below method sorts the stack s 
you are required to complete the below method */
void insertSort(stack<int> &st, int num){
    if(st.empty() || st.top() <= num){
        st.push(num);
        return;
    }
    int save = st.top();
    st.pop();
    insertSort(st,num);
    st.push(save);
}
void sortStack(stack<int> &st)
{

    if(st.empty()){
        return;
    }
 
    int save = st.top();
    st.pop();
    sortStack(st);
    insertSort(st,save);
    
}



void SortedStack :: sort()
{
    sortStack(s);
   //Your code here
}