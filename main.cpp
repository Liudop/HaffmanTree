#include <QCoreApplication>
#include <iostream>
#include <huffman_tree.h>
#include <QDebug>

//#include <QTextStream>

//#include <string>

using namespace std;

int main(int argc, char *argv[])
{

    QCoreApplication a(argc, argv);

    string instring;
    qDebug()<<"请输入要编码的字符串";
    cin>> instring;

    Huffman_tree *hfmtree = new Huffman_tree(instring);
    hfmtree->maketree();
    delete hfmtree;




//    QStringList teststr;
//    for(int test = 0;test<10;test++)
//    {
//        QString tmptest = QString::number(test);
//        teststr.append(tmptest);

//    }


//   // while(haha)
//    qDebug()<<"字符串"<<teststr;



    return a.exec();

}


//    someways to input or out put strings in Qt console
//    QString temp;
//    QTextStream in(stdin);
//    QTextStream out(stdout);
//    in>>temp;
//    out<<temp<<endl;
//    qDebug()<<temp;
//    char tmp;
//   string tmp;
//    cin>> tmp;
//    cout<<tmp<<endl;
