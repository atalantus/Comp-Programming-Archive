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

// Time Complexity: O(n)
class Solution {
public:
    int maxDepth(TreeNode* root) {
        return search(root, 0);
    }
    
    int search(TreeNode* root, int depth) {
        if (root == nullptr) return 0;
        
        return max(search(root->left, depth), search(root->right, depth)) + 1;
    }
};