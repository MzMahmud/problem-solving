/*
// Definition for a Node.
public class Node {
    public int val;
    public IList<Node> children;

    public Node() {}

    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, IList<Node> _children) {
        val = _val;
        children = _children;
    }
}
*/

public class Solution {
    public IList<IList<int>> LevelOrder(Node root) {
        IList<IList<int>> output = new List<IList<int>>();
        
        Queue<Node> q = new Queue<Node>(); 
        if(root != null)
            q.Enqueue(root);
        
        while(q.Count != 0){
            int n = q.Count;
            output.Add(new List<int>(n));
            for(int i = 0;i < n;i++){
                Node node = q.Dequeue();
                output[output.Count - 1].Add(node.val);
                foreach(Node child in node.children){
                    q.Enqueue(child);
                }
            }
        }
        return output;
    }
}