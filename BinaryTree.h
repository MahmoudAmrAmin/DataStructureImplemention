//
// Created by mahmod on 1/10/2024.
//

#ifndef FINAL_IMP_TREE_H
#define FINAL_IMP_TREE_H
#include<iostream>
#include<queue>
using namespace std;
template<class t>class Tree
{
private:
    struct node
    {
        t item ;
        node * left_child;
        node * right_child ;
        node(t value)
        {
            item = value ;
            left_child =NULL ;
            right_child = NULL;
        }
    };
    node * tree ;
public:
    Tree();
    ~Tree();
    void free_BST(node * x);
    node * get_tree(){return tree;}
    void insert( node * x , t value);
    void pre_order(node * x);
    void in_order(node * x);
    void post_order(node * x);
    void printLevelOrder(node* root);
    bool is_leaf(node * n);
    void search(t value);
    bool empty();
    bool deleteNode(t value);
};
//check if tree is empty
template<class t> bool Tree<t>::empty()
{
    return tree == NULL ;
}
// constructor
template<class t> Tree<t>::Tree()
{
    tree = NULL;
}
// delete all node from x to leaf
template<class t>void Tree<t>::free_BST(node * x )
{
    if(x == NULL){return ; }
    free_BST(x->left_child);
    free_BST(x->right_child);
    delete x ;
}
//destructor

template<class t> Tree<t>::~Tree()
{
    free_BST(tree);
}
// insert
template<class t> void Tree<t>::insert(Tree::node *x, t value)
{
    if(tree == NULL)
    {
        tree = new node(value);return;
    }
    if(x -> item == value)
    {
        cout<<"element already exist"<<endl;
    }
    else if(x->item > value)
    {
        if(x->left_child != NULL)
        {
            insert(x -> left_child ,value);
        }
        else
        {
            x->left_child = new node (value);
        }
    }
    else
    {
        if(x -> right_child != NULL)
        {
            insert(x-> right_child ,value);
        }
        else
        {
            x->right_child = new node(value);
        }
    }
}
// pre_order traversal
template<class t> void Tree<t>::pre_order(Tree::node *x)
{
    if( tree== NULL){cout<<"tree is empty"<<endl;return;}
    if(x != NULL){
    cout<<x->item<<" ";
    pre_order(x->left_child);
    pre_order(x->right_child);
    }
}
template<class t> void Tree<t>::in_order(Tree::node *x)
{
    if( tree== NULL){cout<<"tree is empty"<<endl;return;}
    if(x != NULL){
        in_order(x->left_child);
        cout<<x->item<<" "; // root
        in_order(x->right_child);
    }
}
template<class t> void Tree<t>::post_order(Tree::node *x)
{
    if( tree== NULL){cout<<"tree is empty"<<endl;return;}
    if(x != NULL){
        post_order(x->left_child);
        post_order(x->right_child);
        cout<<x->item<<" "; // root
    }
}

template<class t>void Tree<t> ::printLevelOrder(node * root)
{
    // Base Case
    if (root == NULL)
        return;

    // Create an empty queue for level order traversal
    queue<node*> q;

    // Enqueue Root and initialize height
    q.push(root);

    while (q.empty() == false) {

        // Print front of queue and remove it from queue
        node * ode = q.front();
        cout << ode->item<< " ";
        q.pop();

        // Enqueue left child
        if (ode->left_child != NULL)
            q.push(ode->left_child);

        // Enqueue right child
        if (ode->right_child != NULL)
            q.push(ode->right_child);
    }
}
// check if this node is leaf or no
template<class t> bool Tree<t>::is_leaf(Tree::node *n)
{
    return n->right_child == NULL && n->left_child == NULL;
}

// search by value
template<class t> void Tree<t>::search(t value)
{
    string path ="";
    node * temp = tree ;
    node * parent = tree ;
    if(temp == NULL){cout<<"tree is empty"<<endl;return;}
    else
    {
        path += "root";
        while(temp != NULL && temp -> item != value)
        {
            parent = temp;
            if(value > temp->item )
            {
                temp = temp->right_child;
                path+= "->right";
            }
            else
            {
                temp = temp ->left_child;
                path += "->left";
            }
        }
    }
    if(temp == NULL){cout<<"element doesn't found"<<endl;return;}
    cout<<path;
}
// delete node by value
template<class t>bool Tree<t>::deleteNode(t value)
{
    char child ='L';
    node * temp = tree ;
    node * parent = tree ;
    while(temp != NULL &&temp -> item != value)
    {
        parent = temp ;
        if(temp ->item > value)
        {
            temp = temp->left_child;
        }
        else
        {
            temp = temp ->right_child ;
            child ='R';
        }
    }
    if(temp == NULL){cout<<"element not found"<<endl;return false ;}
    // the node will delete has to child
    while(temp->right_child != NULL &&temp->left_child != NULL)
    {
        node * newLeft = temp ->right_child;
        parent = temp;
        child = 'R';
        while(newLeft->left_child != NULL)
        {
            parent = newLeft ;
            newLeft = newLeft ->left_child;
            child = 'L';
        }
        swap(temp ->item , newLeft ->item);
        temp = newLeft;
    }
    if(is_leaf(temp))
    {
        if(temp == tree ){tree = NULL;}
        else{(child =='L') ? parent ->left_child = NULL :parent ->right_child =NULL ; }
    }
    node * oneChild = (temp ->left_child == NULL)?temp->right_child : temp ->left_child ;
    if(temp == tree)
    {
        tree = oneChild ;
    }
    else
    {
        (child == 'L')?parent ->left_child = oneChild :parent->right_child = oneChild ;
    }
    delete temp;
    return true ;
}

#endif //FINAL_IMP_TREE_H
