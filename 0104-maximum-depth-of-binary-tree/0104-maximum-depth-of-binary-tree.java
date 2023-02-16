/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public static int myFunction(TreeNode treeNode){
        if(treeNode==null) return 0;
        return Math.max(myFunction(treeNode.left),myFunction(treeNode.right))+1;
    }
    public int maxDepth(TreeNode root) {
        return myFunction(root);
    }
}