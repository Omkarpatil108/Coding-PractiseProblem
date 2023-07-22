//{ Driver Code Starts
// C++ implementation to convert infix expression to postfix
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to convert an infix expression to a postfix expression.
    
    bool isOperator(char c)
    {
        return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
    }
    
    bool isHigherPrecedence(char op1, char op2) 
    {
        unordered_map<char, int> precedence;
        precedence['+'] = 1;
        precedence['-'] = 1;
        precedence['*'] = 2;
        precedence['/'] = 2;
        precedence['^'] = 3;
        
        return precedence[op1] >= precedence[op2];
    }
    string infixToPostfix(string s) 
    {
        // Your code here
        stack<char>st;  //for operators
        string ans="";//for postfix expressions
         unordered_map<char, int> mp;
        mp['+'] = 1;
        mp['-'] = 1;
        mp['*'] = 2;
        mp['/'] = 2;
        mp['^'] = 3;
        mp['('] = 0; // Lower precedence for opening parenthesis
        mp[')'] = 0; //
          
        for (int i = 0; i < s.size(); i++)
        {
            char c = s[i];
        
            if (isOperator(c)) 
            {
                while (!st.empty() && isHigherPrecedence(st.top(), c)) 
                {
                    ans += st.top();
                    st.pop();
                }
                st.push(c);
            }
            else if (c == '(')
            {
                st.push(c);
            } 
            else if (c == ')')
            {
                while (!st.empty() && st.top() != '(')
                {
                    ans += st.top();
                    st.pop();
                }
                st.pop(); // Pop the opening parenthesis '('
            } 
            else 
            {
                ans += c; // Append operands directly to the result
            }
        }

    // Pop any remaining operators from the stack
    while (!st.empty()) 
    {
        ans += st.top();
        st.pop();
    }

    return ans;
}
        
    
};


//{ Driver Code Starts.
// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    cin.ignore(INT_MAX, '\n');
    while (t--) {
        string exp;
        cin >> exp;
        Solution ob;
        cout << ob.infixToPostfix(exp) << endl;
    }
    return 0;
}

// } Driver Code Ends