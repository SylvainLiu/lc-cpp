#include <vector>
#include <stdio.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class BSTIterator
{
private:
    void inorder(TreeNode* root, vector<int>& res) {
        if (!root) {
            return;
        }
        inorder(root->left, res);
        res.push_back(root->val);
        inorder(root->right, res);
    }

    vector<int> traverse(TreeNode *root) {
        vector<int> res;
        inorder(root, res);
        return res;
    }

    vector<int> arr;
    int idx;
public:
    BSTIterator(TreeNode* root): idx(0), arr(traverse(root)) {};
    int next() { return arr[idx++];}
    bool hasNext() { return arr.size() > idx;}
};

int main(){
    TreeNode* root = new TreeNode(1);
    BSTIterator* obj = new BSTIterator(root);
    int param_1 = obj->next();
    bool param_2 = obj->hasNext();
}