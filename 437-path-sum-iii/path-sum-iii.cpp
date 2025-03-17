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
    void findPathSum(TreeNode* root, int& targetSum, int& cnt, map<long long, long long> m, long long sum){
        if(root == NULL){
            return;
        }

        sum += root->val;
        cout << sum << endl;
        if(m.find(sum - targetSum) != m.end()){
            cout << m[sum - targetSum] << endl;
            cnt += m[sum - targetSum];
        }
        m[sum] += 1;
        findPathSum(root->left, targetSum, cnt, m, sum);
        findPathSum(root->right, targetSum, cnt, m, sum);
        return;
    }
    int pathSum(TreeNode* root, int targetSum) {

        map<long long, long long> m;
        m[0] = 1;
        int sum = 0, cnt = 0;
        findPathSum(root, targetSum, cnt, m, sum);

        return cnt;
    }
};