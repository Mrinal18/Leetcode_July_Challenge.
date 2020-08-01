"""
The Hamming distance between two integers is the number of positions at which the corresponding bits are different.

Given two integers x and y, calculate the Hamming distance.

Note:
0 ≤ x, y < 231.

Example:

Input: x = 1, y = 4

Output: 2

Explanation:
1   (0 0 0 1)
4   (0 1 0 0)
       ↑   ↑

The above arrows point to positions where the corresponding bits are different.
"""

class Solution:
    def hammingDistance(self, x: int, y: int) -> int:
        #we have to do an XOR for this operation. 
        #for example: we have number 11011001 and 10011101, when we do XOR of these number
        #11011001 ^ 10011101 = 01000100. so since the number of 1s is 2, therefore the distance is 2. 
        
        
        #first perform the xor for two numbers.
        """xor = x ^ y
        
        #convert this into a string so you can split it later.
        xor = "{:b}".format(xor)
        count = 0
        #now check the number of 1s you get:
        for i in xor:
            count += int(i)     
        return count 
        """
        
        xor = x ^ y 
        
        xor = bin(xor)
        
        count = xor.count('1')
        
        return count
