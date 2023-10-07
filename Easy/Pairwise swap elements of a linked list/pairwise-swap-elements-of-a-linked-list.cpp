//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
/*
  Pairwise swap a linked list
  The input list will have at least one element
  node is defined as

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

}*head;
*/
class Solution
{
    public:
     struct Node* swapPair(struct Node* ptr1, struct Node* ptr2, struct Node* pre){
        ptr1->next=ptr2->next;
        ptr2->next=ptr1;
        pre->next=ptr2;
        return ptr1;
    }
    Node* pairWiseSwap(struct Node* head) 
    {
        // The task is to complete this method
        if(head->next==NULL) return head;

        struct Node* ptr = head;
        head=head->next;
        
        //First swap
        ptr->next=head->next;
        head->next=ptr;
        struct Node* pre=ptr;
        
        // 1st transition
        if(ptr->next == NULL || ptr->next->next ==NULL) return head;
        ptr=ptr->next;

        while (ptr->next != NULL )
        {
            //swap
            pre = swapPair(ptr,ptr->next, pre);
            
            // transition
            if(ptr->next == NULL) return head;
            ptr=ptr->next;
        
        }

        return head;
    }
};

//{ Driver Code Starts.

void printList(Node* node) 
{ 
	while (node != NULL) { 
		cout << node->data <<" "; 
		node = node->next; 
	}  
	cout<<"\n";
}

int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;

		int data;
		cin>>data;
		struct Node *head = new Node(data);
		struct Node *tail = head;
		map<Node*, int> mp;
		mp[head] = head->data;
		for (int i = 0; i<n-1; ++i)
		{
			cin>>data;
			tail->next = new Node(data);
			tail = tail->next;
			mp[tail] = tail->data;
		}
		struct Node *failure = new Node(-1);
		Solution ob;
		head = ob.pairWiseSwap(head);
		int flag = 0;
		struct Node *temp = head;
		while(temp){
		    if(mp[temp] != temp->data){
		        flag = 1;
		        break;
		    }
		    temp = temp->next;
		}
		if(flag)
		    printList(failure);
		else
		    printList(head);
	}
	return 0; 
}

// } Driver Code Ends