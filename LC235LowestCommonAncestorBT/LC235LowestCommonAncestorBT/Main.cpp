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

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    int minim = min(p->val, q->val);
    int maxim = max(p->val, q->val);
    if (root->val >= minim && root->val <= maxim)
    {
        return root;
    }
    else if (root->val > minim && root->val > maxim)
    {
        return lowestCommonAncestor(root->left, p, q);
    }
    else
    {
        return lowestCommonAncestor(root->right, p, q);
    }
}

int main()
{
    return 0;
}