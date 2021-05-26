#include<map>
#include<list>
using namespace std;

namespace ariel{
    template<typename T>
    class BinaryTree{
        struct Node{
            T _data;
            Node* right;
            Node* left;
            Node(T data) : _data(data), right(nullptr), left(nullptr){}
        };

        Node* _root;

        public:
            class iterator{
                protected:
                    Node* root;
                public:
                    iterator(Node *n = nullptr) : root(n){}
                    int size();
                    virtual iterator& operator++(){return *this;}
                    bool operator!=(const iterator){return false;}
                    T& operator*(){return root->_data;}
                    T* operator->(){return &(root->_data);}
                    // friend ostream& operator<<(ostream& out, const iterator it){return out;}
            };
            class PreIterator : public iterator{
                public:
                    iterator& operator++(){return *this;}
            };
            class InIterator : public iterator{
                public:
                    iterator& operator++(){return *this;}
            };
            class PostIterator : public iterator{
                public:
                    iterator& operator++(){return *this;}
            };
            BinaryTree& add_root(T r){return *this;}
            BinaryTree& add_right(T n, T v){return *this;}
            BinaryTree& add_left(T n, T v){return *this;}

            iterator begin(){return iterator(_root);}
            iterator end(){return iterator(nullptr);}

            iterator begin_preorder(){return iterator(_root);}
            iterator end_preorder(){return iterator(nullptr);}

            iterator begin_inorder(){return iterator(_root);}
            iterator end_inorder(){return iterator(nullptr);}

            iterator begin_postorder(){return iterator(_root);}
            iterator end_postorder(){return iterator(nullptr);}
            friend ostream& operator<<(std::ostream& out, const BinaryTree<T>& bt){return out;}
    };
}