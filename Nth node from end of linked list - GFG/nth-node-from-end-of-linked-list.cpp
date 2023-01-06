//{ Driver Code Starts
// C program to find n'th Node in linked list
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};


/* Function to get the nth node from the last of a linked list*/
int getNthFromLast(struct Node* head, int n);



/* Driver program to test above function*/
int main()
{
  int T,i,n,l,k;

    cin>>T;

    while(T--){
    struct Node *head = NULL,  *tail = NULL;

        cin>>n>>k;
        int firstdata;
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }

    cout<<getNthFromLast(head, k)<<endl;
    }
    return 0;
}
// } Driver Code Ends


/* struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

//Function to find the data of nth node from the end of a linked list.
int getNthFromLast(Node *head, int n)
{
       // Your code here
       Node * t = head;
       int ans =-1;
    //   while(t !=NULL && n >0) {
    //         if(n == 1){
    //             ans = t->next->data;
    //         }
    //         t= t->next;
    //         n--;
    //   }
       
       int size=0;
       while(t!= NULL){
           size++;
            t =t->next;
       }
    //   
    //   cout<<size<<endl;
       
       if(n > size){
           return -1;
       }
       
        // for(int i=0;i<size- n ;i++){
        //     cout<<t->data<<endl;
        //     t = t->next;
            
        // }   
        
        int f = size- n ;
        t = head;
        int cnt =1;
        if(f == 0){
            return t->data;
        }
        if(f == 1){
            return t->next->data;
        }
        // cout<<f<<endl;
        
        
        
        t = head;
        
        while(t!= NULL && cnt< f){
            t = t->next;
            cnt++;
        }
        
    
       
       return t->next->data;
}

