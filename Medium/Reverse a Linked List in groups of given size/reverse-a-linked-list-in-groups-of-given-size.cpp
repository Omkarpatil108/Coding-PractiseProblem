//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


struct node
{
    int data;
    struct node* next;
    
    node(int x){
        data = x;
        next = NULL;
    }
    
};

/* Function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}


// } Driver Code Ends
/*
  Reverse a linked list
  The input list will have at least one element  
  Return the node which points to the head of the new LinkedList
  Node is defined as 
    struct node
    {
        int data;
        struct node* next;
    
        node(int x){
            data = x;
            next = NULL;
        }
    
    }*head;
*/

class Solution
{
    public:
    struct node* reverseList(struct node *head) {
        struct node* prev = nullptr;
        struct node* next = nullptr;
        struct node* ptr = head;

        while (ptr) {
            next = ptr->next;
            ptr->next = prev;
            prev = ptr;
            ptr = next;
        }

        return prev;
    }
    struct node *reverse (struct node *head, int k)
    { 
        // Complete this method
        struct node* nn = head;
        struct node* ans =new struct node(-1);
        struct node* ansPtr = ans;

        while (nn != nullptr) {
            struct node* start = nn;
            struct node* end = nn;

            int cnt = k;
            while (end != nullptr && cnt != 1) {
                end = end->next;
                cnt--;
            }

            if (end != nullptr) {
                nn = end->next;
                end->next = nullptr;
            } else {
                nn = nullptr;
            }
            
            ansPtr->next = reverseList(start);
            ansPtr = start;
        }

        return ans->next;
    }
};


//{ Driver Code Starts.

/* Drier program to test above function*/
int main(void)
{
    int t;
    cin>>t;
     
    while(t--)
    {
        struct node* head = NULL;
        struct node* temp = NULL;
        int n;
        cin >> n;
         
        for(int i=0 ; i<n ; i++)
        {
            int value;
            cin >> value;
            if(i == 0)
            {
                head = new node(value);
                temp = head;
            }
            else
            {
                temp->next = new node(value);
                temp = temp->next;
            }
        }
        
        int k;
        cin>>k;
        
        Solution ob;
        head = ob.reverse(head, k);
        printList(head);
    }
     
    return(0);
}


// } Driver Code Ends