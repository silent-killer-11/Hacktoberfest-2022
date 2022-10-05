class Solution:
    def invertTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        if root==None:
            return None
        temp = root.left
        root.left = root.right
        root.right = temp
        self.invertTree(root.left) 
        self.invertTree(root.right)
        return root
