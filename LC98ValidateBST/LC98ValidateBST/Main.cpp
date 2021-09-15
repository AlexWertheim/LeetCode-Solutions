#include <iostream>
#include <stack>

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

void bstStack(TreeNode* root, stack<int>& b)
{
    if (root != nullptr)
    {
        bstStack(root->left, b);
        b.push(root->val);
        bstStack(root->right, b);
    }
}

bool isValidBST(TreeNode* root) {
    stack<int> b;
    bstStack(root, b);
    int top = b.top();
    b.pop();
    while (!b.empty())
    {
        if (top <= b.top())
        {
            return false;
        }
        top = b.top();
        b.pop();
    }
    return true;
}

int main()
{
    return 0;
}