"""

Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once.

Example:

Input:  [1,2,1,3,2,5]
Output: [3,5]
Note:

The order of the result is not important. So in the above example, [5, 3] is also correct.
Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?

"""
class Solution:
    def singleNumber(self, nums: List[int]) -> List[int]:
        """#this is O(n) solution. 
        if len(nums) == 0:
            return [0,0]
        
        c = Counter(nums)
        
        output = []
        for key in c:
            if c[key] == 1:
                output.append(key)
        return output
    
        
        """
        
        #for O(1) solution, we will have to use bit manipulatio
        
        bitmask = 0
        
        #difference between two numbers (a and y) wjicj were only seen once.
        for num in nums:
            bitmask ^= num
            
            #rightmost 1-bit diff between a and y
        diff = bitmask & (-bitmask)
            
        x = 0
        for num in nums:
            if num & diff:
                #bitmask will contaim only x
                x ^= num
                    
        return [x, bitmask ^ x]
                
