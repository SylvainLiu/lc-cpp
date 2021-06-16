#include<limits.h>
#include <algorithm>
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
    int maximum = INT_MIN;

public:
    int maxPathSum (TreeNode* root) {
        maxGain(root);
        return maximum;
    }

    int maxGain(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }

        int left = max(maxGain(node->left), 0);
        int right = max(maxGain(node->right), 0);
        int cur = left + right + node->val;
        maximum = max(maximum, cur);

        return node->val + max(left, right);
    }
};