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
        vectorBTree(root->left, v);
        vectorBTree(root->right, v);
        v.push_back(root->val);
    }
}

vector<int> postorderTraversal(TreeNode* root) {
    vector<int> postOrd;
    vectorBTree(root, postOrd);
    return postOrd;
}

int main()
{
    return 0;
}