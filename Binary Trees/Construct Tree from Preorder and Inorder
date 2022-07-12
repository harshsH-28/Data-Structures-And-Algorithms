// My Way Solution

BinaryTreeNode<int>* buildTree(int *preorder, int preLength, int *inorder, int inLength) {
    int rootData = preorder[0];
    BinaryTreeNode<int> *root = new BinaryTreeNode<int> (rootData);

    if (preLength == 1)
        return root;
    else if (preLength == 0)
        return NULL;
    else
    {
        int leftInEnd;
        int rightInStart;
        int leftPreStart = 1;
        int leftInStart = 0;
        for (int i = 0; i < inLength; i++)
        {
            if (inorder[i] == rootData)
            {
                leftInEnd = i - 1;
                rightInStart = i + 1;
            }
        }
        int leftPreEnd = leftInEnd - leftInStart + leftPreStart;
        int leftLength = leftPreEnd - leftPreStart + 1;
        int rightPreStart = leftPreEnd + 1;
        int rightPreEnd = preLength - 1;
        int rightLength = rightPreEnd - rightPreStart + 1;
        BinaryTreeNode<int>* left = buildTree(preorder + 1, leftLength, inorder, leftLength);
        BinaryTreeNode<int>* right = buildTree(preorder + rightPreStart, rightLength, inorder + rightInStart, rightLength);
        root->left = left;
        root->right = right;
        return root;
    }
}

// Leetcode Solution

TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int ps, int pe, int is, int ie)
    {
        if (is > ie)
            return NULL;
        int rootData = preorder[ps];
        TreeNode* root = new TreeNode(rootData);
        int rootIndex = -1;
        for (int i = is; i <= ie; i++)
        {
            if (inorder[i] == rootData)
            {
                rootIndex = i;
                break;
            }
        }
        int lPS = ps + 1;
        int lIS = is;
        int lIE = rootIndex - 1;
        int lPE = lIE - lIS + lPS;
        int rPS = lPE + 1;
        int rPE = pe;
        int rIS = rootIndex + 1;
        int rIE = ie;
        root->left = helper(preorder, inorder, lPS, lPE, lIS, lIE);
        root->right = helper(preorder, inorder, rPS, rPE, rIS, rIE);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int size = preorder.size();
        return helper(preorder, inorder, 0, size - 1, 0, size - 1);
    }
