# Given the root of a Binary Search Tree (BST), return the minimum absolute difference between the values of any two different nodes in the tree.
'''
Example 
        4
      /   \
    2       6
   / \
  1   3

  Output = 1

'''

def getMinimumDifference(self,root):
       
    self.tree = []
    def helper(root):
        if root is None:
            return
        helper(root.left)
        self.tree.append(root.val)
        helper(root.right)
       
    helper(root)
    min_diff = -999999
    n = len(self.tree)
    for i in range(n-1):
        diff = (abs(self.tree[i+1]-self.tree[i]))
        min_diff = min(min_diff,diff)
            
             
        
    return min_diff
