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
    bool helper(TreeNode* root, int target){
        if(root->left == NULL && root->right == NULL){
            return root->val == target;
        }

        bool left = true;
        if(root->left){
            left = helper(root->left, target);
        }
        
        bool right = true;
        if(root->right){
            right = helper(root->right, target);
        }
        
        if(left == true && right == true){
            root->left = NULL;
            root->right = NULL;
            return root->val == target;
        }
        else if(left == true){
            root->left = NULL;
        }
        else if(right == true){
            root->right = NULL;
        }

        return false;
    }
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        
        bool flag = helper(root, target);
        if(flag == true){
            return NULL;
        }
        return root;
    }
};