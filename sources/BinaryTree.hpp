#include<map>
#include<list>
using namespace std;

namespace ariel{
    template<class T>
    class BinaryTree{
        // using iterator = typename std::list<T>::iterator;
        struct Node{
            T _data;
            Node* right;
            Node* left;
            Node(T data) : _data(data), right(nullptr), left(nullptr){}
        };

        Node* _root;
        list<T> allNodes;

        public:
            class iterator{
                protected:
                    Node* root;
                public:
                    iterator(Node *n = nullptr) : root(n){}
                    int size();
                    virtual iterator& operator++();
                    bool operator!=(const iterator);
                    iterator operator*();
                    T* operator->();
                    friend ostream& operator<<(std::ostream& out, const iterator it);
            };
            class PreIterator : public iterator{
                public:
                    iterator& operator++();
            };
            class InIterator : public iterator{
                public:
                    iterator& operator++();
            };
            class PostIterator : public iterator{
                public:
                    iterator& operator++();
            };
            BinaryTree& add_root(T r);
            BinaryTree& add_right(T n, T v);
            BinaryTree& add_left(T n, T v);

            typename list<T>::iterator begin();
            typename list<T>::iterator end();

            PreIterator begin_preorder();
            PreIterator end_preorder();

            InIterator begin_inorder();
            InIterator end_inorder();

            PostIterator begin_postorder();
            PostIterator end_postorder();
            template<typename E> friend ostream& operator<<(std::ostream& out, const BinaryTree<E>& bt);
    };
    template<typename T> BinaryTree<T>& BinaryTree<T>::add_root(T r) {return *this;}
    template<typename T> BinaryTree<T>& BinaryTree<T>::add_right(T n, T v) {return *this;}
    template<typename T> BinaryTree<T>& BinaryTree<T>::add_left(T n, T v) {return *this;}
}