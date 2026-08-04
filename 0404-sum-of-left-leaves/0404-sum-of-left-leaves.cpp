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
private:
    int dfs(TreeNode* root){
        int curr = 0;
        if(root == nullptr){
            return 0;
        }

        int left = dfs(root->left);
        int right = dfs(root->right);

        if(root->left && root->left->left == nullptr && root->left->right == nullptr){
            curr = root->left->val;
        }

        return left + right + curr;


    }
public:
    int sumOfLeftLeaves(TreeNode* root) {

        return dfs(root);
        
    }
};