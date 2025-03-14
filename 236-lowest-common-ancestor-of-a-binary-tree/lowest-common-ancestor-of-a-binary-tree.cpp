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
    TreeNode* findLCA(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root == NULL){
            return NULL;
        }

        if(root == p || root == q){
            return root;
        }
        TreeNode* left = findLCA(root->left, p, q);
        TreeNode* right = findLCA(root->right, p, q);

        if(left == NULL){
            return right;
        }
        if(right == NULL){
            return left;
        }

        if(right != NULL && left != NULL){
            return root;
        }
        return NULL;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        return findLCA(root, p, q);
    }
};