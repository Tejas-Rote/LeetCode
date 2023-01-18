//{ Driver Code Starts
#include <iostream>

using namespace std;

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};



Node *swapkthnode(Node* head, int num, int K);

void addressstore(Node **arr, Node* head)
{
    Node* temp = head;
    int i = 0;
    while(temp){
        arr[i] = temp;
        i++;
        temp = temp->next;
    }
}

bool check(Node ** before, Node **after, int num, int K)
{
    if(K > num)
        return 1;
    return (before[K-1] == after[num - K]) && (before[num-K] == after[K-1]);
}

int main()
{
    int T;
    cin>>T;
    while(T--){
        int num, K , firstdata;
        cin>>num>>K;
        int temp;
        cin>>firstdata;
        Node* head = new Node(firstdata);
        Node* tail = head;
        for(int i = 0; i<num - 1; i++){
            cin>>temp;
            tail->next = new Node(temp);
            tail = tail->next;
        }
        
        Node *before[num];
        addressstore(before, head);
        
        head = swapkthnode(head, num, K);
        
        Node *after[num];
        addressstore(after, head);
        
        if(check(before, after, num, K))
            cout<<1<<endl;
        else
            cout<<0<<endl;
    }
}

// } Driver Code Ends


//User function Template for C++

/* Linked List Node structure
   struct Node  {
     int data;
     Node *next;
     Node(int x) {
        data = x;
        next = NULL;
  }
  }
*/

//Function to swap Kth node from beginning and end in a linked list.
Node *swapkthnode(Node* head, int num, int K)
{
    
    if(head==NULL)
       return NULL;

    

    Node*fp=head;
    Node*sp=head,*sp_prev=NULL;
    Node*node1=head,*node1_prev=NULL;
    if(K>num)
    return head;
    
    int k=K;
    
    while(--k)
    
    {
      node1_prev=node1;
      node1=node1->next;
      fp=fp->next;
    }

      

    while(fp->next!=NULL)
    {
        sp_prev=sp;
        sp=sp->next;
        fp=fp->next;
    }

    //   cout<<node1_prev->data;
    //   cout<<node1->data;
    //   cout<<sp_prev->data;
    //   cout<<sp->data;

      

    if(K==1)
    {
        sp_prev->next=node1;
        Node*temp=node1->next;
        node1->next=sp->next;
        sp->next=temp;
        return sp;
    }
    
    if(K==num)
    
    {
        node1_prev->next=sp;
        Node*temp=sp->next;
        sp->next=node1->next;
        node1->next=temp;
        return node1;
    
    }
    
    node1_prev->next=sp;
    sp_prev->next=node1;
    Node*temp=node1->next;
    node1->next=sp->next;
    sp->next=temp;

    return head;
    
    
    
    
    
    
    
    
    
    // // Your Code here
    // if(num<K){
    //     return head;
    // }
    
    // int front = K-1;
    // int end = num-K;
    // Node * t = head;
    // Node *p =head, *q=head;
    // Node*prev1 = NULL, *prev2 = NULL;
    
    // int cnt =0;
    
    // if(num<K){
    //     return head;
    // }
    
    // if(front== end){
    //     return head;
    // }
    






    
    
    
    
    // // t= head;
    // // while(t){
    // //     if(cnt == front){
    // //         p= t;
    // //     }
        
    // //     if(cnt == end){
    // //         q = t;
    // //     }
    // //     t = t->next;
    // //     cnt++;
    // // }
    // // cout<<p->data<<" "<<q->data;
    
    

    
    
    
    // // t=head;
    // for(int i=0;i<front;i++){
    //     prev1 = p;
    //     p = p->next;
        
    // }
    
    
    
    // // t=head;
    //  for(int i=0;i<end;i++){
    //     prev2 = q;
    //     q = q->next;
        
    // }
    
    // cout<<p->data<<" "<<q->data;
    // // cout<<prev1->data<<" "<<prev2->data<<endl; 
     
    
    // if(K==1){
    //     return head = q;
    // }
    
    // if(K == num){
    //     return head = p;
    // }
    
    
    // // prev1->next = q; 
    // // prev2->next = p;
    // // swap(p->next, q->next);



    
    // // cout<<prev1->data<<" "<<prev2->data<<endl;
    
    
    
  
    
    
    

    
    


    

    

    
    // return head;
    
}
