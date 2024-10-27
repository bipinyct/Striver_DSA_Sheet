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
    int rangeSumBST(TreeNode* root, int low, int high) {
    //if root node is empty/null then returns 0...
    if (root == nullptr) return 0;
    //create a container to store sum/ans...
    int ans = 0;
    //if root node is greater than low then traverse left subtree...
    if (root->val > low) ans += rangeSumBST(root->left, low, high);
    //if root node is greater && smaller than high then sum value of nodes accordingly...
    if (root->val >= low && root->val <= high) ans += root->val;
    //if required then traverse right subtree but only when if root node is smaller than high...
    if (root->val < high) ans += rangeSumBST(root->right, low, high);

    //finally, returns sum/ans...
    //Time Complexity : O(n)
    //Space Complexity : O(n)

    return ans;
}
};