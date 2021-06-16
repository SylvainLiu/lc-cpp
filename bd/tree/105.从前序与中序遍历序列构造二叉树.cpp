#include<unordered_map>
#include<vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    unordered_map<int,int> index;

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        for (int i = 0; i < n; ++i) {
            index[inorder[i]] = i;
        }
        return buildTree(preorder, inorder, 0, n - 1, 0, n -1);
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder, int prel, int prer, int inl, int inr) {
        if (prel > prer) {
            return nullptr;
        }

        int preroot = prel;
        int inroot = index[preorder[preroot]];

        TreeNode* root = new TreeNode(preorder[preroot]);
        int leftSize = inroot - inl;

        root->left = buildTree(preorder, inorder, prel + 1, prel + leftSize, inl, inroot - 1);
        root->right = buildTree(preorder, inorder, prel + leftSize + 1, prer, inroot + 1, inr);

        return root;
    }
};