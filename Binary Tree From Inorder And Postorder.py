# question link: https://www.interviewbit.com/old/problems/binary-tree-from-inorder-and-postorder/

# Definition for a  binary tree node
# class TreeNode:
#    def _init_(self, x):
#        self.val = x
#        self.left = None
#        self.right = None

class Solution:
    # @param A : list of integers
    # @param B : list of integers
    # @return the root node in the tree
    def buildTree(self, A, B):
        def inpoo(ino,poo):
            if len(ino)==0:
                return None
            a=poo[-1]
            z=ino.index(a)
            root=TreeNode(a)
            root.left=inpoo(ino[:z],poo[:z])
            root.right=inpoo(ino[z+1:],poo[z:-1])
            return root
            
        return inpoo(A,B)
