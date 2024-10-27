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

    // LOGIC -> make sorted array from inorder traversal
    // then traverse array and keep on creating new node to its left
    // TC = SC = O(N)

    void inorder(TreeNode* root, vector<int> &v){
        if(root == NULL){
            return ;
        }

        inorder(root -> left, v);
        v.push_back(root -> val);
        inorder(root -> right, v);
    }

    TreeNode* solve(vector<int> &v , int index){
        if(index >= v.size()){
            return NULL;
        }

        TreeNode* root = new TreeNode(v[index]);

        root -> right = solve(v,index+1);

        return root;
    }

    TreeNode* increasingBST(TreeNode* root) {
        vector<int> v;
        inorder(root,v);

        return solve(v,0);
    }


    // method 2 -- better
    // void make(TreeNode* root, TreeNode*& ans){
    //     if(root == NULL) return;
    //     make(root->left, ans);
    //     // ans->left = NULL;
    //     ans->right = new TreeNode(root->val);
    //     ans = ans->right;
    //     make(root->right, ans);
    // }

    // TreeNode* increasingBST(TreeNode* root) {
    //     TreeNode* dummy = new TreeNode(-1);
    //     TreeNode* ans = dummy;
    //     make(root, ans);
    //     return dummy->right;
    // }
};