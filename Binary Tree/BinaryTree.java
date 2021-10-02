/*
Create a binary tree and perform inorder, preorder and postorder
*/
package tree;
import java.util.*;
//IMPORTING ALL THE CLASSES
class TreeNode
{
	TreeNode left,right;
	int data;
	public TreeNode (int d)//parameterized constructor
	{
		left=null;
		right=null;
		data=d;
	}
}
class BinaryTree{     //Binary tree class
	TreeNode root;
	public BinaryTree()//Default constructor
	{
		root=null;
	}
	void create()//Create tree
	{
		Scanner sc= new Scanner(System.in);
		Scanner sn= new Scanner(System.in);
		int ans;
		do {
		
			System.out.println("Enter the data you want to insert in the Binary tree: ");
			int d=sc.nextInt();
			TreeNode temp=new TreeNode(d);
			TreeNode ptr;
			if(root==null) {//If the element is the first element in the tree
				root=temp;
			}
			else {
				ptr=root;
				while(ptr!=null) {
					System.out.println("Enter the direction(l/r): ");
					char dir=sn.nextLine().charAt(0);
					if(dir=='l') {
						if(ptr.left==null) {//If left child is not present then attaching temp as left child
							ptr.left=temp;
							break;
						}
						else {
							ptr=ptr.left;//If left child is present then shifting ptr on it
						}
					}
					else {
						if(ptr.right==null) {//If right child is not present then attaching temp as right child
							ptr.right=temp;
							break;
						}
						else {
							ptr=ptr.right;//If right child is present then shifting ptr on it
						}
					}
			
				}
			}
			System.out.println("Do you want to continue(1/0): ");
			ans =sc.nextInt();
		}while(ans!=0);
	}
	void recursiveInorder(TreeNode lRoot)//Recursive inorder function
	{
		if(lRoot==null) {//Base case
			return;
		}
		recursiveInorder(lRoot.left); //processing inorder of left subtree
		System.out.println(lRoot.data);//Displaying current node data
		recursiveInorder(lRoot.right);//processing inorder of right subtree
	}
	void recursivePreorder(TreeNode lRoot)//Recursive Preorder function
	{
		if(lRoot==null) {//Base case
			return;
		}
		System.out.println(lRoot.data);//Displaying current node data
		recursivePreorder(lRoot.left);//processing Preorder of left subtree
		recursivePreorder(lRoot.right);//processing Preorder of right subtree
	}
	void recursivePostorder(TreeNode lRoot)//Recursive Postorder function
	{
		if(lRoot==null) {//Base case
			return;
		}
	
		recursivePostorder(lRoot.left);//processing Postorder of left subtree
		recursivePostorder(lRoot.right);//processing Postorder of right subtree
		System.out.println(lRoot.data);//Displaying current node data
	}
	void nonrecursiveInorder()//Non Recursive Inorder function
	{
		Stack<TreeNode> st=new Stack<TreeNode>();
		TreeNode ptr=root;
		while(ptr!=null || !st.empty()) {
			while(ptr!=null) {//Traversing till leftmost node
				st.push(ptr);
				ptr=ptr.left;
			}
			if(!st.empty()) {//Pop element from stack and print the data and move to the right child
				ptr=st.pop();
				System.out.println(ptr.data);
				ptr=ptr.right;
			}
		}
	}
	void nonrecursivePreorder()//Non Recursive Preorder function
	{
		Stack<TreeNode> st=new Stack<TreeNode>();
		TreeNode ptr=root;
	
		while(ptr!=null || !st.empty()) {
			while(ptr!=null) {//Traversing and printing data till leftmost node 
				System.out.println(ptr.data);
				st.push(ptr);
				ptr=ptr.left;
			}
			if(!st.empty()) {//Pop element from stack and move to the right child
				ptr=st.pop();
				ptr=ptr.right;
			}
		}
	 
	}
	void nonrecursivePostOrder()//Non recursive post order function
	{
		TreeNode ptr=root;
		if(root==null)
			return ;
		TreeNode pre=null;
		Stack<TreeNode> s = new Stack();      
		while(ptr!=null || !s.empty()){
			if(ptr!=null){				//Traversing till leftmost node
				s.push(ptr);
				ptr = ptr.left;
			}
			else{
				ptr = s.peek();
				if(ptr.right==null || ptr.right==pre){//Checking if the node do not have right child or if the right child is already  processed
					System.out.println(ptr.data);
					s.pop();
					pre=ptr;
					ptr = null;
				}
				else
					ptr = ptr.right;//Moving ptr to the right child 
			}
		}
	}
/********************************EXTRA*************************************************/
	void displayTree(TreeNode lroot) //function to Display Binary tree
	{
		if(lroot==null)//Base case
			return;
		System.out.print(lroot.data + " : ");//Displaying data of the current node
		if(lroot.left!=null)
			System.out.print("L " + lroot.left.data);//Displaying left child of the current node if present
		if(lroot.right!=null)
			System.out.print("   R " + lroot.right.data);//Displaying right child of the current node if present
		System.out.println(" ");
		displayTree(lroot.left);//Recursive call on left subtree
		displayTree(lroot.right);//Recursive call on right subtree
	}
	int count(TreeNode lroot)//Function to count no of nodes in the tree
	{
		if(lroot==null) {//Base Case
			return 0;
		}
		int ct=1+count(lroot.left)+count(lroot.right);//Recursive call
		return ct;
	}
}
public class Mainclass {//Main class
	public static void main(String[] args) {
		int ch;
		BinaryTree b=new BinaryTree();
		Scanner sc=new Scanner(System.in);
		do
		{
			System.out.println("**************************************");
			System.out.println("MENU: \n\n1.Create a Binary Tree \n2.Display the recursive Inorder \n3.Display the non recursive Inorder \n4.Display the non recursive Preorder\n5.Display the non Recursive Postorder \n6.Display the recursive Preorder \n7.Display the recursive Postorder\n8. Display Tree\n9.Count no of Nodes");
			System.out.println("\n*************************************");
			System.out.println("\nEnter your choice: ");
			ch=sc.nextInt();
			switch(ch)//Switch case
			{
			case 1:
					b.create();//call create();
					break;
			case 2:

					System.out.println("\nThe Recursive Inorder is: ");
					b.recursiveInorder(b.root);//callInOrder();
					break;
			case 3:
					System.out.println("\nThe Non Recursive Inorder is: ");
					b.nonrecursiveInorder();//nonrecursiveInorder();
					break;
			case 4:
					System.out.println("\nThe Non Recursive Preorder is: ");
					b.nonrecursivePreorder();//nonrecursivePreorder();
					break;
			case 5:
					System.out.println("\nThe Non Recursive Postorder is: ");
					b.nonrecursivePostOrder();//nonrecursivePostOrder();
					break;
			case 6:
					System.out.println("\nThe Recursive Preorder is: ");
					b.recursivePreorder(b.root);//callPreOrder();
					break;
			case 7:
					System.out.println("\nThe Recursive Postorder is: ");
					b.recursivePostorder(b.root);//callPostOrder();
					break;
			case 8:
					System.out.println("\nThe Binary Tree  is: ");
					b.displayTree(b.root);//callPostOrder();
					break;
			case 9:
					System.out.println("\nThe number of nodes in the tree are: "+ b.count(b.root));//callPostOrder();
					break;

		}
		System.out.println("Do you want to continue ,1 to continue,0 to exit: ");
		ch=sc.nextInt();
	}
	while (ch==1);
	}
}
/* TIME COMPLEXITIES
 * Create: O(n)
 * Recursive Inorder,Preorder,Postorder: O(n)
 * Non Recursive Inorder,Preorder,Postorder: O(n)
 * Display Tree:O(n)
 * Count: O(n)
 * 
 * Output
 * **************************************
MENU: 

1.Create a Binary Tree 
2.Display the recursive Inorder 
3.Display the non recursive Inorder 
4.Display the non recursive Preorder
5.Display the non Recursive Postorder 
6.Display the recursive Preorder 
7.Display the recursive Postorder
8. Display Tree
9.Count no of Nodes

*************************************

Enter your choice: 
1
Enter the data you want to insert in the Binary tree: 
13
Do you want to continue(1/0): 
1
Enter the data you want to insert in the Binary tree: 
8
Enter the direction(l/r): 
l
Do you want to continue(1/0): 
1
Enter the data you want to insert in the Binary tree: 
15
Enter the direction(l/r): 
r
Do you want to continue(1/0): 
1
Enter the data you want to insert in the Binary tree: 
14
Enter the direction(l/r): 
r
Enter the direction(l/r): 
l
Do you want to continue(1/0): 
1
Enter the data you want to insert in the Binary tree: 
19
Enter the direction(l/r): 
r
Enter the direction(l/r): 
r
Do you want to continue(1/0): 
1
Enter the data you want to insert in the Binary tree: 
7
Enter the direction(l/r): 
l
Enter the direction(l/r): 
l
Do you want to continue(1/0): 
1
Enter the data you want to insert in the Binary tree: 
10
Enter the direction(l/r): 
l
Enter the direction(l/r): 
r
Do you want to continue(1/0): 
1
Enter the data you want to insert in the Binary tree: 
4
Enter the direction(l/r): 
l
Enter the direction(l/r): 
l
Enter the direction(l/r): 
l
Do you want to continue(1/0): 
0
Do you want to continue ,1 to continue,0 to exit: 
1
**************************************
MENU: 

1.Create a Binary Tree 
2.Display the recursive Inorder 
3.Display the non recursive Inorder 
4.Display the non recursive Preorder
5.Display the non Recursive Postorder 
6.Display the recursive Preorder 
7.Display the recursive Postorder
8. Display Tree
9.Count no of Nodes

*************************************

Enter your choice: 
8

The Binary Tree  is: 
13 : L 8   R 15 
8 : L 7   R 10 
7 : L 4 
4 :  
10 :  
15 : L 14   R 19 
14 :  
19 :  
Do you want to continue ,1 to continue,0 to exit: 
1
**************************************
MENU: 

1.Create a Binary Tree 
2.Display the recursive Inorder 
3.Display the non recursive Inorder 
4.Display the non recursive Preorder
5.Display the non Recursive Postorder 
6.Display the recursive Preorder 
7.Display the recursive Postorder
8. Display Tree
9.Count no of Nodes

*************************************

Enter your choice: 
2

The Recursive Inorder is: 
4
7
8
10
13
14
15
19
Do you want to continue ,1 to continue,0 to exit: 
1
**************************************
MENU: 

1.Create a Binary Tree 
2.Display the recursive Inorder 
3.Display the non recursive Inorder 
4.Display the non recursive Preorder
5.Display the non Recursive Postorder 
6.Display the recursive Preorder 
7.Display the recursive Postorder
8. Display Tree
9.Count no of Nodes

*************************************

Enter your choice: 
3

The Non Recursive Inorder is: 
4
7
8
10
13
14
15
19
Do you want to continue ,1 to continue,0 to exit: 
1
**************************************
MENU: 

1.Create a Binary Tree 
2.Display the recursive Inorder 
3.Display the non recursive Inorder 
4.Display the non recursive Preorder
5.Display the non Recursive Postorder 
6.Display the recursive Preorder 
7.Display the recursive Postorder
8. Display Tree
9.Count no of Nodes

*************************************

Enter your choice: 
4

The Non Recursive Preorder is: 
13
8
7
4
10
15
14
19
Do you want to continue ,1 to continue,0 to exit: 
1
**************************************
MENU: 

1.Create a Binary Tree 
2.Display the recursive Inorder 
3.Display the non recursive Inorder 
4.Display the non recursive Preorder
5.Display the non Recursive Postorder 
6.Display the recursive Preorder 
7.Display the recursive Postorder
8. Display Tree
9.Count no of Nodes

*************************************

Enter your choice: 
6

The Recursive Preorder is: 
13
8
7
4
10
15
14
19
Do you want to continue ,1 to continue,0 to exit: 
1
**************************************
MENU: 

1.Create a Binary Tree 
2.Display the recursive Inorder 
3.Display the non recursive Inorder 
4.Display the non recursive Preorder
5.Display the non Recursive Postorder 
6.Display the recursive Preorder 
7.Display the recursive Postorder
8. Display Tree
9.Count no of Nodes

*************************************

Enter your choice: 
5

The Non Recursive Postorder is: 
4
7
10
8
14
19
15
13
Do you want to continue ,1 to continue,0 to exit: 
1
**************************************
MENU: 

1.Create a Binary Tree 
2.Display the recursive Inorder 
3.Display the non recursive Inorder 
4.Display the non recursive Preorder
5.Display the non Recursive Postorder 
6.Display the recursive Preorder 
7.Display the recursive Postorder
8. Display Tree
9.Count no of Nodes

*************************************

Enter your choice: 
7

The Recursive Postorder is: 
4
7
10
8
14
19
15
13
Do you want to continue ,1 to continue,0 to exit: 
1
**************************************
MENU: 

1.Create a Binary Tree 
2.Display the recursive Inorder 
3.Display the non recursive Inorder 
4.Display the non recursive Preorder
5.Display the non Recursive Postorder 
6.Display the recursive Preorder 
7.Display the recursive Postorder
8. Display Tree
9.Count no of Nodes

*************************************

Enter your choice: 
9

The number of nodes in the tree are: 8
Do you want to continue ,1 to continue,0 to exit: 
0

 */
