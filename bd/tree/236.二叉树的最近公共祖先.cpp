
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* ans;

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root, p, q);
        return ans;
    }

    bool dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) {
            return false;
        }
        bool cur = root == p || root == q;
        bool l = dfs(root->left, p, q);
        bool r = dfs(root->right, p, q);

        if ((l && r) || (cur && (l || r))) {
            ans = root;
        }
        return l || r || cur;
    }
};