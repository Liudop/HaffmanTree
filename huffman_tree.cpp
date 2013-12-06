#include "huffman_tree.h"

Huffman_tree::~Huffman_tree()
{
    code.clear();
    list.clear();
    treelist.clear();

    myDeleteTree(maintree);
    qDebug()<<"析构调用";
}

void Huffman_tree::myDeleteTree(phftree deleteTree)
{
    if(deleteTree->lchild!=NULL)
    {
        myDeleteTree(deleteTree->lchild);
    }
    else
    {
        delete deleteTree;
        return;
    }
    if(deleteTree->rchild!=NULL)
    {
        myDeleteTree(deleteTree->rchild);
    }
    else
    {
        delete deleteTree;
        return;
    }




}


Huffman_tree::Huffman_tree(string intext)
{
    //text = intext;
    char tmp;
    foreach (tmp, intext)
    {
        if(list.contains(tmp))//查找是否含tmp的键
        {
            list[tmp]++;
        }
        else
        {
            list.insert(tmp,1);
        }
    }

    //    QList<int> slist = list.values();
    //    qSort(slist.begin(), slist.end());

    for(int m = 1;!list.isEmpty();m++)
    {
        QHashIterator <char,int> i(list);

        while(i.hasNext())
        {
            i.next();
            if(i.value()== m)
            {
                qDebug()<<i.key()<<"has value"<<i.value();
                //                wordstack.push(i.key());
                //                weightstack.push(i.value());
                phftree tree = new hftree;
                tree->parent = tree->lchild = tree->rchild = NULL;
                tree->weight = m;
                char tmpword = i.key();
                tree->word = tmpword;
                treelist.append(tree);
                //                qDebug()<<"next is";
                //                qDebug()<<tree->word<<"has value"<<tree->weight<<endl;
                list.remove(i.key());
            }
        }
    }


    //                QHashIterator <char,int> j(list);

    //                while(j.hasNext())
    //                {
    //                    j.next();
    //                    qDebug()<<j.key()<<"has value"<<j.value();
    //                }


}

void Huffman_tree::maketree()
{
    while(treelist.count()>1)
    {
        phftree parenttree = new hftree;
        parenttree->lchild = treelist[0];
        parenttree->rchild = treelist[1];
        parenttree->parent = NULL;
        parenttree->word = ' ';
        parenttree->weight = parenttree->lchild->weight + parenttree->rchild->weight;
        treelist.removeAt(0);
        treelist.removeAt(0);
        if(treelist.count()==0)
        {
            //return parenttree;
            maintree = parenttree;
            giveCode(parenttree);
        }
        else if(parenttree->weight>=treelist.last()->weight)
        {
            treelist+=parenttree;
        }
        else
        {
            for(int i = 0;treelist.count()>i;i++)
            {
                if(parenttree->weight<treelist[i]->weight)
                {
                    treelist.insert(i,parenttree);
                    break;
                }
            }
        }

    }
}


void Huffman_tree::giveCode(phftree tmptree)
{

    //   qDebug()<<"dwdedc";
    //    QString code;
    //    phftree nowtree = tmptree;

    //    if(nowtree->lchild!=NULL)
    //    {
    //        nowtree = nowtree->lchild;
    //        code += '0';

    //    }

    /*QStack<int> code;*/// = QChar(' ');

    if(tmptree->lchild==NULL)
    {

        QStack<int>::Iterator m;
        cout<<endl<<tmptree->word<<" has code: ";
        for(m=code.begin();m!=code.end();++m)
        {
            cout<<*m;
        }

        code.pop();
        return ;
    }
    else
    {
        code.push(0);
        giveCode(tmptree->lchild);
        //code.pop();
    }


    if(tmptree->rchild==NULL)
    {
        QStack<int>::Iterator m;
        cout<<endl<<tmptree->word<<"has code: ";
        for(m=code.begin();m!=code.end();++m)
        {
            cout<<*m;
        }
        code.pop();
        return ;
    }
    else
    {
        code.push(1);
        giveCode(tmptree->rchild);
        if(!code.isEmpty())
        {
            code.pop();
        }
    }


}



//    QChar lword,rword;
//    int lweight,rweight;
//    lword  = wordstack.pop();
//    rword  = wordstack.pop();
//    lweight = weightstack.pop();
//    rweight = weightstack.pop();

//    phftree parentpoint,lchildpoint,rchildpoint;
//    lchildpoint->parent = parentpoint;
//    rchildpoint->parent = parentpoint;
//    lchildpoint->lchild = lchildpoint->rchild = rchildpoint->lchild = rchildpoint->rchild = NULL;
//    lchildpoint->word = lword;
//    lchildpoint->weight = lweight;
//    rchildpoint->word = rword;
//    rchildpoint->weight = rweight;

//    parentpoint->word = ' ';
//    parentpoint->weight = lweight+rweight;

//    wordstack.push(' ');
//    weightstack.push(lweight+rweight);



