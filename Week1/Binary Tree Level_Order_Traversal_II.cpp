/*
Description:


Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
]

Approch :

Iteration: BFS Traversal
Algorithm

The recursion above could be rewritten in the iteration form.

Let's keep each tree level in the queue structure, which typically orders elements in a FIFO (first-in-first-out) manner. In Java one could use ArrayDeque implementation of the Queue interface. In Python using Queue structure would be an overkill since it's designed for a safe exchange between multiple threads and hence requires locking which leads to a performance downgrade. In Python the queue implementation with a fast atomic append() and popleft() is deque.

Algorithm

Initialize two queues: one for the current level, and one for the next. Add root into nextLevel queue.

While nextLevel queue is not empty:

Initialize the current level currLevel = nextLevel, and empty the next level nextLevel.

Iterate over the current level queue:

Append the node value to the last level in levels.

Add first left and then right child node into nextLevel queue.

Return reversed levels.

*/ 

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        
       vector<vector<int>> result;
        
        if(!root) return result;
        
        queue<TreeNode*> Q;
        
        Q.push(root);
        //BFS algo starting now
        while(!Q.empty()){
            int n = Q.size();
            
            vector<int> nodes(n);
            
            for(int i = 0; i < n; ++i){
                TreeNode* node = Q.front();
                Q.pop();
                
                nodes[i] = node->val;
                
                if(node->left) Q.push(node->left);
                if(node->right) Q.push(node->right);
            }
            result.push_back(nodes);
        }
        
        reverse(result.begin(), result.end());
        return result;
    }
    
};
