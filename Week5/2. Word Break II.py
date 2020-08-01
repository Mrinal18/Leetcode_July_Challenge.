"""
Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, add spaces in s to construct a sentence where each word is a valid dictionary word. Return all such possible sentences.

Note:

The same word in the dictionary may be reused multiple times in the segmentation.
You may assume the dictionary does not contain duplicate words.
Example 1:

Input:
s = "catsanddog"
wordDict = ["cat", "cats", "and", "sand", "dog"]
Output:
[
  "cats and dog",
  "cat sand dog"
]
Example 2:

Input:
s = "pineapplepenapple"
wordDict = ["apple", "pen", "applepen", "pine", "pineapple"]
Output:
[
  "pine apple pen apple",
  "pineapple pen apple",
  "pine applepen apple"
]
Explanation: Note that you are allowed to reuse a dictionary word.
Example 3:

Input:
s = "catsandog"
wordDict = ["cats", "dog", "sand", "and", "cat"]
Output:
[]
"""

class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> List[str]:
        wordSet = set(wordDict)
        
        #set a table to map the string to its word breal
        
        memo = defaultdict(list)
        @lru_cache(None)
        def wordbreak(s):
            if not s:
                return [[]] #list of empty list
            
            if s in memo:
                #returned the cached solution directly
                return memo[s]
            
            
            for endIndex in range(1, len(s) + 1):
                word = s[:endIndex]
                if word in wordSet:
                    for subsentence in wordbreak(s[endIndex:]):
                        memo[s].append([word] + subsentence)
            return memo[s]
        
        
        wordbreak(s)
        
        return [" ".join(words) for words in memo[s]]
        
