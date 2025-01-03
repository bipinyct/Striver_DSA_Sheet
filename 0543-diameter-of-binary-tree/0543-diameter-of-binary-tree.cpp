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
    int max_diameter = 0;

    int diameterOfBinaryTree(TreeNode* root) {
        if (root == nullptr) return 0;
        getLength(root);
        return max_diameter;
    }

    int getLength(TreeNode* root) {
        if (root == nullptr) return 0;
        int left = getLength(root->left);
        int right = getLength(root->right);
        max_diameter = std::max(max_diameter, left + right);
        return 1 + std::max(left, right);
    }
};