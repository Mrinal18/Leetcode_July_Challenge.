"""
Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:

The solution set must not contain duplicate triplets.

Example:

Given array nums = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
"""

"""
This is the answer from @caikehe and all the comments below
The main idea is to iterate every number in nums.
We use the number as a target to find two other numbers which make total zero.
For those two other numbers, we move pointers, `l` and `r`, to try them.
`l` start from left to right.
`r` start from right to left.
First, we sort the array, so we can easily move i around and know how to adjust l and r.
If the number is the same as the number before, we have used it as target already, continue. [1]
We always start the left pointer from `i+1` because the combination of 0~`i` has already been tried. [2]
Now we calculate the total:
If the total is less than zero, we need it to be larger, so we move the left pointer. [3]
If the total is greater than zero, we need it to be smaller, so we move the right pointer. [4]
If the total is zero, bingo! [5]
We need to move the left and right pointers to the next different numbers, so we do not get repeating result. [6]
We do not need to consider `i` after `nums[i]>0`, since sum of 3 positive will be always greater than zero. [7]
We do not need to try the last two, since there are no rooms for `l` and `r` pointers.
You can think of it as The last two have been tried by all others. [8]
For time complexity
Sorting takes `O(NlogN)`
Now, we need to think as if the `nums` is really really big
We iterate through the `nums` once, and each time we iterate the whole array again by a while loop
So it is `O(NlogN+N^2)~=O(N^2)`
For space complexity
We didn't use extra space except the `res`
Since we may store the whole 'nums' in it
So it is `O(N)`
`N` is the length of `nums`
"""
class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        
        res = []
        
        nums.sort()

        length = len(nums)
        
        
        for i in range(length - 2): #lenght -2 because we need to make two poiter which needs to be ahead of the i
            if i > 0 and nums[i] == nums[i-1]: continue #because we need to eliminate duplicate numbers.
                
            left, right = i + 1, length -1
            
            while(left < right):
                total = nums[i] + nums[left]  + nums[right]
                
                if total > 0:
                    right -= 1
                elif total < 0:
                    left += 1
                else:
                    res.append([nums[i], nums[left], nums[right]])
                    
                    
                    while left < right and nums[left] == nums[left + 1]:
                        left = left + 1
                    while left < right and nums[right] == nums[right -1]:
                        right = right - 1
                        
                        
                    left += 1
                    right -= 1
                    
        return res
   
