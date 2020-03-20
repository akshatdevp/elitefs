/*
 * 
write a program to create a binary tree as shown below with 7 nodes and 
to find the vertical sum of the binary tree.

Sample Input:
1 2 3 4 5 6 7

Sample Output:
4 2 12 3 7 

Explanation:
       1
     /   \
   2      3
  / \    / \
 4   5  6   7
    

The tree has 5 vertical lines
Vertical-Line-1 has only one node 4 => vertical sum is 4
Vertical-Line-2: has only one node 2=> vertical sum is 2
Vertical-Line-3: has three nodes: 1,5,6 => vertical sum is 1+5+6 = 12
Vertical-Line-4: has only one node 3 => vertical sum is 3
Vertical-Line-5: has only one node 7 => vertical sum is 7

So expected OP is 4, 2, 12, 3 and 7





 * 
 */

import java.util.HashMap;
import java.util.Scanner;
import java.util.*; 


//MyBinaryTreeNode Class containing left and right child of current node and data dataue
class MyBinaryTreeNode {

	public int data;
	public MyBinaryTreeNode left;
	public MyBinaryTreeNode right;

	public MyBinaryTreeNode(int data) {
		this.data = data;
		left = null;
		right = null;
	}

	public int getData() {
		return data;
	}

	public void setData(int data) {
		this.data = data;
	}

	public MyBinaryTreeNode getLeft() {
		return left;
	}

	public void setLeft(MyBinaryTreeNode left) {
		this.left = left;
	}

	public MyBinaryTreeNode getRight() {
		return right;
	}

	public void setRight(MyBinaryTreeNode right) {
		this.right = right;
	}

}

class BinaryTree {

	// implemet the following methods
	MyBinaryTreeNode root;
    static SortedMap<Integer,Integer> m= new TreeMap<>();
    static void helper(MyBinaryTreeNode root,int l)
    {
     if(m.containsKey(l))
        m.replace(l,root.data+m.get(l));
        else m.put(l,root.data);
        if(root.left!=null)
        helper(root.left,l-1);
        if(root.right!=null)
        helper(root.right,l+1);
    }
    public static void verticalSum(MyBinaryTreeNode root){
    if(root!=null)
    {
    helper(root,0);
    }
    //Collections.sort(m);
    for(Integer i:m.values())
    System.out.print(i+" ");
    }
	
}

public class VerticalSum {
	/* main program */
	public static void main(String args[]) {
		BinaryTree tree = new BinaryTree();

		Scanner sc = new Scanner(System.in);

		MyBinaryTreeNode root = new MyBinaryTreeNode(sc.nextInt()); 
		tree.root = root;
		tree.root.setLeft(new MyBinaryTreeNode(sc.nextInt())); 
		tree.root.setRight(new MyBinaryTreeNode(sc.nextInt())); 
		tree.root.getLeft().setLeft(new MyBinaryTreeNode(sc.nextInt())); 
		tree.root.getLeft().setRight(new MyBinaryTreeNode(sc.nextInt())); 
		tree.root.getRight().setLeft(new MyBinaryTreeNode(sc.nextInt())); 
		tree.root.getRight().setRight(new MyBinaryTreeNode(sc.nextInt())); 
	        
		tree.verticalSum(tree.root);

	}
}
