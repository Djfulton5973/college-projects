#include <iostream>
#include <array>

// the tree node struct
struct TreeNode  {
    int info;
    TreeNode *left, *right;
};

// the binary search tree class
// this is a very minimal implementation
// for example we should have destructor
// also we could have search, delete etc.
class BinSearchTree {
public:
    TreeNode* buildTree (int input[], int start, int end);
    void rootBuildTree (int input[], int n);
    bool insert(int newInt);
    bool remove(int key);
    void traverseNodes(TreeNode* root);
    void printLessThanK(int k);
    void printLessThanK(TreeNode* nd, int k);
    void traverseNodes();
private:
    TreeNode* root = nullptr;
};
TreeNode* BinSearchTree::buildTree (int input[], int start, int end) {
    if (start > end)
        return nullptr;
    int mid = (start + end) / 2;

    std::cout << "\nMiddle value: (" << start << " + " << end << ") / 2 = " << mid << std::endl;

    TreeNode* root = new TreeNode;

    root->info = input[mid];

    std::cout << "Left array of " << mid << ": start = " << start << ", end = " << mid - 1 << std::endl;
    root->left = buildTree(input, start, mid - 1);

    std::cout << "Right array of " << mid << ": start = " << start << ", end = " << mid + 1 << std::endl;
    root->right = buildTree(input, mid + 1, end);

    return root;
}

void BinSearchTree::rootBuildTree(int input[], int n) {
    root = buildTree(input, 0, n);
}
// insert into the BST following the logic to go left or right
bool BinSearchTree::insert(int newInt){
    TreeNode* p = root;
    TreeNode* q = nullptr;

    while (p != nullptr) {
        if (p->info == newInt) {
            return false;
        }
        q = p;
        if (newInt < p->info) {
            p = p->left;
        }
        else {
            p = p->right;
        }
    }
    // new node
    TreeNode* v = new TreeNode;
    v->info = newInt;
    v->left = nullptr;
    v->right = nullptr;
    if (q == nullptr) {
        std::cout << "Insert at root " << v->info << std::endl;
        root = v;
    }
    else if (newInt < q->info) {
        std::cout << "Insert " << v->info << " left to " << q->info << std::endl;
        q->left = v;
    }
    else{
        std::cout << "Insert " << v->info << " right to " << q->info << std::endl;
        q->right = v;
    }
    return true;
}

// this is a BST delete function
// in lieu of comments, see the corresponding slides
bool BinSearchTree::remove(int key){
    TreeNode* p = root;
    TreeNode* q = nullptr;

    while (p != nullptr && p->info != key) {
        q = p;
        if (key < p->info) {
            p = p->left;
        }
        else {
            p = p->right;
        }
    }

    if (p == nullptr) {
        return false;
    }
    std::cout << "Remove " << key << std::endl;

    TreeNode* rp;
    if (p->left == nullptr) {
        rp = p->right;
    }
    else if (p->right == nullptr) {
        rp = p->left;
    }
    else {
        TreeNode* f = p;
        rp = p->right;
        TreeNode* s = rp->left;

        while (s != nullptr) {
            f = rp;
            rp = s;
            s = rp->left;
        }

        if (f != p) {
            f->left = rp->right;
            rp->right = p->right;
        }

        rp->left = p->left;
    }

    if (q == nullptr) {
        root = rp;
    }
    else if (p == q->left) {
        q->left = rp;
    }
    else {
        q->right = rp;
    }

    delete p;
    return rp != nullptr;

}

// traversal
void BinSearchTree::traverseNodes() {
    traverseNodes(root); // call the traversal with the root, which is private
}

void BinSearchTree::traverseNodes(TreeNode* root) {
    if (root == nullptr)
        return;
    traverseNodes(root->left);
    std::cout << root->info << " ";
    traverseNodes(root->right);
}

void BinSearchTree::printLessThanK(int k) {
    printLessThanK(root, k);
}

void BinSearchTree::printLessThanK(TreeNode* nd, int k) {
    if (nd == nullptr)
        return;
    printLessThanK(nd->left, k);
    if (nd->info < k)
        std::cout << nd->info << " ";
    printLessThanK(nd->right, k);
}

////////////////////////////////////////////

int main() {
    BinSearchTree st = BinSearchTree(); // the tree object

    int tree[] = {4, 9, 15, 20, 22, 24, 35, 87};

    st.rootBuildTree(tree, 7);

    // now traverse
    std::cout << "\ninorder traversal:  ";
    st.traverseNodes();
}
