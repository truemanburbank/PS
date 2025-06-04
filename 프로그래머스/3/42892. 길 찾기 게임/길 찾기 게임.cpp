#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// 이진트리를 직접 구현하여 전위, 후위 순회하면 되는 문제
class Node
{
public:

    int id, x, y;
    Node* left = nullptr;
    Node* right = nullptr;

    Node(int id, int x, int y) : id(id), x(x), y(y) {}
};

class BinaryTree
{
private:
    Node* root = nullptr;

    static bool cmp(Node* a, Node* b)
    {
        if (a->y == b->y)
            return a->x < b->x;
        return a->y > b->y;
    }

    Node* AddNode(Node* current, Node* newNode)
    {
        if (current == nullptr)
            return newNode;

        if (newNode->x < current->x)
            current->left = AddNode(current->left, newNode);
        else
            current->right = AddNode(current->right, newNode);

        return current;
    }

    // 전위 순회
    void PreOrder(Node* node, vector<int>& answer)
    {
        if (node == nullptr)
            return;

        answer.push_back(node->id);
        PreOrder(node->left, answer);
        PreOrder(node->right, answer);
    }

    // 후위 순회
    void PostOrder(Node* node, vector<int>& answer)
    {
        if (node == nullptr)
            return;

        PostOrder(node->left, answer);
        PostOrder(node->right, answer);
        answer.push_back(node->id);
    }

public:
    BinaryTree() : root(nullptr) {}

    void BuildeTree(const vector<vector<int>>& nodeInfo)
    {
        vector<Node*> nodes;

        for (int i = 0; i < nodeInfo.size(); i++)
            nodes.push_back(new Node(i + 1, nodeInfo[i][0], nodeInfo[i][1]));

        sort(nodes.begin(), nodes.end(), cmp);

        for (Node* node : nodes)
            root = AddNode(root, node);
    }

    vector<int> GetPreOrder()
    {
        vector<int> ret;

        PreOrder(root, ret);

        return ret;
    }

    vector<int> GetPostOrder()
    {
        vector<int> ret;

        PostOrder(root, ret);

        return ret;
    }
};


vector<vector<int>> solution(vector<vector<int>> nodeinfo) 
{
    vector<vector<int>> answer;

    BinaryTree tree;
    tree.BuildeTree(nodeinfo);

    vector<int> pre = tree.GetPreOrder();
    answer.push_back(pre);

    vector<int> post = tree.GetPostOrder();
    answer.push_back(post);

    return answer;
}