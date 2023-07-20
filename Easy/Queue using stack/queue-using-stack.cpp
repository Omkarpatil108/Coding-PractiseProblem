//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Queue {
    stack<int> input, output;
public:

    void enqueue(int x) {
        input.push(x);
    }

    int dequeue() {
        // int ans=output.top();
        // if(output.empty()==false)
        //     output.pop();
        // else{
        //     while(!input.empty())
        //     {
        //         output.push(input.top());
        //         input.pop();
        //     }
        //     return ans;
        // }
        if(output.empty())
        {
            while(!input.empty())
            {
                int curr=input.top();
                output.push(curr);
                input.pop();
            }
        }
        
        if(!output.empty())
        {
            int ans=output.top();
            output.pop();
            return ans;
        }
    }
        
  
};

//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        Queue ob;

        int Q;
        cin>>Q;
        while(Q--){
        int QueryType=0;
        cin>>QueryType;
        if(QueryType==1)
        {
            int a;
            cin>>a;
            ob.enqueue(a);
        }
        else if(QueryType==2)
        {
            cout<<ob.dequeue()<<" ";

        }
        }
    cout<<endl;
    }
}

// } Driver Code Ends