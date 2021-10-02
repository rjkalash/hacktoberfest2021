# question link : https://www.interviewbit.com/old/problems/construct-binary-tree-from-inorder-and-preorder/ 

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
        def inpo(ino,poo):
            if len(ino)==0:
                return None
            a=poo[0]
            z=ino.index(a)
            root=TreeNode(a)
            root.left=inpo(ino[:z],poo[1:z+1])
            root.right=inpo(ino[z+1:],poo[z+1:])
            return root
        return inpo(B,A)
