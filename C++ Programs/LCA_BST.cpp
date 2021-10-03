#include <bits/stdc++.h>
using namespace std;

// Data structure to store a Binary Search Tree node
struct Node
{
	int data;
	Node *left, *right;
};

// Function to create a new binary tree node having given key
Node* newNode(int key)
{
	Node* node = new Node;
	node->data = key;
	node->left = node->right = NULL;

	return node;
}

// Function to perform inorder traversal of the tree
void inorder(Node* root)
{
	if (root == NULL)
		return;

	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
}

// Recursive function to insert a key into BST
Node* insert(Node* root, int key)
{
	// if the root is null, create a new node and return it
	if (root == NULL)
		return newNode(key);
		
	if (key == root->data) 
    { 
        return root; 
    } 

	// if given key is less than the root node, recur for left subtree
	if (key < root->data)
		root->left = insert(root->left, key);

	// if given key is more than the root node, recur for right subtree
	else
		root->right = insert(root->right, key);

	return root;
}

int max(Node* root) {
    if(root->right == NULL){
      return root->data;
    } else {
      return max(root->right);
    }
  }


Node *remove(Node* root, int data) {
    if (root == NULL) {
      return NULL;
    }

    if (data > root->data) {
      root->right = remove(root->right, data);
      return root;
    } else if (data < root->data) {
      root->left = remove(root->left, data);
      return root;
    } else {
      if(root->left == NULL && root->right == NULL){
        return NULL;
      } else if(root->left == NULL){
        return root->right;
      } else if(root->right == NULL){
        return root->left;
      } else {
        int m = max(root->left);
        root->data = m;
        root->left = remove(root->left, m);
        return root;
      }
    }
  }
  
static int sum=0;
void *rwsp(Node *root)
{
    if (root == NULL) 
    {
      return NULL;
    }
    rwsp(root->right);
    
    int od = root->data;
    root->data = sum;
    sum+=od;
    
    rwsp(root->left);
}

int lca(Node* root,int d1,int d2)
{
    
    if(root->data>d1 && root->data>d2)
    return lca(root->left,d1,d2);
    
    else if(root->data<d1 && root->data<d2)
    return lca(root->right,d1,d2);
    
    else
    return root->data;
}

void traversalInOrder(Node *root)
{
    if(root != NULL)
    {
    string str = "";
    str += (root->left) == NULL ? "." : to_string(root->left->data) + "";
    str += " <- " + to_string(root->data) + " -> ";
    str += (root->right) == NULL ? "." : to_string(root->right->data) + "";
    cout<<str<<endl;

    traversalInOrder(root->left);
    traversalInOrder(root->right);
    }
}

int main()
{
	Node* root = NULL;
	int n;cin>>n;
	for(int i=0;i<n;i++)
    {
         string a;
        cin>>a;
        
        if(a!="n")
        {
            int w=stoi(a);
           
    root = insert(root,w);
        }
    }
    int d1,d2;cin>>d1>>d2;
    
    int lc = lca(root,d1,d2);
    cout<<lc<<endl;
  
	return 0;
}
