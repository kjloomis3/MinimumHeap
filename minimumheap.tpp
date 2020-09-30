#include "minimumheap.h"

template <typename Comparable>
size_t MinimumHeap<Comparable>::leftChild ( size_t index )
{
    return 2 * index + 1;
}

template <typename Comparable>
size_t MinimumHeap<Comparable>::rightChild ( size_t index )
{
    return 2 * index + 2;
}

template <typename Comparable>
size_t MinimumHeap<Comparable>::parent ( size_t index )
{
    return ( index - 1 ) / 2;
}

template <typename Comparable>
void MinimumHeap<Comparable>::minimumHeapify (size_t i)
{
    size_t l = leftChild(i);
    size_t r = rightChild(i);
    size_t smallest = i;
    if ( l < _size && _elements[l] < _elements[i] )
        smallest = l;
    else
        smallest = i;
    if ( r < _size && _elements[r] < _elements[smallest] )
        smallest = r;
    if ( smallest != i )
    {
        std::swap ( _elements[i], _elements[smallest] );
        minimumHeapify( smallest );
    }
}

template <typename Comparable>
void MinimumHeap<Comparable>::makeMinHeap()
{
    for ( size_t i=parent( _size - 1 ); i < _size; i-- )
        minimumHeapify(i);
}

template <typename Comparable>
MinimumHeap<Comparable>::MinimumHeap(size_t capacity)
    : _elements(capacity), _size{ 0 } {}

template <typename Comparable>
MinimumHeap<Comparable>::MinimumHeap(const std::vector<Comparable>& vec)
    : _elements{ vec }
{
    _size = _elements.size();
    makeMinHeap();
}

template <typename Comparable>
MinimumHeap<Comparable>::MinimumHeap(std::vector<Comparable>&& vec)
    : _elements{ std::move(vec) }
{
    _size = _elements.size();
    makeMinHeap();
}

template <typename Comparable>
size_t MinimumHeap<Comparable>::size() const
{
    return _size;
}

template <typename Comparable>
bool MinimumHeap<Comparable>::empty() const
{
    return _size==0;
}

template <typename Comparable>
void MinimumHeap<Comparable>::clear()
{
    _size = 0;
    _elements.clear();
}

template <typename Comparable>
const Comparable& MinimumHeap<Comparable>::top ( ) const
{
    if ( empty() ) { throw MinimumHeapUnderflowException(); }
    return _elements[0];
}

template <typename Comparable>
const Comparable& MinimumHeap<Comparable>::at ( size_t index ) const
{
    if ( index > _size ) { throw MinimumHeapIndexOutOfBoundsException(); }
    return _elements[index];
}

template <typename Comparable>
const Comparable& MinimumHeap<Comparable>::operator[] ( size_t index ) const
{
    return at ( index );
}

template <typename Comparable>
void MinimumHeap<Comparable>::insert ( const Comparable& element )
{
    Comparable copy = element;
    insert( std::move(copy) );
}

template <typename Comparable>
void MinimumHeap<Comparable>::insert ( Comparable&& obj)
{
    if ( _size == _elements.size() )
    {
        size_t newSize = 2;
        if ( _size != 0 ) { newSize = _size * 2; }
        _elements.resize( newSize );
    }
    _elements[_size] = obj;
    for (size_t i = _size; i > 0 && _elements[i] < _elements[ parent(i) ]; i = parent(i))
    {
        std::swap(_elements[i], _elements[ parent(i) ]);
    }
    _size++;
}

template <typename Comparable>
Comparable MinimumHeap<Comparable>::pop ()
{
    if ( empty() ) { throw MinimumHeapUnderflowException(); }
    Comparable min = std::move(_elements[0]);
    _size--;
    if ( _size > 0)
    {
        _elements[0] = std::move(_elements[_size]);
        minimumHeapify(0);
    }
    return std::move(min);
}

template <typename Comparable>
void MinimumHeap<Comparable>::pop (Comparable& element)
{
    if ( empty() ) { throw MinimumHeapUnderflowException(); }
    element = std::move(_elements[0]);
    _size--;
    if ( _size > 0)
    {
         _elements[0] = std::move(_elements[_size]);
         minimumHeapify(0);
    }
}

template <typename Comparable>
void MinimumHeap<Comparable>::output ( std::ostream& out ) const
{
    out << "MinimumHeap [";
    for (size_t i=0; i<_size; i++) {
      if ( i > 0 )
        out << ", ";
      out << _elements[i];
    }
    out << "]";
    out.flush();
}

template <typename Comparable>
std::string MinimumHeap<Comparable>::to_string ( )
{
    std::stringstream ss;
    std::string str;
    output ( ss );
    ss >> str;
    return str;
}

template <typename Comparable>
std::ostream& operator<< (std::ostream& out, const MinimumHeap<Comparable>& h)
{
    h.output(out);
    return out;
}

