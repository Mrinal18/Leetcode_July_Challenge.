"""
Using Deque

Complexity Analysis

Time complexity: O(N)

Space complexity: O(N)

"""

from collections import deque

class Solution:
    def reverseWords(self, s: str) -> str:
        #return ' '.join(s.split()[::-1])
        
        #implemetation for deque:
        
        left = 0
        right = len(s) - 1
        
        #removing the leading spaces;
        while left <= right and s[left] == ' ':
            left = left + 1
        
        #removing trailing spaces:
        while left <= right and s[right] == ' ':
            right = right - 1
            
        d, word = deque(), []
        
        #pushing word by word into deque
        while left <= right:
            if s[left] == ' ' and word:
                d.appendleft(''.join(word))
                word = []
            elif s[left] != ' ':
                word.append(s[left])
                
            left += 1
            
        d.appendleft(''.join(word))
        
        return ' '.join(d)
                
            
        
        
        
