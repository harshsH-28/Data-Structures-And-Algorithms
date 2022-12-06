class BST {
    BinaryTreeNode<int>* root;
    
    bool search(int data, BinaryTreeNode<int>* node)
    {
        if(node == NULL)
            return false;
        if(node->data == data)
            return true;
        else if(node->data > data)
            return search(data, node->left);
        else
            return search(data, node->right);
    }
    
    void print(BinaryTreeNode<int>* root)
    {
        if(root == NULL)
            return;
        
        cout<<root->data<<":";
        if(root->left != NULL)
            cout<<"L:"<<root->left->data<<",";
        if(root->right != NULL)
            cout<<"R:"<<root->right->data;
        cout<<endl;
        print(root->left);
        print(root->right);
    }
    
    BinaryTreeNode<int>* insert(int data, BinaryTreeNode<int>* node)
    {
        if(node == NULL)
            return new BinaryTreeNode<int>(data);
        
        if(node->data > data)
            node->left = insert(data,node->left);
        else
            node->right = insert(data,node->right);
        
        return node;
    }
    
    BinaryTreeNode<int>* remove(int data, BinaryTreeNode<int>* node)
    {
        if(node == NULL)
            return NULL;
        
        if(node->data > data)
        {
            node->left = remove(data,node->left);
            return node;
        }
        else if(node->data < data)
        {
            node->right = remove(data,node->right);
            return node;
        }
        else
        {
            if(node->left && node->right)
            {
                BinaryTreeNode<int>* minNode = node->right;
				while (minNode->left != NULL) {
					minNode = minNode->left;
				}
				int rightMin = minNode->data;
				node->data = rightMin;
				node->right = remove(rightMin, node->right);
				return node;
            }
            else if(node->left || node->right)
            {
                if(node->left)
                {
                    BinaryTreeNode<int>* ans = node->left;
                    node->left = NULL;
                    delete node;
                    return ans;
                }                    
                else
                {
                    BinaryTreeNode<int>* ans = node->right;
                    node->right = NULL;
                    delete node;
                    return ans;
                }
            }
            else
            {
                delete node;
                return NULL;
            }
        }
    }
   public:
    BST() { 
        root = NULL;
    }
    
    ~BST() {
		delete root;
	}

	/*----------------- Public Functions of BST -----------------*/

    void remove(int data) { 
        root = remove(data,root);
    }

    void print() { 
      	print(root);
    }

    void insert(int data) { 
        this->root = insert(data, this->root);
    }

    bool search(int data) {
        return search(data, root);
    }
};
