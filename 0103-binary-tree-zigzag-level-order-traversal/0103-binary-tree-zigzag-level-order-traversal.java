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
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        List<List<Integer>> result=new LinkedList();
        if(root==null) return result;
        Queue<TreeNode> queue=new LinkedList();
        int level=1;
        queue.add(root);
        while(!(queue.isEmpty())){
            List<Integer> list=new ArrayList();
            int g=queue.size();
            for(int e=0;e<g;e++){
                TreeNode node=queue.poll();
                list.add(node.val);
                if(node.left!=null) queue.add(node.left);
                if(node.right!=null) queue.add(node.right);
            }
            if(level%2==0){
                List<Integer> list1=new ArrayList();
                for(int f=list.size()-1;f>=0;f--) list1.add(list.get(f));
                result.add(list1);
            }else result.add(list);
            level++;
        }
        return result;
    }
}