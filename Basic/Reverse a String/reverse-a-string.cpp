//{ Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function Template for C++
class Solution
{
    public:
    string reverseWord(string str)
    {
        // Your code goes here
         int n=str.length(); 
        int i=0; int j=n-1; 
        while(i<j) 
        { 
            int temp; 
            temp=str[i];
            str[i]=str[j];
            str[j]=temp; 
            i++;
            j--;
        } 
        return str;
    }
};



//{ Driver Code Starts.

int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
    	string s;
    	cin >> s;
    	Solution ob;
    	cout << ob.reverseWord(s) << endl;
	}
	return 0;
	
}


// } Driver Code Ends