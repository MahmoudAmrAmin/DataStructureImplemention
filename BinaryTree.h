//
// Created by mahmod on 12/19/2023.
//

#ifndef DATASTRUCTURES_IMPLEMENT_BINARYTREE_H
#define DATASTRUCTURES_IMPLEMENT_BINARYTREE_H
#include<iostream>
using namespace std ;

template<class t>class node
{
public:
    t item ;
    node * right ,*left ;
    node(t item);
};

template<class t>class Binary_Tree
{
private:
    node<t> * tree;
public:
    Binary_Tree();
    ~Binary_Tree();
    node<t>* get_tree();
    void free_BST(node<t>*);
    void insert(node<t>* n  , t element);
    bool is_leaf(node<t>*n);
    void preorder_traversal(node<t>*n);
    void inorder_traversal(node<t>*n);
    void postorder_traversal(node<t>*n);
    void search(t element);
    bool delete_node(t element);
    bool empty();

};
// binary search  methods
template<class t> bool Binary_Tree<t>::is_leaf(node<t> *n)
{
    return n->right == NULL && n->left == NULL;
}
template<class t> void Binary_Tree<t>::search(t element)
{
    node<t> * parent =tree;node<t> *temp =tree;
    string path ="";
    if(empty()){cout<<"tree is empty "<<endl;return;}
    else
    {
        path +="root" ;
        while( temp != NULL && temp ->item != element)
        {
            //parent = temp;
            if(element > temp -> item)
            {
                if(temp ->right != NULL ) {
                    temp = temp->right;
                    path +=" ->right path";
                }
            }
            else
            {
                if(temp -> left != NULL)
                {
                    temp = temp ->left;
                    path += " -> leftPath";
                }
            }
        }
        if(temp == NULL){cout<<"element not found"<<endl;}
        else {cout<<path<<endl;}
    }
}
template<class t>void Binary_Tree<t>::free_BST(node<t> *n)
{
    if(empty()){ return;}
    free_BST(n ->left);
    free_BST(n ->right);
    delete n;
}
template<class t> Binary_Tree<t>::Binary_Tree()
{
    tree = NULL ;
}
template<class t> Binary_Tree<t>::~Binary_Tree()
{
    free_BST(tree);
}
template<class t> bool Binary_Tree<t>::empty()
{
    return tree == NULL ;
}

template<class t> void Binary_Tree<t>::insert(node<t> *n, t element)
{
    if(empty())
    {
        tree = new node(element);
        return ;
    }
    if(n->item == element){cout<<"already in tree"<<endl;return;}
    if(n != NULL)
    {
        if(element > n->item)
        {
            if(n ->right != NULL)
                insert(n->right , element);
            else
                n->right = new node(element);
        }
        else
        {
            if(n ->left != NULL)
                insert(n->left ,element);
            else
                n->left =new node(element);
        }
    }

}
template<class t>void Binary_Tree<t>::preorder_traversal(node<t> * n )
{
    if(empty())
    {
        cout<<"tree is empty"<<endl;
        return;
    }
    if(n != NULL)    // base case of recursion
    {
        cout<<n->item<<"|"; // visited root
        preorder_traversal(n->left);
        preorder_traversal(n->right);
    }
}

template<class t> void Binary_Tree<t>::inorder_traversal(node<t> *n)
{
    if(empty())
    {
        cout<<"tree is empty"<<endl;
        return ;
    }
    if(n != NULL)
    {
        inorder_traversal(n -> left);
        cout<<n->item<<"|";// visited root
        inorder_traversal(n ->right);
    }
}

template<class t>void Binary_Tree<t>::postorder_traversal(node<t> *n)
{
    if(empty())
    {
        cout<<"tree is empty"<<endl;
        return ;
    }
    if( n != NULL)
    {
        postorder_traversal(n -> left);
        postorder_traversal(n ->rigth);
        cout<<n ->item <<"|"; // visited root
    }
}
//class node methods
template<class t>  node<t>::node(t item)
{
    this ->item = item ;
    right = left = NULL;
}

template<class t> bool Binary_Tree<t>::delete_node(t element)
{
    node<t> * parent =tree,*temp=tree;
    char child = 'L';
    while(temp != NULL && temp -> item != element)
    {
        parent = temp;
        if(temp ->item < element)
        {
            if(temp -> right != NULL)
            {
                temp = temp ->right ;
                child = 'R';
            }
        }
        else
        {
            if(temp -> left!= NULL)
            {
                temp = temp ->left ;
                child = 'L';
            }
        }
    }
    if(temp ==NULL){cout<<"this element not found "<<endl;return false ; }
    // if node has 2 child swap with min of right subtree
    while(temp ->left != NULL && temp ->right != NULL)
    {
        node<t> * newLeft = temp ->right;
        child = 'R';
        parent = temp;

        while(newLeft ->left != NULL)
        {
            parent = newLeft ;
            newLeft =newLeft->left ;
            child = 'L';
        }
        swap(temp->item , newLeft->item);
        temp = newLeft;
    }
    // if node hasn't children
    if(is_leaf(temp))
    {
        // if node is root
        if(temp == tree)
        {
            tree = NULL ;
        }
        else
        {
            child =='L' ?parent ->left = NULL :parent ->right =NULL ;
        }
    }
    // if node has one child
    node<t> * oneChild = (temp ->left ==NULL)?temp ->right :temp->left ;
    // check if is root
    if(temp ==tree)
    {
        tree = NULL ;
    }
    else
    {
        child == 'L' ? parent ->left = oneChild :parent->right = oneChild ;
    }
    delete temp;
    return true ;
}

template<class t> node<t>* Binary_Tree <t>::get_tree()
{
    return tree ;
}

#endif //DATASTRUCTURES_IMPLEMENT_BINARYTREE_H
