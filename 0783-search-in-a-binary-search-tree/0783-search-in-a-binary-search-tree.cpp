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
    TreeNode* searchBST(TreeNode* root, int val) {
        // Base case: if the current node is NULL, return NULL
        if (root == NULL) return NULL;

        // If the current node's value matches the target value, return the node
        if (root->val == val) return root;

        // If the target value is greater, search in the right subtree
        else if (root->val < val) return searchBST(root->right, val);

        // If the target value is less, search in the left subtree
        else return searchBST(root->left, val);
    }
};