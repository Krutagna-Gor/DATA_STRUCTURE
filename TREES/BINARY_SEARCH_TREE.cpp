#include <iostream>
#include <cstdlib>
using namespace std;

struct node
{
    int info;
    struct node *left, *right;
};

// Create a new node
struct node *create_node(int x)
{
    struct node *temp;

    temp = (struct node *)malloc(sizeof(struct node));

    temp->info = x;
    temp->left = temp->right = NULL;

    return temp;
}

// Set node on left
void setleft(struct node *q, int x)
{
    struct node *p;

    p = create_node(x);
    q->left = p;
}

// Set node on right
void setright(struct node *q, int x)
{
    struct node *p;

    p = create_node(x);
    q->right = p;
}

// Inorder Traversal
void inorder(struct node *p)
{
    if (p == NULL)
    {
        return;
    }

    inorder(p->left);
    cout << p->info << " ";
    inorder(p->right);
}

// Preorder Traversal
void preorder(struct node *p)
{
    if (p == NULL)
    {
        return;
    }

    cout << p->info << " ";
    preorder(p->left);
    preorder(p->right);
}

// Postorder Traversal
void postorder(struct node *p)
{
    if (p == NULL)
    {
        return;
    }

    postorder(p->left);
    postorder(p->right);
    cout << p->info << " ";
}

int main()
{
    struct node *root = NULL;
    struct node *p, *q;

    int ch;

    do
    {
        int c;

        cout << "\n\n===== BINARY SEARCH TREE =====";
        cout << "\n1. Insertion";
        cout << "\n2. Traversal";
        cout << "\n3. Exit";
        cout << "\nEnter choice: ";
        cin >> c;

        switch (c)
        {
        case 1:
        {
            int n;

            cout << "\nEnter the root: ";
            cin >> n;

            // Create root only if tree is empty
            if (root == NULL)
            {
                root = create_node(n);
                cout << "\nRoot created successfully.";
            }
            else
            {
                cout << "\nTree already exists. Root = "
                     << root->info;
            }

            int choice;

            do
            {
                cout << "\n\nDo you want to insert another node?";
                cout << "\n1. Yes";
                cout << "\n2. No";
                cout << "\nChoice: ";
                cin >> choice;

                if (choice == 1)
                {
                    int x;

                    cout << "\nEnter node value: ";
                    cin >> x;

                    // Start searching from root
                    p = root;
                    q = root;

                    // Find the correct position
                    while (p != NULL)
                    {
                        q = p;

                        if (x < p->info)
                        {
                            p = p->left;
                        }
                        else
                        {
                            p = p->right;
                        }
                    }

                    // Insert the new node
                    if (x < q->info)
                    {
                        setleft(q, x);
                    }
                    else
                    {
                        setright(q, x);
                    }

                    cout << "Node inserted successfully.";
                }

            } while (choice == 1);

            break;
        }

        case 2:
        {
            if (root == NULL)
            {
                cout << "\nTree is empty!";
                break;
            }

            int choice;

            cout << "\n\n===== TRAVERSAL =====";
            cout << "\n1. Inorder";
            cout << "\n2. Preorder";
            cout << "\n3. Postorder";
            cout << "\nEnter choice: ";
            cin >> choice;

            switch (choice)
            {
            case 1:
                cout << "\nInorder Traversal: ";
                inorder(root);
                cout << endl;
                break;

            case 2:
                cout << "\nPreorder Traversal: ";
                preorder(root);
                cout << endl;
                break;

            case 3:
                cout << "\nPostorder Traversal: ";
                postorder(root);
                cout << endl;
                break;

            default:
                cout << "\nInvalid traversal choice!";
            }

            break;
        }

        case 3:
            cout << "\nProgram exited.";
            return 0;

        default:
            cout << "\nInvalid choice!";
        }

        cout << "\n\nDo you want to continue?";
        cout << "\n1. Yes";
        cout << "\n2. No";
        cout << "\nChoice: ";
        cin >> ch;

    } while (ch == 1);

    return 0;
}