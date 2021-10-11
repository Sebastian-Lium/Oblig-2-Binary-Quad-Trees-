// ADS101 Algoritmer og datastrukturer for spill
// Dag Nylund, Høgskolen i Innlandet (2020)
#ifndef BINARYNODE_H
#define BINARYNODE_H


class BinaryNode
{
    char m_data;
    BinaryNode* m_left;
    BinaryNode* m_right;
public:
    BinaryNode();
    BinaryNode(char data, BinaryNode* left=nullptr, BinaryNode* right=nullptr);
    char getData();
    void insert(char data);
    void intrav();
    void inOrder(class BinaryNode* root);
    void postOrder(class BinaryNode* root);
    unsigned int getFullCount(class BinaryNode* node);
    int maxDepth(BinaryNode* node);
    bool isBalanced(BinaryNode* root);
};

#endif // BINARYNODE_H
