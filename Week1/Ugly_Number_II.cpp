/*
Write a program to find the n-th ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. 

Example:

Input: n = 10
Output: 12
Explanation: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.
Note:  

1 is typically treated as an ugly number.
n does not exceed 1690.

*/

class Solution {
public:
    int nthUglyNumber(int n) {
        if(n <=0)
            return 0;
        
        if (n == 1)
            return 1;
        
        vector<int> K(n);
        
        K[0] = 1;
        //make the counters for 2, 3, 5
        
        int t2 = 0;
        int t3 = 0;
        int t5 = 0;
        for(int i = 1; i < n; i++){
            K[i] = min(K[t2] * 2, min(K[t3] * 3, K[t5] * 5));
            
            if(K[i] == K[t2] * 2) t2++;
            if(K[i] == K[t3] * 3) t3++;
            if(K[i] == K[t5] * 5) t5++;
            
        }
        
        return K[n-1];
    }
};
