

#include <iostream>
#include <queue> // Include the <queue> header for using queue data structure
using namespace std;
class node
{
public:
node *left, *right;
int data;
};
node *insert(node *root, int data)
{
if (!root)
{
root = new node;
root->left = NULL;
root->right = NULL;
root->data = data;
return root;
}
queue<node *> q;
q.push(root);
while (!q.empty())
{
node *temp = q.front();
q.pop();
if (temp->left == NULL)
{
temp->left = new node;
temp->left->left = NULL;
temp->left->right = NULL;
temp->left->data = data;
return root; // Insertion done, return the root of the tree
}
else
{
q.push(temp->left); // Push left child to the queue
}
if (temp->right == NULL)
{
temp->right = new node;
temp->right->left = NULL;
temp->right->right = NULL;
temp->right->data = data;
return root; // Insertion done, return the root of the tree
}
else
{
q.push(temp->right); // Push right child to the queue
}
}
return root; // Return root if no insertion happened
}
void bfs(node *head)
{
if (!head)
return;
queue<node *> q;
q.push(head);
while (!q.empty())
{
node *currNode = q.front();
q.pop();
cout << "\t" << currNode->data;
if (currNode->left)
q.push(currNode->left);
if (currNode->right)
q.push(currNode->right);
}
}
int main()
{
node *root = NULL;
int data;
char ans;
do
{
cout << "\n Enter the data => ";
cin >> data;
root = insert(root, data);
cout << "Do you want to insert one or more nodes? (y/n) ";
cin >> ans;
} while (ans == 'y' || ans == 'Y');
cout << "BFS Traversal:" << endl;
bfs(root);
return 0;
}

