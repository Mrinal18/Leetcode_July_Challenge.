"""
Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.

Example:

Input: 38
Output: 2 
Explanation: The process is like: 3 + 8 = 11, 1 + 1 = 2. 
             Since 2 has only one digit, return it.
Follow up:
Could you do it without any loop/recursion in O(1) runtime?

"""


class Solution:
    def addDigits(self, num: int) -> int:
        
        
        #this is a O(logN) complexity. but we need to do this in 
        '''total = 0
        
        while num > 0:
            total = total + (num % 10)
            num = num // 10
            
            if num ==0  and total >9:
                num = total
                total = 0
            
        return total
        '''
    
        #now we need to find the O(1)
        
        #this is realted to Mathematical digital sum formula:
        if num == 0:
            return 0
        if num % 9 == 0:
            return 9
        return num % 9
    
