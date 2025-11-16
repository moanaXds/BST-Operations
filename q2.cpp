//#include <iostream>
//using namespace std;
//
//class Node {
//public:
//    int data;
//    Node* left;
//    Node* right;
//
//    Node(int val) 
//    {
//        data = val;
//        left = right = NULL;
//    }
//};
//
//class BST {
//public:
//
//    Node* BUILD_PREORDER(int pre[], int& start, int size, int min, int max)
//    {
//        if (pre[start] < min)return NULL;
//        if (pre[start] > max)return NULL;
//
//        Node* root = new Node(pre[start]);
//
//        if (start >= size)
//        {
//            return NULL;
//        }
//        start++;
//
//        root->left = BUILD_PREORDER(pre, start, size, min, root->data);
//        root->right = BUILD_PREORDER(pre, start, size, root->data, max);
//
//        return root;
//    }
//
//    void inorder(Node* root)
//    {
//        if (root == NULL) return;
//
//        inorder(root->left);
//        cout << root->data << " ";
//        inorder(root->right);
//    }
//
//};
//
//
//
//int main()
//{
//    int pre[] = { 1,2,4,22,6,92};
//    int size = 6;
//    int start = 0;
//
//    BST b1;
//
//    Node* root = b1.BUILD_PREORDER(pre, start, size, -100, 100);
//    cout << "Inorder Traversal: ";
//    b1.inorder(root);
//    cout << endl;
//}