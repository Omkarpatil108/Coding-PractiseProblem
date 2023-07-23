//{ Driver Code Starts
#include <bits/stdc++.h>

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

struct Node *start = NULL;


// } Driver Code Ends
/*
 
  Node is defined as
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
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        
        // Add code here
        Node* zeroList = new Node(-1);
        Node* oneList = new Node(-1);
        Node* twoList = new Node(-1);
        Node* zeroptr = zeroList;
        Node* oneptr = oneList;
        Node* twoptr = twoList;

        while (head) {
            if (head->data == 0) {
                zeroptr->next = head;
                zeroptr = zeroptr->next;
            } else if (head->data == 1) {
                oneptr->next = head;
                oneptr = oneptr->next;
            } else {
                twoptr->next = head;
                twoptr = twoptr->next;
            }

            head = head->next;
        }


        if (zeroList->next != nullptr) {
            if (oneList->next != nullptr) {
                zeroptr->next = oneList->next;
                oneptr->next = twoList->next;
            } else {
                zeroptr->next = twoList->next;
            }
            
            twoptr->next = nullptr;
            return zeroList->next;
        } else if (oneList->next != nullptr) {
            oneptr->next = twoList->next;
            twoptr->next = nullptr;
            
            return oneList->next;
        } else {
            twoptr->next = nullptr;
            return twoList->next;
        }
        
    }
};


//{ Driver Code Starts.

// Function to sort a linked list of 0s, 1s and 2s
void printList(struct Node *Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
void insert(int n1) {
    int n, value, i;
    // scanf("%d",&n);
    n = n1;
    struct Node *temp;
    for (i = 0; i < n; i++) {
        scanf("%d", &value);

        if (i == 0) {
            start = new Node(value);
            temp = start;
            continue;
        } else {
            temp->next = new Node(value);
            temp = temp->next;
            temp->next = NULL;
        }
    }
}

int main() {

    int n;

    int t;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        insert(n);
        Solution ob;
        struct Node *newHead = ob.segregate(start);
        printList(newHead);
    }

    return 0;
}
// } Driver Code Ends