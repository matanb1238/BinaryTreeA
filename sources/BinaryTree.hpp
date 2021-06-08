
#include<vector>
#include<map>
// using namespace std;


namespace ariel{
    template<typename T>
    class BinaryTree{
        struct Node{
            Node* right = nullptr;
            Node* left = nullptr;
            T _data;
            Node(T data) : _data(data), right(nullptr), left(nullptr){}
            Node(const Node* other) : _data(0), right(nullptr), left(nullptr){
                _data = other->_data; 
                if (other->right != nullptr){right = new Node(other->right);}
                if (other->left != nullptr){left = new Node(other->left);}
            }
        };

        Node* _root;
        int size = 0;
        public:
            class iterator{
                private:
                    unsigned long index;
                    std::vector<Node*> list;
                public:
                    iterator(Node *n = nullptr) : index(0){
                        if(!n) {return;}
                        InIterator(n->left);
                        list.push_back(n);
                        InIterator(n->right);
                    }
                    iterator operator++(int){
                        iterator temp{*this};
                        ++index;
                        return temp;
                    }
                    iterator& operator++(){
                        ++index;
                        return *this;
                    }
                    T& operator*(){return list.at(index)->_data;}
                    T* operator->(){return &(list.at(index)->_data);}
                    bool operator==(const iterator &it) const {
                        return list.at(index) == it.list.at(it.index);
                    }
                    bool operator!=(const iterator &it) const {
                        return !(*this == it);
                    }
            };
            class PreIterator : public iterator{
                std::vector<Node*> list;
                unsigned long index;
                public:
                    PreIterator(Node *n = nullptr) : index(0){
                        if(!n) {return;}
                        list.push_back(n);
                        PreIterator(n->left);
                        PreIterator(n->right);
                    }
            };
            class InIterator : public iterator{
                std::vector<Node*> list;
                unsigned long index;
                public:
                    InIterator(Node *n = nullptr) : index(0){
                        if(!n) {return;}
                        PreIterator(n->left);
                        list.push_back(n);
                        PreIterator(n->right);
                    }
            };
            class PostIterator : public iterator{
                std::vector<Node*> list;
                unsigned long index;
                public:
                    PostIterator(Node *n = nullptr) : index(0){
                        if(!n) {return;}
                        PreIterator(n->left);
                        PreIterator(n->right);
                        list.push_back(n);
                    }
            };
            int getSize() const{
                return this->size;
            }
            BinaryTree(): _root(nullptr){}
            BinaryTree(const BinaryTree& other) : _root(new Node(other._root)), size(other.getSize()){}

            BinaryTree(BinaryTree &&other) noexcept : size(other.getSize()) {
                _root = other._root;
                other._root = nullptr;
            }

             ~BinaryTree(){
                 delete this->_root;
            }
            Node* getNode(Node *n ,T data){
                if(!n) {return nullptr;}
                if(n->_data == data) {return n;}
                Node* node = getNode(n->left, data);
                if(node) {return node;}
                return getNode(n->right, data);
            }
            BinaryTree& add_root(const T& value){
                if(_root) { _root->_data = value; }
                else { _root = new Node(value);}
                size = 1;
                return *this;
            }
            BinaryTree& add_right(const T& node, const T& value){
                Node* n = getNode(_root, node);
                if(!n){std::__throw_invalid_argument("Not exist");}
                if(n->right == nullptr) {
                    n->right = new Node(value);
                    this->size++;
                }
                else {
                    n->right->_data = value;
                }
                // m.insert(pair<T, *Node>(*value, n->right));
                //m.insert({*value, n->right});
                return *this;
            }
            BinaryTree& add_left(const T& node, const T& value){
                Node* n = getNode(_root, node);
                if(!n){std::__throw_invalid_argument("Not exist");}
                if(n->left == nullptr) {
                    n->left = new Node(value);
                    this->size++;
                }
                else {
                    n->left->_data = value;
                }
                // m.insert(pair<T, *Node>(*value, n->left));
                //m.insert({*value, n->left});
                return *this;
            }

            InIterator begin(){return InIterator(_root);}
            InIterator end(){return InIterator(nullptr);}

            PreIterator begin_preorder(){return PreIterator(_root);}
            PreIterator end_preorder(){return PreIterator(nullptr);}

            InIterator begin_inorder(){return InIterator(_root);}
            InIterator end_inorder(){return InIterator(nullptr);}

            PostIterator begin_postorder(){return PostIterator(_root);}
            PostIterator end_postorder(){return PostIterator(nullptr);}

            BinaryTree& operator=(const BinaryTree& other) {
                if (this == &other) {return *this;}
                delete(this->_root);
                _root = new Node(other._root);
                return *this;
            }

            BinaryTree& operator=(BinaryTree&& other) noexcept {
                *this = std::move(other);
                return *this;
            }
            friend std::ostream& operator<<(std::ostream& os, const BinaryTree<T>& bt){return os;}
    };
}

