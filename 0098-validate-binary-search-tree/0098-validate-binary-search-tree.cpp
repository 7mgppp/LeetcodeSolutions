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
    long long prev = LLONG_MIN;
private:
    bool dfs(TreeNode* root){
        if(root == NULL){
            return true;
        }

        if (!dfs(root->left))
        return false;

        if(root->val <= prev){
            return false;
        }

        prev = root->val;

        return dfs(root->right);

    }
public:
    bool isValidBST(TreeNode* root) {

        return dfs(root);
        
    }
};