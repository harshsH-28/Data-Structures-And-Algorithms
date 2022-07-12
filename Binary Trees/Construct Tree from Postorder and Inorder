BinaryTreeNode<int>* build(int *po, int *io, int ps, int pe, int is, int ie)
{
    if (is > ie)
        return NULL;
    int rootData = po[pe];
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    int rootIndex = -1;
    for (int i = is; i <= ie; i++)
    {
        if (io[i] == rootData)
        {
            rootIndex = i;
            break;
        }
    }
    int lPS = ps;
    int lIS = is;
    int lIE = rootIndex - 1;
    int lPE = lIE - lIS + lPS;
    int rPS = lPE + 1;
    int rPE = pe - 1;
    int rIS = rootIndex + 1;
    int rIE = ie;
    root->left = build(po, io, lPS, lPE, lIS, lIE);
    root->right = build(po, io, rPS, rPE, rIS, rIE);
    return root;
}

BinaryTreeNode<int>* buildTree(int *postorder, int postLength, int *inorder, int inLength) {
    return build(postorder, inorder, 0, postLength - 1, 0, inLength - 1);
}
