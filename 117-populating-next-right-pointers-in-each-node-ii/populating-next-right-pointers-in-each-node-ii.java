class Solution {
    public Node connect(Node root) {
        dfs(root);
        return root;
    }
    
    public void dfs(Node root){
        if(root == null) return;
        if(root.right != null){
            if(root.left != null) root.left.next = root.right;
            root.right.next = find_next(root.next);
        }else if(root.left != null) root.left.next = find_next(root.next);
        
        dfs(root.right); // right side first
        dfs(root.left);
        
    }

    
    public Node find_next(Node next){
        while(next != null){
            if(next.left != null) return next.left;
            if(next.right != null) return next.right;
            next = next.next;
        }
        return null;
    }
    
}