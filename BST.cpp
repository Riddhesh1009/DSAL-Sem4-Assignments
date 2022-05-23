// Beginning with an empty binary search tree, Construct binary search tree by inserting 
// the values in the order given. After constructing a binary tree -
// i. Insert new node, ii. Find number of nodes in longest path from root, iii. Minimum data 
// value found in the tree, iv. Change a tree so that the roles of the left and right pointers 
// are swapped at every node, v. Search a value 

#include <iostream>
using namespace std;
class Node
{
    int data;
    Node *left;
    Node *right;

public:
    Node()
    {
        data = 0;
        left = NULL;
        right = NULL;
    }
    Node(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
    friend class BST;
};

class BST
{
    Node *root;

public:
    BST()
    {
        root = NULL;
        cout << "Empty Binary Search Tree Created" << endl;
    }
    void insert(int value);
    Node *search(Node *root, int TargetValue);
    bool search(int TargetValue);
    int mini();
    int height(Node *root);
    void longestpath();
    void swap();
    void swap(Node *root);
    void deleteValue(int value);
    Node *deleteRecursive(Node *root, int value);
};

void BST::insert(int value)
{
    Node *pNew;
    pNew = new Node(value);
    if (root == NULL)
    {
        root = pNew;
        cout << "Root Created" << endl;
    }
    else
    {
        Node *pTemp;
        pTemp = root;
        do
        {
            if (value < pTemp->data)
            {
                if (pTemp->left == NULL)
                {
                    pTemp->left = pNew;
                    cout << "New Value Inserted to the left of " << pTemp->data << endl;
                    break;
                }
                else
                {
                    pTemp = pTemp->left;
                }
            }
            else if (value > pTemp->data)
            {
                if (pTemp->right == NULL)
                {
                    pTemp->right = pNew;
                    cout << "New Value Inserted to the right of " << pTemp->data << endl;
                    break;
                }
                else
                {
                    pTemp = pTemp->right;
                }
            }
            else
            {
                cout << "Duplicate Element Entered" << endl;
                break;
            }
        } while (pTemp != NULL);
    }
}

bool BST::search(int TargetValue)
{
    return search(root, TargetValue);
}

Node *BST::search(Node *root, int TargetValue)
{
    if (root == NULL)
    {
        return NULL;
    }

    
    if (TargetValue < root->data)
    {
        return search(root->left, TargetValue);
    }
    else if (TargetValue > root->data)
    {
        return search(root->right, TargetValue);
    }
    else
    {
        return root;
    }
}

int BST::mini()
{
    Node *pTemp;
    pTemp = root;
    while (pTemp->left != NULL)
    {
        pTemp = pTemp->left;
    }

    return pTemp->data;
};

int BST::height(Node *root)
{
    int hl, hr;
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return 1;
    else
        hl = height(root->left);
    hr = height(root->right);
    if (hr >= hl)
        return hr + 1;
    else
        return hl + 1;
}

void BST::longestpath()
{
    cout << "Number of nodes in longest path :" << height(root) << endl;
}

void BST::swap(Node *root)
{
    Node *temp;

    if (root->left != NULL)
        swap(root->left);
    if (root->right != NULL)
        swap(root->right);

    // Swap
    temp = root->left;
    root->left = root->right;
    root->right = temp;
}

void BST::swap()
{
    swap(root);
    cout << "binary tree is Swapped" << endl;
}

void BST::deleteValue(int value)
{
    root = deleteRecursive(root, value);
}

Node *BST::deleteRecursive(Node *root, int value)
{
    if (root == NULL)
    {
        return NULL;
        cout << "Value is not present in tree" << endl;
    }
    else
    {
        if (value < root->data)
        {
            cout << "Searching the value in left subtree of " << root->data << endl;
            root->left = deleteRecursive(root->left, value);
        }
        else if (value > root->data)
        {
            cout << "Searching the value in right subtree of " << root->data << endl;
            root->right = deleteRecursive(root->right, value);
        }
        else
        { // value is found in the current root
            cout << "Value is found---deleting it" << endl;
            if (root->right == NULL)
                return root->left;
            else
            {
                Node *pInSucc;
                pInSucc = root->right;
                while (pInSucc->left != NULL)
                {
                    pInSucc = pInSucc->left;
                }

                root->data = pInSucc->data;

                root->right = deleteRecursive(root->right, pInSucc->data);
            }
        }
        return root;
    }
}

int main()
{
    int n, val, result, inp, x, min;
    BST bt;

    while (1)
    {
        cout << "1.Insert  2.Search  3.Minimum val  4.No.of nodes in longest path \n 5.Mirror the BST 6.Delete a Node 0.Exit " << endl;
        cin >> x;
        if (x == 0)
            return 0;
        else if (x == 1) // Insert
        {
            cout << "\nEnter Value : ";
            cin >> val;
            bt.insert(val);
        }

        else if (x == 2) // search
        {
            cout << "\nEnter Value for search :";
            cin >> inp;
            result = bt.search(inp);
            if (result == true)
            {
                cout << "Element is Present" << endl;
            }
            else
            {
                cout << "Element is not Present" << endl;
            }
        }

        else if (x == 3) // Minimum val
        {

            min = bt.mini();
            cout << "Minimum value is " << min << endl;
        }

        else if (x == 4) // Longest path
        {
            bt.longestpath();
        }

        else if (x == 5) // Swapping
        {
            bt.swap();
        }

        else if (x == 6) // Deleting
        {
            int d;
            cout << "Enter the value to be deleted" << endl;
            cin >> d;
            bt.deleteValue(d);
        }

        else
            cout << "Invalid" << endl;
    }
}
