#include <iostream>

using namespace std;

typedef struct node {
	int key;
	struct node *left, *right;
} node;
node *root;

bool isBST(node* root, node* l = NULL, node* r = NULL)
{
	if (root == NULL)
		return true;

	if (l != NULL && root->key < l->key)
		return false;

	if (r != NULL && root->key > r->key)
		return false;

	return isBST(root->left, l, root) && isBST(root->right, root, r);
}

node *insertNode(node *root, int key)
{
	if (root == NULL) {
		node *newRoot;
		newRoot = (node *)malloc(sizeof(node));
		newRoot->key = key;
		newRoot->left = NULL;
		newRoot->right = NULL;
		
		return newRoot;
	}
	else {
		if (root->left == NULL)
			root->left = insertNode(root->left, key);
		else {
			if (key < root->key && root->left->key != 0)
				root->left = insertNode(root->left, key);
			else {
				if (root->right == NULL)
					root->right = insertNode(root->right, key);
				else {
					if (key > root->key &&  root->right->key != 0)
						root->right = insertNode(root->right, key);
				}
			}
		}
	}

	return root;
}

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int key;
		cin >> key;

		root = insertNode(root, key);
	}

	if (isBST(root))
		cout << "Da" << endl;
	else cout << "Nu" << endl;

	system("pause");
	return 0;
}

//11 4 1 0 3 0 0 7 6 0 0 0
//11 3 2 1 0 0 4 0 0 5 0 0
//11 5 0 6 0 10 8 0 9 0 0 0