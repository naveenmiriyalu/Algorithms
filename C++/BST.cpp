/* Implementation of Binary Search Tree */
//Author: Naveen M
//Date:   Nov 3-2014
// Similar to Allen Weiss Code

/* API 
insert(x)
inorder()
*/

#include<iostream>

template<typename Comparable>
class BinarySearchTree {
   public:
   BinarySearchTree(){
     root = NULL;
   }

   void insert (const Comparable& x){
   	insert(x,root);
   }

   void inorder(){
     if ( root == NULL ){
	  std::cout << "Tree is empty " << std::endl;
	 }
	 std::cout << "/* Inorder traversal */ " << std::endl; 
     inorder(root);
	 std::cout << std::endl;
	 std::cout << "/* End */ " << std::endl; 
   }

   private:
   // Declarations
    struct BinaryNode {
   	Comparable element;
	BinaryNode* left;
	BinaryNode* right;
	
	BinaryNode(const Comparable &x= Comparable(),BinaryNode *lt = NULL,BinaryNode* rt=NULL):element(x),left(lt),right(rt){}
   } ;

   // Member functions 
   void insert(const Comparable& x,BinaryNode* &t)
   {
     if( t == NULL )
	 	t = new BinaryNode(x,NULL,NULL);
	 else if ( x < t->element)
	    insert(x,t->left);
	 else if (x > t->element)
	    insert(x,t->right);
	 else
	 ;
   
   }

   void inorder(BinaryNode* t)
   {
      if( t== NULL)
	    return;
	  inorder(t->left);
	  std::cout << t->element << " ";
	  inorder(t->right);
   }
     
   // Members
   BinaryNode* root;//pointer to the root 
};

int main()
{
   BinarySearchTree<int> BST;
   BST.insert(6);
   BST.insert(5);
   BST.insert(7);
   BST.inorder();
}

