/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int val=0, TreeNode left=null, TreeNode right=null) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
public class Solution {
    public IList<IList<int>> LevelOrder(TreeNode root) {
        IList<IList<int>> output = new List<IList<int>>();
        
        Queue<TreeNode> q = new Queue<TreeNode>();
        
        if(root != null)
            q.Enqueue(root);
        
        while(q.Count != 0){
            int n = q.Count;
            output.Add(new List<int>(n));
            for(int i = 0;i < n;i++){
                TreeNode node = q.Dequeue();
                output[output.Count - 1].Add(node.val);
                if(node.left != null)
                    q.Enqueue(node.left);
                if(node.right != null)
                    q.Enqueue(node.right);
            }
        }
        
        return output;
    }
}