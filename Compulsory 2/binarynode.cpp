// ADS101 Algoritmer og datastrukturer for spill
// Dag Nylund, Høgskolen i Innlandet (2020)
#include <iostream>
#include <stack>
#include <queue>
#include "binarynode.h"

BinaryNode::BinaryNode() { }
BinaryNode::BinaryNode(char data, BinaryNode* left, BinaryNode* right) :
m_data{data}, m_left{left}, m_right{right}
{ }

char BinaryNode::getData() { return m_data; }

void BinaryNode::insert(char data)
{
    if (data < m_data) {
        if (m_left)
            m_left->insert(data);
        else
            m_left = new BinaryNode(data);
    }
    else if (data > m_data) {
        if (m_right)
            m_right->insert(data);
        else
            m_right = new BinaryNode(data);
    }
}
void BinaryNode::intrav()
{
    if (m_left)
        m_left->intrav();
    std::cout << m_data;
    if (m_right)
        m_right->intrav();
}

void BinaryNode::inOrder(class BinaryNode* root)
{
    std::stack<BinaryNode*> s;
    BinaryNode* current = root;

    while (current != NULL || s.empty() == false) {
        while (current != NULL) {
            s.push(current);
            current = current->m_left;
        }
        current = s.top();
        s.pop();

        std::cout << current->m_data << " ";

        current = current->m_right;
    }
}

void BinaryNode::postOrder(class BinaryNode* root)
{
    if (root == NULL) return;
    std::stack<BinaryNode*> s1, s2;

    s1.push(root);
    BinaryNode* node;

    while (!s1.empty()) {
        node = s1.top();
        s1.pop();
        s2.push(node);

        if (node->m_left) {
            s1.push(node->m_left);
        }
        if (node->m_right) {
            s1.push(node->m_right);
        }
    }
    while (!s2.empty()) {
        node = s2.top();
        s2.pop();
        std::cout << node->m_data << " ";
    }
}

unsigned int BinaryNode::getFullCount(BinaryNode* node)
{
    if (!node) {
        return 0;
    }
    int count = 0;
    std::stack<BinaryNode*> s;
    BinaryNode* current = node;

    while (current != NULL || s.empty() == false) {
        while (current != NULL) {
            s.push(current);
            current = current->m_left;
        }
        current = s.top();
        s.pop();

        ++count;

        current = current->m_right;
    }
    return count;
}

int BinaryNode::maxDepth(BinaryNode* node)
{
        if (node == NULL)
            return 0;
        else
        {
            int lDepth = maxDepth(node->m_left);
            int rDepth = maxDepth(node->m_right);

            if (lDepth > rDepth)
                return(lDepth + 1);
            else return(rDepth + 1);
        }
}

bool BinaryNode::isBalanced(BinaryNode* root)
{
    int lDepth;
    int rDepth;

    if (root == NULL) {
        return 1;
    }

    lDepth = maxDepth(root->m_left);
    rDepth = maxDepth(root->m_right);

    if (abs(lDepth - rDepth) <= 1 && isBalanced(root->m_left) && isBalanced(root->m_right)) {
        return 1;
    }

    return 0;
}
