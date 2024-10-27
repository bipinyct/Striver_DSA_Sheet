/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        // returns NULL if the node is NULL
        if(original == NULL)
            return NULL;

        // returns reference to the cloned node that matches the target
        if(original == target)
            return cloned;

        TreeNode *result = getTargetCopy(original->left, cloned->left, target);
        // returns cloned reference if found i.e if result is not null
        if(result)
            return result;

        return getTargetCopy(original->right, cloned->right, target);
    }
};