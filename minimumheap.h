#ifndef MINIMUMHEAP_H
#define MINIMUMHEAP_H

#include <vector>
#include <ostream>
#include <iostream>
#include <sstream>
#include <memory>

/**
 * @brief Exception: An operation has been attempted on an empty MinimumHeap.
 */
class MinimumHeapUnderflowException {};

/**
 * @brief Exception: An operation has been attempted on an element "outside" the MinimumHeap.
 */
class MinimumHeapIndexOutOfBoundsException {};

/**
 * A minimum heap of Comparable elements. The MinimumHeap is a balanced tree
 * structure such that each element of the MinimumHeap must be less than than
 * any of its descendant elements.
 *
 * The root element in the heap is indexed at position 0. Subsequent elements are
 * indexed such that the the index of a left element is 2 * parent index + 1 and
 * the index of the right element is 2 * parent index + 2.
 *
 * @author Ken Loomis (https://github.com/kjloomis3)
 */
template <typename Comparable> class MinimumHeap {

private:

    /** The _elements of the MinimumHeap arranged in a vector. **/
    std::vector<Comparable> _elements;

    /** The current size of the MinimumHeap **/
    size_t _size;

    /**
     * Produces the index of the left child of the given index.
     * @param index: the index of the parent element
     * @return the index of the left child.
     */
    static size_t leftChild ( size_t index );

    /**
     * Produces the index of the right child of the given index.
     * @param index: the index of the parent element
     * @return the index of the left child.
     */
    static size_t rightChild ( size_t index );

    /**
     * Produces the index of the parent of the given index.
     * @param index: the index of the child element
     * @return the index of the parent.
     */
    static size_t parent ( size_t index );

    /**
     * Moves the element at the given index down in the heap as necessary
     * to preserve the minimum property of the MinimumHeap.
     * @param index: the index of the element to minify
     */
    void minimumHeapify (size_t i);

    /**
     * Minifies the heap such that the resulting heap is a MinimumHeap.
     */
    void makeMinHeap();

 public:

    /**
     * Instantiate a MinimumHeap given the initial capacity (default = 2)
     * of the underlying vector.
     * @param capacity: the initial capacity.
    **/
    explicit MinimumHeap(size_t capacity = 2);

    /**
     * Instantiate a MinimumHeap by copying an existing MinimumHeap.
     * (Copy Constructor)
     * @param rhs: the MinimumHeap to copy.
    **/
    MinimumHeap(const MinimumHeap& rhs) = default;

    /**
     * Instantiate a MinimumHeap by assigning an existing MinimumHeap.
     * (Copy Assignment Constructor)
     * @param rhs: the MinimumHeap to copy.
    **/
    MinimumHeap& operator=(const MinimumHeap& rhs) = default;

    /**
     * Instantiate a MinimumHeap by moving elements from an existing temporary
     * MinimumHeap.
     * (Move Constructor)
     * @param rhs: the MinimumHeap to move elements from.
    **/
    MinimumHeap(MinimumHeap&& rhs) = default;

    /**
     * Instantiate a MinimumHeap by moving elements from an assigned temporary
     * MinimumHeap.
     * (Move Assignment Constructor)
     * @param rhs: the MinimumHeap to move elements from.
    **/
    MinimumHeap& operator=(MinimumHeap&& rhs) = default;

    /**
     * Destructor
    **/
    ~MinimumHeap() = default;

    /**
     * Instantiate a MinimumHeap by copying elements from the given vector.
     * @param vec: the vector to copy elements from.
    **/
    MinimumHeap(const std::vector<Comparable>& vec);

    /**
     * Instantiate a MinimumHeap by moving elements from the given vector.
     * @param vec: the vector to move elements from.
    **/
    MinimumHeap(std::vector<Comparable>&& vec);

    /**
     * Produces the current size of the MinimumHeap.
     * @return number of elements in the MinimumHeap.
     */
    size_t size() const;

    /**
     * Determines if the MinimumHeap is empty (it contains no elements).
     * @return true if the MinimumHeap is empty, false otherwise.
     */
    bool empty() const;

    /**
     * Resets the MinimumHeap to be empty (it will contain no elements).
     * The current capacity of the heap remains unchanged.
     * @return true if the heap is empty, false otherwise.
     */
    void clear();

    /**
     * Produces the element at the top of the heap (the smallest element in
     * the heap) without removing it from the heap.
     * @return the value of the smallest element.
     * @throws MinimumHeapUnderflowException if the MinimumHeap is empty
     */
    const Comparable& top ( ) const;

    /**
     * Produces the element in the MinimumHeap at the given index position.
     * Positions are indexed from the first element (index 0) and increase
     * with each left-to-right, within each depth such that the element at
     * index 1 is the left element of index 0, and index 2 is the right
     * element of index 0.
     * @param index: the index of the element to return.
     * @return the value of the element at the given index.
     * @throws MinimumHeapIndexOutOfBoundsException if the index is not within
     * the bounds (0, size].
     */
    const Comparable& at ( size_t index ) const;

    /**
     * Produces the element in the MinimumHeap at the given index position.
     * Positions are indexed from the first element (index 0) and increase
     * with each left-to-right, within each depth such that the element at
     * index 1 is the left element of index 0, and index 2 is the right
     * element of index 0.
     * @param index: the index of the element to return.
     * @return the value of the element at the given index.
     * @throws MinimumHeapIndexOutOfBoundsException if the index is not within
     * the bounds (0, size].
     */
    const Comparable& operator[] ( size_t index ) const;

    /**
     * Inserts the given element into the MinimumHeap at the appropriate position
     * in the heap such that the minimum property of the heap is preserved.
     *
     * If the heap is full at the time of insertion, the capacity of the heap
     * is doubled in size.
     *
     * @param element: the element to be inserted into the heap
     */
    void insert ( const Comparable& element );

    /**
     * Inserts the given element into the MinimumHeap by moving it from it current
     * location to the appropriate position in the heap such that the minimum
     * property of the heap is preserved.
     *
     * If the heap is full at the time of insertion, the capacity of the heap
     * is doubled in size.
     *
     * @param element: the element to be inserted (moved) into the heap
     */
    void insert ( Comparable&& obj);

    /**
     * Produces the element at the top of the heap (the smallest element in
     * the heap) and removes it from the heap preserving the minimum property
     * of the heap.
     * @return the value of the smallest element.
     * @throws MinimumHeapUnderflowException if the MinimumHeap is empty
     */
    Comparable pop ();

    /**
     * Produces the element at the top of the heap (the smallest element in
     * the heap) implicitly moving it to the given parameter and removes it
     * from the heap preserving the minimum property of the heap.
     * @param element: the variable that will contain the smallest element
     * from the heap, if such an element exists.
     * @throws MinimumHeapUnderflowException if the MinimumHeap is empty
     */
    void pop (Comparable& element);

    /**
     * Produces the elements in MinimumHeap to the given output stream. The
     * format of the output is such that the heap with elements 1, 2, 3, 4,
     * and 5 will be outputted as "MinimumHeap [1, 2, 3, 4, 5]"
     * @param out
     */
    void output ( std::ostream& out = std::cout ) const;

    /**
     * Produces the elements in MinimumHeap as a string. The format of the string
     * is such that the heap with elements 1, 2, 3, 4, and 5 will contain
     * "MinimumHeap [1, 2, 3, 4, 5]"
     * @param out: the output stream to be updated.
     */
    std::string to_string ( );

};

/**
 * Produces the elements in MinimumHeap to the given output stream. The
 * format of the output is such that the heap with elements 1, 2, 3, 4,
 * and 5 will be outputted as "MinimumHeap [1, 2, 3, 4, 5]"
 * @param out: the output stream to be updated.
 */
template <typename Comparable>
std::ostream& operator<< (std::ostream& out, const MinimumHeap<Comparable>& h);

/** Includes the templated class implementation to be compiled during usage of
 * the class. **/
#include "minimumHeap.tpp"

#endif // MINIMUMHEAP_H
