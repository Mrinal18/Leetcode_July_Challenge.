"""
Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
]

"""

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from collections import deque
class Solution:
    def zigzagLevelOrder(self, root: TreeNode) -> List[List[int]]:

        if root is None:
            return []
        
        output = []
        def dfs(node, depth):
            
            if depth >= len(output):
                output.append(deque([node.val]))
                
            else:
                if depth % 2 == 0:
                    #if even go to right side ie, do normal append
                    output[depth].append(node.val)
                else:
                    #if odd then we traverse left side
                    output[depth].appendleft(node.val)
                
            for next_node in [node.left, node.right]:
                if next_node is not None:
                    dfs(next_node, depth + 1)
        
        dfs(root, 0)
        print(output)
        
        return output
                    
            
