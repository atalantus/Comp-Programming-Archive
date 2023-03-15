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
    int h;
    bool end;

    bool isCompleteTree(TreeNode* root) {
        int i = 0;
        TreeNode* t = root;
        while (true) {
            if (t == NULL) break;
            ++i;
            t = t->left;
        }
        h = i;
        end = false;
        return visit(root, 1);
    }

    bool visit(TreeNode* root, int d) {
        // right child but no left
        if (root->right && !root->left)
            return false;

        // leaf (no children)
        if (!root->right && !root->left) {
            // at correct height
            if ((d + end) == h) {
                return true;
            } else if (!end) {
                // end of tree
                end = true;
                return true;
            }
            // past the end and incorrect height
            return false;
        }

        // check left child
        if (!visit(root->left, d + 1))
            return false;

        if (root->right) {
            // check right child
            if (!visit(root->right, d + 1))
                return false;
        } else {
            // had correct left child but no right child
            // --> end
            if (!end) {
                end = true;
            } else {
                return false;
            }
        }
        return true;
    }
};