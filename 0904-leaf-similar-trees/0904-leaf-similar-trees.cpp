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
    void find_leaf(vector<int> &a, TreeNode* r){
        if(r == nullptr) return ;
        if(r->left == nullptr && r->right == nullptr){
            a.push_back(r->val);
            return ;
        }
        find_leaf(a,r->left);
        find_leaf(a,r->right);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> a , b ;
        find_leaf(a,root1);
        find_leaf(b,root2);
        if(a.size() != b.size()) return false;
        for(int i = 0 ; i < a.size() ; i++) if(a[i]!=b[i]) return false;
        return true;
    }
};