//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to check if a string can be obtained by rotating
    //another string by exactly 2 places.
    bool isRotated(string str1, string str2)
    {
        // Your code here
        int m=str2.length();
        int n=str1.length();
        
        if(n != m)
        {
            return false;
        }
        for(int i=0;i<n;i++)
        {
            // if(str1[i]==str2[(i % str2.length()) +str1.length()-i] )return true;
            
             if(str1[(i+2)%n] != str2[i%m] && str1[(i)%m] != str2[(i+2)%m]) 
                return false;
            
        }
        return true;
        
    }

};


//{ Driver Code Starts.

int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		string b;
		cin>>s>>b;
		Solution obj;
		cout<<obj.isRotated(s,b)<<endl;
	}
	return 0;
}

// } Driver Code Ends