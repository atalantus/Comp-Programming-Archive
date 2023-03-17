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
    vector<int> in;
    vector<int> post;
    //unordered_map<int,int> inMap;
    map<int,int> inMap;
    //int inMap[6000];

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        in = inorder;
        post = postorder;
        int s = inorder.size();
        
        // calculate inMap
        for (int i = 0; i < s; ++i)
            inMap[inorder[i]] = i;
        
        return buildSubTree(0, s, 0, s);
    }

    TreeNode* buildSubTree(int inF, int inT, int poF, int poT) {
        auto root = new TreeNode(post[poT-1]);

        // leaf
        if (inF == inT - 1)
            return root;

        // find index in inorder for root
        int i = inMap[root->val];

        if (i > inF) {
            // we have left subtree
            root->left = buildSubTree(inF, i, poF, poF + i - inF);
        }

        if (i < inT - 1) {
            // we have right subtree
            root->right = buildSubTree(i+1, inT, poF + i - inF, poT-1);
        }

        return root;
    }
};