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
    TreeNode* recover(string& traversal, int& ind, int depth){

        if(ind >= traversal.length()){
            return NULL;
        }

        int dash = 0;
        while(ind+dash < traversal.length() && traversal[ind+dash] == '-'){
            dash++;
        }
        if(dash != depth){
            return NULL;
        }
        ind += dash;
        
        int val = 0;
        while(ind < traversal.length() && isdigit(traversal[ind])){
            val = val*10 + (traversal[ind] - '0');
            ind++;
        }

        TreeNode* node = new TreeNode(val);

        node->left = recover(traversal, ind, depth+1);
        node->right = recover(traversal, ind, depth+1);

        return node;
    }
    TreeNode* recoverFromPreorder(string traversal) {
        int ind = 0;
        return recover(traversal, ind, 0);
    }
};