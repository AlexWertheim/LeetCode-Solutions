#include <iostream>
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

void buildTree(TreeNode* root, vector<int>& elts)
{
    if (root != nullptr)
    {
        buildTree(root->left, elts);
        elts.push_back(root->val);
        buildTree(root->right, elts);
    }
}

int kthSmallest(TreeNode* root, int k) {
    vector<int> elts;
    buildTree(root, elts);
    return elts[k - 1];
}

int main()
{
    return 0;
}