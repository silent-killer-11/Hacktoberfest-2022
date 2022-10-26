// 100% WORKING CODE
// gfg sol
// submit on gfg


//  RRRRRR - learn the logic



/*

Given two Binary Trees. Check whether they are Isomorphic or not.

Note: 
Two trees are called isomorphic if one can be obtained from another by a series of flips, i.e. by swapping left and right children of 
several nodes. Any number of nodes at any level can have their children swapped. Two empty trees are isomorphic.


Sol:
We simultaneously traverse both trees. Let the current nodes of two trees being traversed be n1 and n2 respectively. There are following 
two conditions for subtrees rooted with n1 and n2 to be isomorphic:
1) Data of n1 and n2 is same. 
2) One of the following two is true for children of n1 and n2:
    a) Left child of n1 is isomorphic to left child of n2 and right child of n1 is isomorphic to right child of n2. 
    b) Left child of n1 is isomorphic to right child of n2 and right child of n1 is isomorphic to left child of n2.



*/




bool isIsomorphic(node* root1, node* root2){

    // Both roots are NULL, trees isomorphic by definition
    if(root1 == NULL && root2 == NULL){
        return true;
    }

    // Exactly one of the root1 and root2 is NULL, trees not isomorphic
    if(root1 == NULL || root2 == NULL){
        return false;
    }

    if(root1->data != root2->data){
        return false;
    }

    // There are two possible cases for root1 and root2 to be isomorphic
    // Case 1: The subtrees rooted at these nodes have NOT been "Flipped".
    // Both of these subtrees have to be isomorphic, hence the &&
    // Case 2: The subtrees rooted at these nodes have been "Flipped"
    return
    (isIsomorphic(root1->left,root2->left) && isIsomorphic(root1->right,root2->right))||
    (isIsomorphic(root1->left,root2->right) && isIsomorphic(root1->right,root2->left));
    
}
 