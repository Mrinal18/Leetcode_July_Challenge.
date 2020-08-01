"""
Given two binary strings, return their sum (also a binary string).

The input strings are both non-empty and contains only characters 1 or 0.

Example 1:

Input: a = "11", b = "1"
Output: "100"
Example 2:

Input: a = "1010", b = "1011"
Output: "10101"
 

Constraints:

Each string consists only of '0' or '1' characters.
1 <= a.length, b.length <= 10^4
Each string is either "0" or doesn't contain any leading zero
"""

class Solution:
    def addBinary(self, a: str, b: str) -> str:
        #this approch is very time consuming as it has O(N+M) complexity. 
        #return '{0:b}'.format(int(a,2) + int(b,2))
        
        """Bit manipulation Method
Here the interviewer may as me to add these binary numbers without using addition operation.

if no addition operation then we have to use bit manipulation.

Tip:if you dnt know where to strat then do XOR operation on the input. That helps!! 


Algorithm

Convert a and b into integers x and y, x will be used to keep an answer, and y for the carry.

While carry is nonzero: y != 0:

Current answer without carry is XOR of x and y: answer = x^y.

Current carry is left-shifted AND of x and y: carry = (x & y) << 1.

Job is done, prepare the next loop: x = answer, y = carry.

Return x in the binary form.

        
        x, y = int(a, 2), int(b, 2)
        
        while y:
            answer = x ^ y 
            carry = (x & y ) << 1
            
            x, y = answer, carry

        return bin(x)[2:]  
        """
        """
        this approch is bit manipulation:
        
        Start from carry = 0. If number a has 1-bit in this lowest bit, add 1 to the carry. The same for number b: if number b has 1-bit in the lowest bit, add 1 to the carry. At this point the carry for the lowest bit could be equal to 
        Here i will make use of a carry:
        if my least sig = 1 then carry will become 1.
        
        Now, append the lowest bit of the carry to the answer and move the higest bit of the catry to the next order bit. 
        """

        n = max(len(a), len(b))
        
        a,b = a.zfill(n), b.zfill(n)
        
        carry = 0
        
        out = []
        
        for i in range(n - 1, -1, -1):
            if a[i] == '1':
                carry += 1
            if b[i] == '1':
                carry += 1
            
            if carry % 2 == 1:
                out.append('1')
            else:
                out.append('0')

                
            carry //= 2
            
            
        if carry == 1:
            out.append('1')
        out.reverse()
        
        
        return ''.join(out)
    
