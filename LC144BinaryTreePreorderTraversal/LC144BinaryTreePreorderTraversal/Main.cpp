#include<iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

void vectorBTree(TreeNode* root, vector<int>& v)
{
    if (root != nullptr)
    {
        v.push_back(root->val);
        vectorBTree(root->left, v);
        vectorBTree(root->right, v);
    }
}

vector<int> preorderTraversal(TreeNode* root) {
    vector<int> preOrd;
    vectorBTree(root, preOrd);
    return preOrd;
}

int main()
{
    return 0;
}