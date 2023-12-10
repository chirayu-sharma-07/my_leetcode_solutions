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
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> result=new ArrayList<List<Integer>>();
        if(root==null) return result;
        Queue<TreeNode> q=new LinkedList<>();
        q.add(root);
        int count=1;
        while(!(q.isEmpty())){
            List<Integer> sub_result=new ArrayList<Integer>();
            int e=count;
            count=0;
            while(e!=0){
                TreeNode t=q.remove();
                e--;
                sub_result.add(t.val);
                if(t.left!=null){
                    count++;
                    q.add(t.left);
                }
                if(t.right!=null){
                    count++;
                    q.add(t.right);
                }
            }
                result.add(sub_result);
        }
        return result;
    }
}