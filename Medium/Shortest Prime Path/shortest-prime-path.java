//{ Driver Code Starts
//Initial Template for Java
import java.io.*;
import java.util.*;

// } Driver Code Ends
//User function Template for Java
class Solution{
    int solve(int num1,int num2){
        Queue<Integer> queue = new LinkedList<>();
        // Set to keep track of visited numbers
        HashSet<Integer> visited = new HashSet<>();

        // Enqueue the starting number
        queue.offer(num1);
        visited.add(num1);

        // Initialize distance
        int distance = 0;

        while (!queue.isEmpty()) {
            int size = queue.size();
            // Explore all numbers at the current distance level
            for (int i = 0; i < size; i++) {
                int currentNum = queue.poll();

                // Check if we have reached the destination
                if (currentNum == num2) {
                    return distance;
                }

                // Explore neighbors by changing a single digit
                for (int j = 0; j < 4; j++) {
                    for (int k = 0; k <= 9; k++) {
                        // Skip leading zeros
                        if (j == 0 && k == 0) {
                            continue;
                        }

                        // Construct the new number by changing a digit
                        int newNum = replaceDigit(currentNum, j, k);

                        // Check if the new number is prime and not visited
                        if (isPrime(newNum) && !visited.contains(newNum)) {
                            // Enqueue the new number and mark it as visited
                            queue.offer(newNum);
                            visited.add(newNum);
                        }
                    }
                }
            }

            // Increment the distance for the next level of exploration
            distance++;
        }

        // If we reach here, it means num2 is not reachable from num1
        return -1;
    }

    // Helper method to replace a digit in a number
    private int replaceDigit(int num, int position, int newDigit) {
        int[] digits = new int[4];
        for (int i = 3; i >= 0; i--) {
            digits[i] = num % 10;
            num /= 10;
        }
        digits[position] = newDigit;
        int result = 0;
        for (int digit : digits) {
            result = result * 10 + digit;
        }
        return result;
    }

    // Helper method to check if a number is prime
    private boolean isPrime(int num) {
        if (num < 2) {
            return false;
        }
        for (int i = 2; i <= Math.sqrt(num); i++) {
            if (num % i == 0) {
                return false;
            }
        }
        return true;
    }
}

//{ Driver Code Starts.
class GFG{
    public static void main(String args[]) throws IOException{
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());
        while(t-- > 0)
        {
            String input_line[] = read.readLine().trim().split("\\s+");
            int num1=Integer.parseInt(input_line[0]);
            int num2=Integer.parseInt(input_line[1]);
            
            Solution ob = new Solution();
            System.out.println(ob.solve(num1,num2));
        }
    }
}
// } Driver Code Ends