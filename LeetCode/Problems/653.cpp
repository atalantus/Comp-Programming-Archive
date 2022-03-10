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

// Time Complexity: O(n*log n)
class Solution {
   public:
    bool findTarget(TreeNode* root, int k) { return inorder(root, root, k); }

    bool inorder(TreeNode* cur, TreeNode* root, int k) {
        if (cur == nullptr)
            return false;

        if (inorder(cur->left, root, k))
            return true;
        if (find(root, cur, k - cur->val))
            return true;
        if (inorder(cur->right, root, k))
            return true;

        return false;
    }

    bool find(TreeNode* root, TreeNode* skip, int v) {
        if (root == nullptr)
            return false;

        if (root->val == v && root != skip)
            return true;
        if (root->val >= v)
            return find(root->left, skip, v);
        return find(root->right, skip, v);
    }
};