#include <stdexcept>
#include <iostream>
using namespace std;

template <class T>
struct Node {
    T val;         // associated data
    Node left, right;  // left and right subtrees
    int size;          // number of nodes in subtree
};

template <class T>
Node createNode(T val, int size) {
    Node node;
    node.val = val;
    node.size = size;
    return node;
}

template <class T>
bool isEmpty(Node<T> x) {
    return size(x) == 0;
}

template <class T>
int size(Node<T> x) {
    if (x == NULL) 
        return 0;
    else 
        return x.size;
}

template <class T>
bool contains(Node<T> root, T x) {
    if (key == NULL)
        throw invalid_argument("argument to contains() is null");
    return get(key) != NULL;
}

template <class T>
T get(Node<T> x, T key) {
    if (key == NULL)
        throw invalid_argument("calls get() with a null key");
    if (x == NULL)
        return NULL;
    if (key < x.val)
        return get(x.left, key);
    else if (key > x.val) 
        return get(x.right, key);
    else
        return x.val;
}

template <class T>
Node put(Node<T> x, Key key) {
    if (x == null) return new Node(key, val, 1);
    int cmp = key.compareTo(x.key);
    if      (cmp < 0) x.left  = put(x.left,  key, val);
    else if (cmp > 0) x.right = put(x.right, key, val);
    else              x.val   = val;
    x.size = 1 + size(x.left) + size(x.right);
    return x;
}


    /**
     * Removes the smallest key and associated value from the symbol table.
     *
     * @throws NoSuchElementException if the symbol table is empty
     */
    public void deleteMin() {
        if (isEmpty()) throw new NoSuchElementException("Symbol table underflow");
        root = deleteMin(root);
        assert check();
    }

    private Node deleteMin(Node x) {
        if (x.left == null) return x.right;
        x.left = deleteMin(x.left);
        x.size = size(x.left) + size(x.right) + 1;
        return x;
    }

    /**
     * Removes the largest key and associated value from the symbol table.
     *
     * @throws NoSuchElementException if the symbol table is empty
     */
    public void deleteMax() {
        if (isEmpty()) throw new NoSuchElementException("Symbol table underflow");
        root = deleteMax(root);
        assert check();
    }

    private Node deleteMax(Node x) {
        if (x.right == null) return x.left;
        x.right = deleteMax(x.right);
        x.size = size(x.left) + size(x.right) + 1;
        return x;
    }

    /**
     * Removes the specified key and its associated value from this symbol table     
     * (if the key is in this symbol table).    
     *
     * @param  key the key
     * @throws IllegalArgumentException if {@code key} is {@code null}
     */
void delete(Key key) {
    if (key == null) throw new IllegalArgumentException("calls delete() with a null key");
    root = delete(root, key);
}

Node delete(Node x, Key key) {
    if (x == null) 
        return null;

    int cmp = key.compareTo(x.key);
    if      (cmp < 0) x.left  = delete(x.left,  key);
    else if (cmp > 0) x.right = delete(x.right, key);
    else { 
        if (x.right == null) return x.left;
        if (x.left  == null) return x.right;
        Node t = x;
        x = min(t.right);
        x.right = deleteMin(t.right);
        x.left = t.left;
    } 
    x.size = size(x.left) + size(x.right) + 1;
    return x;
} 