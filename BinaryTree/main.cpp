#include <iostream>
#include <string>
#include <exception>
#include <list>
#include <functional>

struct Node
{
    int value;
    Node* left = nullptr;
    Node* right = nullptr;

    // Constructor
    Node() {};

    // Overloaded Constructor
    Node(int value) : value(value) {}

    // Overloaded Constructor
    Node(int value, Node* left, Node* right) : value(value), left(left), right(right) {}
};

void PreOrderPrint(Node* n)
{
    // TODO
    if (n == nullptr)
    {
        return;
    }

    std::cout << n->value << std::endl;

    PreOrderPrint(n->left);
    PreOrderPrint(n->right);

}

void PostOrderPrint(Node* n)
{
    // TODO
    if (n == nullptr)
        return;

    PostOrderPrint(n->left);
    PostOrderPrint(n->right);

    std::cout << n->value << std::endl;
}

void OrderPrint(Node* n)
{
    if (n == nullptr)
        return;

    OrderPrint(n->left);

    std::cout << n->value << std::endl;

    OrderPrint(n->right);

    
}

void ForEachPreOrder(Node* n, std::function<void(Node*)> fn)
{
    if (n == nullptr)
        return;
    // Invoke the fn for each node
    fn(n);
    ForEachPreOrder(n->left, fn);
    ForEachPreOrder(n->right, fn);
}

void ForEachDfs(Node* root, std::function<void(Node*)> fn)
{
    // Create the stack
    std::list<Node*> stack;
    // add first node to the stack
    stack.push_back(root);

    // while stack is not empty
    while (stack.empty() == false)
    {
        // remove the next node
        Node* n = stack.back();
        stack.pop_back();
        // process the node
        fn(n);
        // add children to the stack
        if (n->right) stack.push_back(n->right);
        if (n->left) stack.push_back(n->left);
    }
}

Node* Find(Node* n, int value)
{
    // TODO
    bool find = false;
    while (!find)
    {
        if (n == nullptr)
        {            
            find = true;
        }
        else if (n->value == value)
        {           
            find = true;
        }
        else if (value < n->value)
        {
            if (n != nullptr)
            {
                n = n->left;
            }            
        }
        else if (value > n->value)
        {
            if (n != nullptr)
            {
                n = n->right;
            }            
        }
    }
    return n;
}
    
void Insert(Node* root, Node* nodeToInsert)
{
    // TODO    
    bool adding = false;
    while(!adding)
    {
        if (nodeToInsert == nullptr)
        {
            return;
        }
        else if (nodeToInsert->value == root->value)
        {
            return;
        }
        else if (nodeToInsert->value < root->value)
        {
            if (root->left != nullptr)
            {
                root = root->left;
            }
            else
            {
                root->left = nodeToInsert;
                adding = true;
            }
        }
        else if (nodeToInsert->value > root->value)
        {
            if (root->right != nullptr)
            {
                root = root->right;
            }            
            else
            {
                root->right = nodeToInsert;
                adding = true;
            }
        }        
    }
}
    
void Remove(int val, Node* root, Node* n)
{
    //if (n->value == val)
    //{
    //    Node* child = n;
    //    n = nullptr;
    //    Insert(root, child);
    //    Insert(root, child->left);
    //    Insert(root, child->right);
    //    delete child;
    //}
    if (n->left->value == val)
    {
        Node* child = n->left;
        n->left = nullptr;
        Insert(root, child->left);
        Insert(root, child->right);
        delete child;
    }
    else if (n->right->value == val)
    {
        Node* child = n->right;
        n->right = nullptr;
        Insert(root, child->left);
        Insert(root, child->right);
        delete child;
    }
    else if (val < n->value)
    {
        Remove(val, root, n->left);
    }
    else if (val > n->value)
    {
        Remove(val, root, n->right);
    }
}
    
int Height(Node* n)
{
    // TODO
    return 0;
}
    
int Depth(Node* root, Node* n)
{
    // TODO
    return 0;
}

void PrintNode(Node* n)
{
    if (n != nullptr)
        std::cout << n->value << "Has Been Found" << std::endl;
    else
        std::cout << "Not Found: " << std::endl;
}

int main(int argc, char** argv)
{
    Node root = Node(6,
        new Node(4,
            new Node(2, nullptr, nullptr),
            new Node(5, nullptr, nullptr)),
        new Node(8,
            new Node(7, nullptr, nullptr),
            new Node(9, nullptr, nullptr)));

    PreOrderPrint(&root);
    std::cout << std::endl;

    Remove(2, &root, &root);
    PreOrderPrint(&root);
    std::cout << std::endl;

    Insert(&root, new Node(2));
    PreOrderPrint(&root);
    std::cout << std::endl;

    OrderPrint(&root);
    std::cout << std::endl;

    PostOrderPrint(&root);

    std::cout << std::endl;

    PrintNode(Find(&root, 20));
        
    return 0;
}