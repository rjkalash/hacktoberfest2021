// Java program to construct BST from given preorder
// traversal

// A binary tree node
class Node {

	int data;
	Node left, right;

	Node(int d)
	{
		data = d;
		left = right = null;
	}
}

class Index {

	int index = 0;
}

class BinaryTree {

	Index index = new Index();

	// A recursive function to construct Full from pre[].
	// preIndex is used to keep track of index in pre[].
	Node constructTreeUtil(int pre[], Index preIndex,
						int low, int high, int size)
	{

		// Base case
		if (preIndex.index >= size || low > high) {
			return null;
		}

		// The first node in preorder traversal is root. So
		// take the node at preIndex from pre[] and make it
		// root, and increment preIndex
		Node root = new Node(pre[preIndex.index]);
		preIndex.index = preIndex.index + 1;

		// If the current subarray has only one element, no
		// need to recur
		if (low == high) {
			return root;
		}

		// Search for the first element greater than root
		int i;
		for (i = low; i <= high; ++i) {
			if (pre[i] > root.data) {
				break;
			}
		}

		// Use the index of element found in preorder to
		// divide preorder array in two parts. Left subtree
		// and right subtree
		root.left = constructTreeUtil(
			pre, preIndex, preIndex.index, i - 1, size);
		root.right = constructTreeUtil(pre, preIndex, i,
									high, size);

		return root;
	}

	// The main function to construct BST from given
	// preorder traversal. This function mainly uses
	// constructTreeUtil()
	Node constructTree(int pre[], int size)
	{
		return constructTreeUtil(pre, index, 0, size - 1,
								size);
	}

	// A utility function to print inorder traversal of a
	// Binary Tree
	void printInorder(Node node)
	{
		if (node == null) {
			return;
		}
		printInorder(node.left);
		System.out.print(node.data + " ");
		printInorder(node.right);
	}

	// Driver code
	public static void main(String[] args)
	{
		BinaryTree tree = new BinaryTree();
		int pre[] = new int[] { 10, 5, 1, 7, 40, 50 };
		int size = pre.length;
		Node root = tree.constructTree(pre, size);
		System.out.println(
			"Inorder traversal of the constructed tree is ");
		tree.printInorder(root);
	}
}

// This code has been contributed by Mayank Jaiswal
