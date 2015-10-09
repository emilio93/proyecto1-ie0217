#ifndef NODE_CLASS
#define NODE_CLASS

#include <stddef.h>//This gets NULL
#include "Color.hh"

template<typename T>
/**
 * @breif The node class defines a multiset element within it's red-black tree
 *        implementation. It contains the data and the multiplicity, which are
 *        related to the multiset concept. It also contains the tree elements
 *        which are, color, left child and right child.
 *        In addition, this implementation will know it's parent Node, (kind of
 *        like a doubly linked list).
 */
class Node{
    private:
        /**
         * @breif This is the data contained in the Node. Keep in mind that
         *        this class should have a way to be compared in order to arrange
         *        the tree.
         */
        T data;

        /**
         * @breif This number indicates how many elements does the node contain(how
         *        many can it provide).
         */
        int multiplicity;

        /**
         * @breif Indicates the parent Node.
         */
        Node * parent = NULL;

        /**
         * @breif Indicates the left child Node.
         */
        Node * left;

        /**
         * @breif Indicates the right child Node.
         */
        Node * right;

        /**
         * @breif Indicates the color of the Node.
         */
        Colors color;

    public:
        /**
         * @breif Creates a Node with data. By default, the Node's color is red.
         *        Also the multiplicity will be 1. This is the constructor for
         *        the root node.
         * @param data The data which the node will contain.
         */
        Node(T data);

        /**
         * @breif Creates a Node with data. By default, the Node's color is red.
         *        Also the multiplicity will be 1.
         * @param data The data which the node will contain.
         * @param parent The parent node.
         */
        Node(T data, Node<T> * parent);

        /**
         * @breif Destructs the Node.
         */
        ~Node(void);

        /**
         * @breif Returns data in the node.
         * @return The data in the node.
         */
        T getData(void);

        /**
         * @breif Returns the multiplicity of the node.
         * @return The multiplicity of the node.
         */
        int getMultiplicity(void);

        /**
         * @breif Returns the parent node.
         * @return The parent node.
         */
        const Node * getParent(void);

        /**
         * @breif Returns the left child node.
         * @return The left child node.
         */
        const Node * getLeft(void);

        /**
         * @breif Returns right child node.
         * @return The right child node.
         */
        const Node * getRight(void);

        /**
         * @breif Returns the nodes color.
         * @return The color of the current node.
         */
        Colors getColor(void);

        /**
         * @breif Toggle the Node's color.
         */
        void recolor(void);

        /**
         * @breif Changes the Node's color to a specific color.
         * @param c The color which the Node is going to have.
         */
        void recolor(Colors c);

        /**
         * @breif Adds an element, this is, increases the multiplicity.
         */
        void add(void);

        /**
         * @breif Removes an element, this is, decreases the multiplicity, when it
         *        reaches 0, it indicates returning true.
         * @return  True if the multipliciti reaches 0, ie, the Node must be deleted.
         */
        bool remove(void);

        /**
         * @breif Read the data within the Node.
         * @return  Data within the node
         */
        const T * read(void);

        /**
         * @breif Adds a child node on the left side;
         * @param left The pointer to the node to add.
         */
        void addLeft(Node<T> * left);

        /**
         * @breif Adds a child node on the right side;
         * @param left The pointer to the node to add.
         */
        void addRight(Node<T> * right);
};


/******************************
 *                            *
 *  THE CLASS IMPLEMENTATION  *
 *                            *
 ******************************/

template<typename T>
Node<T>::Node(T data) {
    this->data = data;
    this->parent = NULL;
    this->color = RED;
}

template<typename T>
Node<T>::Node(T data, Node<T> * parent) {
    this->data = data;
    this->parent = parent;
    this->color = this->Colors.RED;
    this->multiplicity = 1;
}

template<typename T>
Node<T>::~Node(void) {
    int a = 1;
}

template<typename T>
Colors Node<T>::getColor(void) {
    return this->color;
}

template<typename T>
void Node<T>::recolor(void) {
    if (this->color == RED) this->color = BLACK;
    else this->color = RED;
}

template<typename T>
void Node<T>::recolor(Colors c) {
    this->color = c;
}

template<typename T>
void Node<T>::add(void) {
    ++this->multiplicity;
}

template<typename T>
bool Node<T>::remove(void) {
    bool empty = false;
    --this->multiplicity;
    if (this->multiplicity == 0) {
        empty = true;
    }
    return empty;
}

template<typename T>
const T * Node<T>::read(void) {
    return this->data;
}

template<typename T>
void Node<T>::addLeft(Node<T> * left) {
    this->left = left;
}

template<typename T>
void Node<T>::addRight(Node<T> * right) {
    this->right = right;
}
#endif