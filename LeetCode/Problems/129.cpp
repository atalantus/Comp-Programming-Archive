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
    int sumNumbers(TreeNode* root) {
        int s = 0;
        visit(root, 0, s);
        return s;
    }

    void visit(TreeNode* root, int n, int& sum) {
        n = n * 10 + root->val;

        // return leaf path value
        if (!root->left && !root->right) {
            sum += n;
            return;
        }

        if (root->left)
            visit(root->left, n, sum);
        if (root->right)
            visit(root->right, n, sum);
    }
};