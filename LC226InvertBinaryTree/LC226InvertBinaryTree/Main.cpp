#include<iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

void swapNodes(TreeNode* root)
{
    if (root != nullptr)
    {
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;
        swapNodes(root->left);
        swapNodes(root->right);
    }
}

TreeNode* invertTree(TreeNode* root) {
    swapNodes(root);
    return root;
}

int main()
{
    return 0;
}