#ifndef HUFFMAN_TREE_H
#define HUFFMAN_TREE_H

//#include<string>
#include <QtCore>
#include <iostream>

using namespace std;

//typedef struct linklist
//{
//    char word;
//    int weight;

//    struct linklist *next;

//}   lklist,*plklist;

typedef struct Huffmantree
{
    char word;
    int weight;

    struct Huffmantree *parent,*lchild,*rchild;

}   hftree,*phftree;



class Huffman_tree
{

public:
    ~Huffman_tree();
    Huffman_tree(string intext);
    void maketree();
    void giveCode(phftree tmptree);

private:
    void myDeleteTree(phftree deleteTree);
    phftree maintree;
    QHash<char,int> list;
    // QStack <char> wordstack;
    //  QStack <int> weightstack;
    QList < phftree > treelist;

    QStack<int> code;

    // string text;


};

#endif // HUFFMAN_TREE_H
