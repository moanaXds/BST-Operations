//#include<iostream>
//
//using namespace std;
//
//class Node {
//public:
//	int data;
//	Node* left;
//	Node* right;
//
//	Node(int val)
//	{
//		data = val;
//		left = right = NULL;
//	}
//};
//
//class BST {
//public:
//	Node* insertion(Node* root, int val)
//	{
//		if (root == NULL)
//		{
//			return new Node(val);
//		}
//
//		if (val < root->data)
//		{
//			root->left = insertion(root->left, val);
//
//		}
//		if (val > root->data)
//		{
//			root->right = insertion(root->right, val);
//
//		}
//		return root;
//	}
//
//	void FindPrecedorSuccesor(Node* root)
//	{
//		Node* temp = root->right;
//
//		if (temp != NULL)
//		{
//			while (temp->left != NULL)
//			{
//				temp = temp->left;
//			}
//
//			cout << "INORDER SUCCESOR : " << temp->data<<endl;
//		}
//		else
//		{
//			cout << "NO INORDER SUCCESOR \n";
//		}
//
//		Node* temp1 = root->left;
//
//		if (temp != NULL)
//		{
//			while (temp->right != NULL)
//			{
//				temp = temp->right;
//			}
//
//			cout << "INORDER PRECEDOR : " << temp->data << endl;
//		}
//		else
//		{
//			cout << "NO INORDER PRECEDOR ";
//		}
//	}
//};
//
//int main()
//{
//	BST b1;
//	Node* root = NULL;
//	root = b1.insertion(root, 20);
//	root = b1.insertion(root, 8);
//	root = b1.insertion(root, 22);
//	root = b1.insertion(root, 4);
//	root = b1.insertion(root, 12);
//	root = b1.insertion(root, 10);
//	root = b1.insertion(root, 14);
//
//	b1.FindPrecedorSuccesor(root);
//
//}