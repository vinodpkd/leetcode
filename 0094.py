#94. Binary Tree Inorder Traversal
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
contents = []
class Solution:
    #contents = []
    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        result = []
        def helper(node):
            if node:
                helper(node.left)
                result.append(node.val)
                helper(node.right)
        helper(root)
        return result
