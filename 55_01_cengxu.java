import java.util.*;
import structure.TreeNode;

//层序遍历的方式，用一个队列
public class TreeDepth_cengxu{
    
    public static int treeDepth(TreeNode<Integer> root){
        if(root == null)
            return 0;
        Queue<TreeNode<Integer> > queue = new LinkedList<>();
        queue.offer(root);

        int depth = 0;

        while(!queue.isEmpty()){
            int size = queue.size();
            TreeNode<Integer> cur = null;
            for(int i = 0;i<size;++i){
                cur = queue.poll();
                if(cur.left!=null)
                    queue.offer(cur.left);
                if(cur.right!=null)
                    queue.offer(cur.right);
            }
            depth++;
        }
        return depth;

    }

}
