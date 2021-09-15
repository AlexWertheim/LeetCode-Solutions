#include <iostream>

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

bool isEqual(TreeNode* root1, TreeNode* root2)
{
    if (root1 == nullptr && root2 == nullptr)
    {
        return true;
    }
    else if (root1 == nullptr && root2 != nullptr)
    {
        return false;
    }
    else if (root1 != nullptr && root2 == nullptr)
    {
        return false;
    }
    else
    {
        if (root1->val != root2->val)
        {
            return false;
        }
        return(isEqual(root1->left, root2->right) && isEqual(root1->right, root2->left));
    }
}


bool isSymmetric(TreeNode* root) {
    return isEqual(root->left, root->right);
}

int main()
{
	return 0;
}