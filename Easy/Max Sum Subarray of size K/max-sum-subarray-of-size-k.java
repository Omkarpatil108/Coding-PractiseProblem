//{ Driver Code Starts
//Initial Template for Java
import java.io.*;
import java.util.*;

class GFG
{
    public static void main(String args[])throws IOException
    {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while(t-- > 0)
        {
            
            int N=sc.nextInt();
            int K=sc.nextInt();
            ArrayList<Integer> Arr = new ArrayList<Integer>(N); 
  
            // Appending new elements at 
            // the end of the list 
            for (int i = 0; i < N; i++) {
                int x = sc.nextInt();
                Arr.add(x); 
            }

            Solution ob = new Solution();
            System.out.println(ob.maximumSumSubarray(K,Arr,N));
        }
    }
}

// } Driver Code Ends


//User function Template for Java
class Solution{
    static long maximumSumSubarray(int K, ArrayList<Integer> Arr,int N){
        long maxSum = 0l;
        Deque<Integer> dq = new ArrayDeque<>();
        long tempSum = 0l;
        for(int i = 0; i < N; i += 1) {
            if(dq.isEmpty()) {
                dq.addLast(Arr.get(i));
                tempSum += Arr.get(i);
            } else {
                if(dq.size() < K) {
                    dq.addLast(Arr.get(i));
                    tempSum += Arr.get(i);
                } else {
                    tempSum -= dq.remove();
                    dq.addLast(Arr.get(i));
                    tempSum += Arr.get(i);
                }
            }
            maxSum = Math.max(maxSum, tempSum);
        }
        return maxSum;
    }
}