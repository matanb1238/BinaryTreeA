
#include "sources/BinaryTree.hpp"
#include "doctest.h"
#include <iostream>
#include <sstream>
#include<string>

using namespace ariel;
using namespace std;

TEST_CASE("Add Check"){
    BinaryTree<int> b;
    CHECK_NOTHROW(b.add_root(1));
    CHECK_NOTHROW(b.add_left(1, 2));
    CHECK_NOTHROW(b.add_right(1, 3));
    
    //overriding
    CHECK_NOTHROW(b.add_right(1,4));
    CHECK_NOTHROW(b.add_root(3));
    CHECK_THROWS(b.add_right(1,5)); //There is no 1 in the tree
    
    BinaryTree<int> b2;
    //Not the correct type
    CHECK_THROWS(b.add_root(1.0));
    CHECK_THROWS(b.add_root('1'));

    //Now with the correct types
    BinaryTree<double> b3;
    CHECK_NOTHROW(b.add_root(1.0));

    BinaryTree<string> b4;
    CHECK_NOTHROW(b.add_root('1'));
}
TEST_CASE("PreOrder"){
    //int
    BinaryTree<int> b;
    b.add_root(1);
    b.add_left(1,2);
    b.add_right(1,3);
    b.add_left(3,4);
    b.add_right(3,5);
                         //        1
                         //      2   3
                         //         4  5
    ostringstream os;
    for (auto it=b.begin_preorder(); it!=b.end_preorder(); ++it) {
        os << (*it) << " " ;
    } 
    CHECK_EQ(os.str(), "1 2 3 4 5 ");

    //string
    BinaryTree<int> b2;
    b2.add_root('M');
    b2.add_left('M','a');
    b2.add_right('M','t');
    b2.add_left('t','a');
    b2.add_right('t','n');
                
    ostringstream os2;
    for (auto it=b2.begin_preorder(); it!=b2.end_preorder(); ++it) {
        os2 << (*it);
    } 
    CHECK_EQ(os.str(), "Matan");
}
TEST_CASE("InOrder"){
    //int
    BinaryTree<int> b;
    b.add_root(1);
    b.add_left(1,2);
    b.add_right(1,3);
    b.add_left(3,4);
    b.add_right(3,5);
                         //        1
                         //      2   3
                         //         4  5
    ostringstream os;
    for (auto it=b.begin_preorder(); it!=b.end_preorder(); ++it) {
        os << (*it) << " " ;
    } 
    CHECK_EQ(os.str(), "2 1 4 3 5 ");

    //string
    BinaryTree<int> b2;
    b2.add_root('M');
    b2.add_left('M','a');
    b2.add_right('M','t');
    b2.add_left('t','a');
    b2.add_right('t','n');
                
    ostringstream os2;
    for (auto it=b2.begin_preorder(); it!=b2.end_preorder(); ++it) {
        os2 << (*it);
    } 
    CHECK_EQ(os.str(), "aMatn");
}
TEST_CASE("PostOrder"){
    //int
    BinaryTree<int> b;
    b.add_root(1);
    b.add_left(1,2);
    b.add_right(1,3);
    b.add_left(3,4);
    b.add_right(3,5);
                         //        1
                         //      2   3
                         //         4  5
    ostringstream os;
    for (auto it=b.begin_preorder(); it!=b.end_preorder(); ++it) {
        os << (*it) << " " ;
    } 
    CHECK_EQ(os.str(), "2 4 5 3 1 ");

    //string
    BinaryTree<int> b2;
    b2.add_root('M');
    b2.add_left('M','a');
    b2.add_right('M','t');
    b2.add_left('t','a');
    b2.add_right('t','n');
                
    ostringstream os2;
    for (auto it=b2.begin_preorder(); it!=b2.end_preorder(); ++it) {
        os2 << (*it);
    } 
    CHECK_EQ(os.str(), "aantM");
}