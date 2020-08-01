/*
Given inorder and postorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given

inorder = [9,3,15,20,7]
postorder = [9,15,7,20,3]
Return the following binary tree:

    3
   / \
  9  20
    /  \
   15   7
   
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
private:
    TreeNode* buildTreeHelper(vector<int>& inorder, vector<int>& postorder, int istart, int iend, int pstart, int pend){
        
        if(istart > iend || pstart > pend){
            return NULL;
        }
        
        
        TreeNode* root = new TreeNode(postorder[pend]);
        int idx;
        
        for(int i = istart; i <= iend; i++){
            if(inorder[i] == root->val){
                idx = i;
            }
        }
        root->left = buildTreeHelper(inorder, postorder, istart,idx - 1, pstart, pstart + idx -istart - 1);
        
        root->right = buildTreeHelper(inorder, postorder, idx+1, iend, pend- (iend - idx), pend - 1);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return buildTreeHelper(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
    }
};
