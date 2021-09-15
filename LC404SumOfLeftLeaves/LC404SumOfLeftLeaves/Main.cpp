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

int sumLeft(TreeNode* root, bool rightLeaf)
{
    if (root == nullptr)
    {
        return 0;
    }
    if (root->left == nullptr & root->right == nullptr && !rightLeaf)
    {
        return root->val;
    }
    int sum = sumLeft(root->left, 0);
    return sum + sumLeft(root->right, 1);
}

int sumOfLeftLeaves(TreeNode* root) {
    return sumLeft(root, 1);
}

int main()
{
    return 0;
}