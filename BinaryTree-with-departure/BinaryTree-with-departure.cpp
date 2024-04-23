#include <string>
#include <iostream>

/*Когда иду влево влево вправо вправо то он проскакивает одно лево и записывает после 1 лево 2 права*/
using namespace std;
class Node {
public:
    string data;
    Node* left;
    Node* right;
    Node* back;

    Node(string data1) {
        data = data1;
        left = NULL;
        right = NULL;
        back = NULL;

    }
};
class BinTree {
public:
    Node* root;
    BinTree() {
        this->root = NULL;
    }
    void printTree(Node* root, int level) {
        if (root != NULL) {
            printTree(root->right, level + 1);
            for (int i = 0; i < level; i++) {
                cout << "    ";
            }
            cout << root->data << endl;
            printTree(root->left, level + 1);
        }
    }

    void startAdd() {
        if (root == NULL) {
            cout << "Введите элемент в начало дерева: " << endl;
            string elem;
            cin >> elem;
            Node* node = new Node(elem);
            root = node;
        }
        else {
            string choice, elem;

            cout << "В какую сторону дерева пойдем? r or l" << endl;
            cin >> choice;

            Node* current = root;

            while (true)
            {
                if ((current->left == NULL) && (choice == "l")) {
                    write_left(current);
                    break;

                }
                else if ((current->right == NULL) && (choice == "r")) {
                    write_right(current);
                    break;
                }
                else {
                    if (choice == "r")
                    {
                        cout << "Здесь находится элемент " << current->right->data << endl;
                        current = current->right;
                    }
                    else if (choice == "l") {
                        cout << "Здесь находится элемент " << current->left->data << endl;
                        current = current->left;
                    }
                    cout << "Куда пойдем? r or l" << endl;
                    cin >> choice;


                }
            }
        }
    }

private:
    void write_left(Node* current) {
        string elem;
        cout << "Введите элемент: " << endl;
        cin >> elem;
        current->left = new Node(elem);

    }
    void write_right(Node* current) {
        string elem;
        cout << "Введите элемент: " << endl;
        cin >> elem;
        current->right = new Node(elem);
    }
};
int main()
{
    BinTree tree;
    setlocale(LC_ALL, "ru");
    cout << "Бинарное дерево~ " << endl;
    tree.startAdd();
    tree.startAdd();
    tree.startAdd();
    tree.startAdd();
    tree.startAdd();


    tree.printTree(tree.root, 5);
    cout << endl;


}
