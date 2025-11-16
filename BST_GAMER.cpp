//
//#include <iostream>
//#include <string>
//
//using namespace std;
//
//// ======== Class: Gamer ========
//class Gamer
//{
//public:
//    string name;
//    int rank;
//    float accuracy;
//
//    // TODO: Constructor to initialize attributes
//
//
//    void display() const
//    {
//        cout << "Name: " << name
//            << ", Rank: #" << rank
//            << ", Accuracy: " << accuracy << endl;
//    }
//};
//
//// ======== Class: Node ========
//class Node
//{
//public:
//    Gamer gamer;
//    Node* left;
//    Node* right;
//
//    Node(Gamer g)
//    {
//        gamer = g;
//        left = right = nullptr;
//    }
//};
//
//// ======== Class: GamerBST ========
//class GamerBST
//{
//private:
//    Node* root;
//
//    // ===== Helper Functions =====
//    // TODO: Recursive insert function (sorted by rank)
//
//    Node* insert(Node* root, Gamer g)
//    {
//        if (root == NULL)
//        {
//            return new Node(g);
//        }
//
//        if (g.rank < root->gamer.rank)
//        {
//            root->left = insert(root->left, g);
//        }
//
//        if (g.rank > root->gamer.rank)
//        {
//            root->right = insert(root->right, g);
//        }
//
//        return root;
//    }
//
//    // TODO: Recursive search function (by rank)
//
//    Node* search(Node* node, int rank)
//    {
//        if (node == NULL)
//        {
//            return NULL;
//        }
//
//        if (rank == node->gamer.rank)
//        {
//            return node;
//        }
//
//        if (rank < node->gamer.rank)
//        {
//            return  search(node->left, rank);
//        }
//
//        if (rank > node->gamer.rank)
//        {
//            return  search(node->right, rank);
//        }
//
//    }
//
//
//    // TODO: Recursive inorder traversal to display leaderboard
//
//    void inorder(Node* root)
//    {
//        if (root == NULL)return;
//
//        inorder(root->left);
//        root->gamer.display();
//        inorder(root->right);
//    }
//
//    // TODO: Finds the gamer with lowest accuracy
//
//    Node* findMinAccNode(Node* node)
//    {
//        if (node == NULL)return NULL;
//
//        Node* minNode = NULL;
//
//        findMinAccNodeHelper(node, minNode);
//
//        return minNode;
//    }
//
//
//    // TODO: Helper method for the above method. Recursively finds the gamer with lowest accuracy
//
//    void findMinAccNodeHelper(Node* node, Node*& minNode)
//    {
//        if (node == nullptr) return;
//
//        if (minNode == NULL || node->gamer.accuracy < minNode->gamer.accuracy)
//        {
//            minNode = node;
//        }
//
//
//        findMinAccNodeHelper(node->left, minNode);
//        findMinAccNodeHelper(node->right, minNode);
//    }
//
//
//    // TODO: Deletes the gamer by rank with the lowest accuracy
//
//    Node* deleteByRank(Node* node, int rank)
//    {
//        if (node == NULL)
//        {
//            return NULL;
//        }
//
//
//        if (rank < node->gamer.rank)
//        {
//            node->left = deleteByRank(node->left, rank);
//        }
//
//        if (rank > node->gamer.rank)
//        {
//            node->right = deleteByRank(node->right, rank);
//        }
//
//        else
//        {
//            if (node->left == NULL && node->right == NULL)
//            {
//                delete node;
//                return NULL;
//            }
//
//            else if (node->right == NULL)
//            {
//                Node* temp = node->left;
//                delete node;
//                return temp;
//            }
//
//            else
//            {
//                Node* temp = node->right;
//
//                while (temp->left != NULL)
//                {
//                    temp = temp->left;
//                }
//
//                node->gamer = temp->gamer;
//
//                node->right = deleteByRank(node->right, rank);
//
//            }
//
//
//        }
//
//        return node;
//    }
//
//
//    void DeleteMinAccuracy()
//    {
//        if (root == NULL)return;
//
//        Node* storeMin = findMinAccNode(root);
//
//        cout << " Min AccURACY Node :";
//        storeMin->gamer.display();
//
//        root = deleteByRank(root, storeMin->gamer.rank);
//
//    }
//
//
//public:
//    GamerBST()
//    {
//        root = nullptr;
//    }
//
//    // ===== Public Interface =====
//    void insert(Gamer g)
//    {
//        // TODO: Call recursive insert helper
//        root = insert(root, g);
//    }
//
//    void searchByRank(int rank)
//    {
//        // TODO: Call recursive search helper and display result
//        Node* result = search(root, rank); 
//
//        if (result == NULL) cout << "Player not found\n";
//
//        else
//        {
//            cout << "Player found: ";
//            result->gamer.display();
//        }
//    }
//
//    void deleteMinAccuracy()
//    {
//        // TODO: Call recursive search helpers and remove the gamer with lowest accuracy
//
//        // Use the findMinAccNode and deleteByRank helper methods
//
//        DeleteMinAccuracy();
//    }
//
//    void displayLeaderboard()
//    {
//        cout << "\n=== Leaderboard (Sorted by Rank) ===\n";
//        // TODO: Call inorder traversal
//
//        inorder(root);
//
//    }
//};
//
//// ======== Main Function ========
//int main()
//{
//    GamerBST leaderboard;
//    int choice;
//
//    do
//    {
//        cout << "\n=== Gamer Leaderboard System ===\n";
//        cout << "1. Add Gamer\n";
//        cout << "2. Search Gamer by Rank\n";
//        cout << "3. Display Leaderboard\n";
//        cout << "4. Remove Gamer with Lowest Accuracy\n";
//        cout << "5. Exit\n";
//        cout << "Enter choice: ";
//        cin >> choice;
//
//        if (choice == 1)
//        {
//            Gamer g;
//            cout << "Enter name: ";
//            cin >> g.name;
//            cout << "Enter rank: ";
//            cin >> g.rank;
//            cout << "Enter Accuracy Ratio: ";
//            cin >> g.accuracy;
//            leaderboard.insert(g);
//            cout << "Gamer added successfully!\n";
//        }
//        else if (choice == 2)
//        {
//            int r;
//            cout << "Enter rank to search: ";
//            cin >> r;
//            leaderboard.searchByRank(r);
//        }
//        else if (choice == 3)
//        {
//            leaderboard.displayLeaderboard();
//        }
//        else if (choice == 4)
//        {
//            leaderboard.deleteMinAccuracy();
//        }
//
//        else if (choice == 5)
//        {
//            cout << "Exiting...\n";
//        }
//        else
//        {
//            cout << "Invalid choice! Try again.\n";
//        }
//
//    } while (choice != 5);
//
//    return 0;
//}
