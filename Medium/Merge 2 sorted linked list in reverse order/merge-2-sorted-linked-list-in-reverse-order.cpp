//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node* next;
};

void print(struct Node *Node)
{
    while (Node!=NULL)
    {
        cout << Node->data << " ";
        Node = Node->next;
    }
}


Node *newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->next = NULL;
    return temp;
}


// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
};

*/
class Solution
{
    public:
    
    struct Node * mergeResult(Node *node1,Node *node2)
    {
        // your code goes here
        Node *ans = NULL;

    while (node1 && node2) {
        Node *node = new Node(); // Create a new node without specifying data
        node->data = (node1->data < node2->data) ? node1->data : node2->data;
        node->next = ans;
        ans = node;

        if (node1->data < node2->data) {
            node1 = node1->next;
        } else {
            node2 = node2->next;
        }
    }

    // Handle remaining nodes in node1
    while (node1) {
        Node *node = new Node();
        node->data = node1->data;
        node->next = ans;
        ans = node;
        node1 = node1->next;
    }

    // Handle remaining nodes in node2
    while (node2) {
        Node *node = new Node();
        node->data = node2->data;
        node->next = ans;
        ans = node;
        node2 = node2->next;
    }

    return ans;
    }  
};


//{ Driver Code Starts.

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int nA;
        cin>>nA;
        int nB;
        cin>>nB;

        struct Node* headA=NULL;
        struct Node* tempA = headA;

        for(int i=0;i<nA;i++)
        {
            int ele;
            cin>>ele;
            if(headA==NULL)
            {
                headA=tempA=newNode(ele);

            }else{
                tempA->next = newNode(ele);
				tempA=tempA->next;
            }
        }

        struct Node* headB=NULL;
        struct Node* tempB = headB;


        for(int i=0;i<nB;i++)
        {
            int ele;
            cin>>ele;
            if(headB==NULL)
            {
                headB=tempB=newNode(ele);

            }else{
                tempB->next = newNode(ele);
				tempB=tempB->next;
            }
        }
        
        Solution ob;
        struct Node* result = ob.mergeResult(headA,headB);

        print(result);
        cout<<endl;


    }
}

// } Driver Code Ends