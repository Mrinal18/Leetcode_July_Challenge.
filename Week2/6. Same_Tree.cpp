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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        /*bool result = false;
        
        //check if the root of two trees are equal or not.
        if (p == NULL && q == NULL) return true;
        if (q == NULL || p == NULL) return false;
        if(p->val != q->val)
            return false;
        
        
        return isSameTree(p->right, q->right) && isSameTree(p->left, q->left);
     
        //here the complexity will be O(N) for both time and space. 
        
        */
        
        
        //The idea is to store both the root values in a queue, and later dequeue both two compare them.

        queue<TreeNode*> que;
        que.push(p); que.push(q);
        
        while(!que.empty()){
            TreeNode* np = que.front();  que.pop();
            TreeNode* nq = que.front(); que.pop();
            
            if(np == NULL && nq == NULL) continue;
            
            if(np == NULL || nq == NULL || np->val != nq-> val) return false;
            
            que.push(np->left); que.push(nq->left);
            que.push(np->right); que.push(nq->right);
        }
        
        
        return true;
        
        
    }
};
