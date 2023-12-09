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
    public List<Integer> inorderTraversal(TreeNode root) {
        List<Integer> result=new ArrayList<Integer>();
        if(root==null){
            return result;
        }
        Stack<TreeNode> stk=new Stack<TreeNode>();
        TreeNode e=null;
        TreeNode f=null;
        for(e=root;e!=null;e=e.left) stk.push(e);
        while(!stk.empty()){
            f=stk.pop();
            result.add(f.val);
            if(f.right!=null){
                for(e=f.right;e!=null;e=e.left) stk.push(e);
            }
        }
        return result;
    }
}