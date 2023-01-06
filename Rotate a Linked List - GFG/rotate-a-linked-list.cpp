//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
/*

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/


class Solution
{
    public:
    //Function to rotate a linked list.
    Node* rotate(Node* head, int k)
    {
        // Your code here
        int size=0;
        Node* t = head;
        Node*z = NULL;
        while(t){
            size++;
            z = t;
            t = t->next;
        }
        // t->next = head;
        // z = t;
        t=head;
        int n = k%size;
        if(n == 0){
            return head;
        }
        Node*prev = NULL;
        
        while(n--){
            prev = t;
            t = t->next;
        }
        Node *newHead = t;
        
        
        
        // cout<<newHead->data<<endl;
        // cout<<prev->data<<endl;
        // cout<<z->data<<endl;
        z->next = head;
        
        
        prev->next = NULL;
        // Node *z= newHead;
        // cout<<z->data<<endl;
        // while(z!= NULL){
        //     z=z->next;
        // }
        
        
        
        
        return newHead;
        
        // return head;
    }
};
    


//{ Driver Code Starts.

void printList(Node *n)
{
    while (n != NULL)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, val, k;
        cin>>n;
        
        cin>> val;
        Node *head = new Node(val);
        Node *tail = head;
        
        for(int i=0; i<n-1; i++)
        {
            cin>> val;
            tail->next = new Node(val);
            tail = tail->next;
        }
        
        cin>> k;
        
        Solution ob;
        head = ob.rotate(head,k);
        printList(head);
    }
    return 1;
}

// } Driver Code Ends