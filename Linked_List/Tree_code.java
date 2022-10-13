import java.util.*;
import java.io.*;
class BinaryTree{
    Scanner sc=new Scanner(System.in);
    public Node buildTree(){
        int n=sc.nextInt();
        if(n==-1){
            return null;
        }
        Node root=new Node(n);
        root.left=buildTree();
        root.right=buildTree();
        return root;
    }
    public void inOrder(Node root){
        if(root==null){
            return;
        }
        inOrder(root.left);
        System.out.println(root.data);
        inOrder(root.right);
    }
    public void preOrder(Node root){
        if(root==null){
            return;
        }
        System.out.println(root.data);
        preOrder(root.left);
        preOrder(root.right);
    }
    public void postOrder(Node root){
        if(root==null){
            return;
        }
        postOrder(root.left);
        postOrder(root.right);
        System.out.println(root.data);
    }
    public int height(Node root){
        if(root==null){
            return 0;
        }
        int leftHeight=height(root.left);
        int rightHeight=height(root.right);
        return 1+Math.max(leftHeight, rightHeight);
    }
    public boolean search(Node root, int data){
        if(root==null){
            return false;
        }
        if(root.data==data){
            return true;
        }
        boolean leftSearch=search(root.left, data);
        boolean rightSearch=search(root.right, data);
        return (leftSearch || rightSearch);
    }
    
    static void top(Node root, Map<Integer, Pair> m,int level ,int maxWidth){
        if(root==null){
            return;
        }
        if(m.containsKey(maxWidth) && level<m.get(maxWidth).level){
            Pair p=new Pair(level,root.data);
            m.put(maxWidth,p);
        }
        else{
            Pair p=new Pair(level, root.data);
            m.putIfAbsent(maxWidth, p);
        }
        top(root.left, m,level+1 ,maxWidth-1);
        top(root.right, m,level+1 ,maxWidth+1);

    }

    static ArrayList<Integer> topView(Node root)
    {
        
        Map<Integer, Pair> m=new TreeMap<>();
        top(root, m,0, 0);
        ArrayList<Integer> ans=new ArrayList<>();
        for(java.util.Map.Entry<Integer, Pair> entry: m.entrySet()){
            ans.add(entry.getValue().data);
        }
        return ans;
        
    }
    static void bottom(Node root, Map<Integer, Pair> m,int level ,int maxWidth){
        if(root==null){
            return;
        }
        if(!m.containsKey(maxWidth) || level>=m.get(maxWidth).level){
            Pair p=new Pair(level,root.data);
            m.put(maxWidth,p);
        }
        
        bottom(root.left, m,level+1 ,maxWidth-1);
        bottom(root.right, m,level+1 ,maxWidth+1);

    }
    static ArrayList<Integer> bottomView(Node root){
        Map<Integer, Pair> m=new TreeMap<>();
        bottom(root, m,0, 0);
        ArrayList<Integer> ans=new ArrayList<>();
        for(java.util.Map.Entry<Integer, Pair> entry: m.entrySet()){
            ans.add(entry.getValue().data);
        }
        return ans;
    }
    static int maxLevel=0;
    static void leftView(Node root, int level){
        if(root==null){
            return;
        }
        if(level>= maxLevel){
            System.out.println(root.data);
            maxLevel+=1;
        }
        leftView(root.left, level+1);
        leftView(root.right, level+1);

    }
    static int max1=0;
    static void rightView(Node root, int level){
        
        if(root==null){
            return;
        }
        if(level>=max1){
            System.out.println(root.data);
            max1+=1;
        }
        rightView(root.right, level+1);
        rightView(root.left, level+1);
    }
    static void levelOrderTraversal(Node root, int level, Map<Integer, List<Integer>> m){
        if(root==null){
            return;
        }
        if(m.containsKey(level)){
            m.get(level).add(root.data);
        }else{
            m.put(level , new ArrayList<Integer>());
            m.get(level).add(root.data);
        }
        levelOrderTraversal(root.left, level+1, m);
        levelOrderTraversal(root.right, level+1, m);
    }
    static List<List<Integer>> levelOrder(Node root){
        Map<Integer, List<Integer>> m=new HashMap<>();
        List<List<Integer>> al=new ArrayList<>();
        levelOrderTraversal(root, 0, m);
        for(List<Integer> ll: m.values()){
            al.add(new ArrayList<Integer>(ll));
        }
        return al;
    }
}
class trees{

    public static void main(String[] args) {
        BinaryTree bt=new BinaryTree();
        Node root=bt.buildTree();
        System.out.println(" ");
         
        List<List<Integer>> al= bt.levelOrder(root);
        System.out.println(al);
    }
}
class Node{
    int data;
    Node left;
    Node right;
    public Node(int data){
        this.data=data;
        this.left=null;
        this.right=null;
    }
}
class Pair{
    int level;
    int data;
    public Pair(int level, int data){
        this.level=level;
        this.data=data;
    }
}
