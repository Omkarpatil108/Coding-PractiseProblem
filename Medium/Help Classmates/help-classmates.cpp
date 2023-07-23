//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
//User function Template for C++

class Solution{
    
    public:
    vector<int> help_classmate(vector<int> arr, int n) 
    { 
        // Your code goes here
        stack<int>st;
        st.push(-1);
        // vector<int>nse(n,-1);
        for(int i=n-1;i>=0;i--)
        {
            int t1=st.top();
            // while(!st.empty() && arr[i]<arr[st.top()])
            // {
            //     nse[st.top()]=arr[i];
            //     st.pop();
            // }
            // st.push();
            if(arr[i]>st.top())
            {
                st.push(arr[i]);
                arr[i]=t1;
            }
            else{
                while(st.top()>=arr[i])
                {
                    st.pop();
                }
                int t2=st.top();
                st.push(arr[i]);
                arr[i]=t2;
            }
        }
        return arr;
    } 
};

//{ Driver Code Starts.

int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<int> array(n);
		for (int i = 0; i < n; ++i)
		{
			cin>>array[i];
		}
		Solution obj;
		vector<int> result = obj.help_classmate(array,n);
		for (int i = 0; i < n; ++i)
		{
			cout<<result[i]<<" ";
		}
		cout<<"\n";
	}
	return 0; 
}


// } Driver Code Ends