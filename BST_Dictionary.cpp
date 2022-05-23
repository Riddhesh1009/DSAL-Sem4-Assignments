// A Dictionary stores keywords and its meanings. Provide facility for adding new 
// keywords, deleting keywords, updating values of any entry. Provide facility to display 
// whole data sorted in ascending/ Descending order. Also find how many maximum 
// comparisons may require for finding any keyword. Use Binary Search Tree for 
// implementation. 

#include <iostream>
using namespace std;

class Node
{
    string key;
    string mean;
    Node *left;
    Node *right;

public:
    Node()
    {
        key = "";
        mean = "";
        left = NULL;
        right = NULL;
    }
    Node(string value, string m)
    {
        key = value;
        mean = m;
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
    void insert(string value, string m);
    void search(string TargetValue);
    Node *search(Node *root, string TargetValue);
    void deleteValue(string value);
    Node *deleteRecursive(Node *root, string value);
    void display();
    void Inorder(Node* );
};

void BST :: display()
{
    Node* ptemp;
    ptemp=root;
    Inorder(ptemp);
}

void BST :: Inorder(Node* ptemp)
{
    if(ptemp!=NULL)
    {
        Inorder(ptemp->left);
        cout<<"= "<<ptemp->key<<" - "<<ptemp->mean<<endl;
        Inorder(ptemp->right);

    }


}

void BST::insert(string value, string m)
{
    Node *pNew;
    pNew = new Node(value, m);

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
            if (value < pTemp->key)
            {
                if (pTemp->left == NULL)
                {
                    pTemp->left = pNew;
                    cout << "New Value Inserted to the left of " << pTemp->key << endl;
                    break;
                }
                else
                {
                    pTemp = pTemp->left;
                }
            }
            else if (value > pTemp->key)
            {
                if (pTemp->right == NULL)
                {
                    pTemp->right = pNew;
                    cout << "New Value Inserted to the right of " << pTemp->key << endl;
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

void BST::search(string TargetValue)
{
    Node *ptemp;
    ptemp = search(root, TargetValue);
   
    if (ptemp == NULL)
    {
        cout << "NOT Found" << endl;
    }
    else
    {
        cout << ptemp->key << " ---> " << ptemp->mean << endl;
    }
}

Node *BST::search(Node *root, string TargetValue)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (TargetValue < root->key)
    {
        return search(root->left, TargetValue);
    }
    else if (TargetValue > root->key)
    {
        return search(root->right, TargetValue);
    }
    else
    {
        return root;
    }
}

void BST::deleteValue(string value)
{
    root = deleteRecursive(root, value);
}

Node *BST::deleteRecursive(Node *root, string value)
{
    if (root == NULL)
    {
        return NULL;
        cout << "Value is not present in tree" << endl;
    }
    else
    {
        if (value < root->key)
        {
            cout << "Searching the value in left subtree of " << root->key << endl;
            root->left = deleteRecursive(root->left, value);
        }
        else if (value > root->key)
        {
            cout << "Searching the value in right subtree of " << root->key << endl;
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
                    pInSucc = pInSucc->left;

                root->key = pInSucc->key;
                root->mean=pInSucc->mean;
                root->right = deleteRecursive(root->right, pInSucc->key);
            }
        }
        return root;
    }
}

int main()
{
    int n, result, x;
    string val, m, inp;
    BST bt;

    while (1)
    {
        cout << "1.Insert  2.Search  3.Delete a Node 4.Update a node 5.Display the Dictionary 0.Exit " << endl;
        cin >> x;
        if (x == 0)
            return 0;
        else if (x == 1) // Insert
        {
            cout << "\nEnter the Word : ";
            cin >> val;
            cout << "\nEnter the Meaning : ";
            cin >> m;
            bt.insert(val, m);
        }

        else if (x == 2) // search
        {
            cout << "\nEnter Value for search :";
            cin >> inp;
            bt.search(inp);
        }

        else if (x == 3) // Deleting
        {
            string d;
            cout << "Enter the value to be deleted" << endl;
            cin >> d;
            bt.deleteValue(d);
        }
        else if (x == 4) // Updating
        {
            string Up;
            cout << "Enter the value to be Updated" << endl;
            cin >> Up;
            bt.deleteValue(Up);
            cout << "\nEnter the Meaning : ";
            cin >> m;
            bt.insert(Up, m);
        } 

        else if (x == 5) // Display
        {
            cout<<"The words in our Dictionary are :- "<<endl;
            bt.display();
        } 


        else
            cout << "Invalid" << endl;
    }
}
