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
    public boolean myFunction(TreeNode p,TreeNode q){
        if(p==null || q==null){
            if(p==null && q==null) return true;
            return false;
        }
        if(p.val!=q.val) return false;
        if(!myFunction(p.left,q.left)) return false;
        if(!myFunction(p.right,q.right)) return false;
        return true;
    }
    public boolean isSameTree(TreeNode p, TreeNode q) {
        return myFunction(p,q);
    }
}