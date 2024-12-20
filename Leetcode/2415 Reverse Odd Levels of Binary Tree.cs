public class Solution
{
    public TreeNode? ReverseOddLevels(TreeNode root)
    {
        List<TreeNode> q = [root];
        bool reverse = false;
        while (q.Count > 0)
        {
            List<TreeNode> newQ = [];
            foreach (var node in q)
            {
                if (node.left != null) newQ.Add(node.left);
                if (node.right != null) newQ.Add(node.right);
            }
            if (reverse)
            {
                for (int i = 0, j = q.Count - 1; i < j; i++, j--)
                {
                    (q[i].val, q[j].val) = (q[j].val, q[i].val);
                }
            }
            q = newQ;
            reverse = !reverse;
        }
        return root;
    }
}
