"""
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).

Find the minimum element.

The array may contain duplicates.

Example 1:

Input: [1,3,5]
Output: 1
Example 2:

Input: [2,2,2,0,1]
Output: 0
"""

class Solution:
    def findMin(self, nums: List[int]) -> int:
        left = 0
        right = len(nums) - 1
        
        mid = 0
        
        while(left <= right):
            mid = left + (right -left) // 2
            
            if(nums[mid] > nums[right]):
                left = mid + 1
            elif nums[mid] < nums[right]:
                right = mid
                
            elif(nums[right-1] > nums[right]): #this is just a check to check the pivot index which will be passed by at hi--. To avoid this, we can add the following judgement:
                left = right
                break   
            else:
                right-=1 #if nums[mid] and nums[right] are same
                
        return nums[left]
