//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.util.*;

class GFG{
    public static void main(String args[])throws IOException
    {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(in.readLine());
        while(t-- > 0){
            String s = in.readLine();
            int k = Integer.parseInt(in.readLine());
            
            Solution ob = new Solution();
            System.out.println(ob.minValue(s, k));
        }
    }
}
// } Driver Code Ends


// User function Template for Java

class Solution{
    static int minValue(String s, int k){
        // code here
         Map<Character, Integer> frequencyMap = new HashMap<>();

        // Calculate character frequencies
        for (char c : s.toCharArray()) {
            frequencyMap.put(c, frequencyMap.getOrDefault(c, 0) + 1);
        }
        // Create a priority queue to keep characters with higher frequencies at the top
        PriorityQueue<Integer> maxHeap = new PriorityQueue<>(Collections.reverseOrder());
        maxHeap.addAll(frequencyMap.values());

        // Remove k elements from the frequency
        while (k > 0 && !maxHeap.isEmpty()) {
            int frequency = maxHeap.poll();
            if (frequency > 1) {
                maxHeap.offer(frequency - 1);
            }
            k--;
        }
        // Calculate the sum of squares of the remaining frequencies
        int sumOfSquares = 0;
        while (!maxHeap.isEmpty()) {
            int frequency = maxHeap.poll();
            sumOfSquares += frequency * frequency;
        }
        return sumOfSquares;
    }
}