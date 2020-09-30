#include <algorithm>
#include <ctime>
#include "minimumheap.h"

using namespace std;

template <typename Comparable>
bool is_min_heap( const MinimumHeap<Comparable>& heap, size_t index = 0 )
{
    if ( heap.size() == 0 ) return true;
    if ( index >= heap.size() ) return false;

    size_t left = index*2+1;
    size_t right = index*2+2;
    if ( right < heap.size() )
           return heap[index] <= heap[left] && heap[index] <= heap[right]
                   && is_min_heap ( heap, left ) && is_min_heap ( heap, right );
    else if ( left < heap.size() )
           return heap[index] <= heap[left] && is_min_heap ( heap, left );
    else
        return true;
}

/**
 * Int Test 0: An empty minimum heap of integers.
 */
void test_int_empty ( void )
{
    cout << "**********************************************************************" << endl
         << "Test MinHeap Empty:" << endl
         << "**********************************************************************" << endl
         << "\tExpected: MinimumHeap: []" << endl
         << "\t  Actual: ";

    MinimumHeap<int> heap;
    cout << heap << endl;
    if ( heap.empty() )
        cout << "\tempty?: true" << endl;
    else
        cout << "\tempty?: false" << endl;
    if ( is_min_heap(heap, 0) )
        cout << "\tmin heap?: true" << endl;
    else
        cout << "\tmin heap?: false" << endl;
}

/**
 * Int Test 1: An minimum heap of integers: 5, 4, 3, 2, 1.
 */
void test_int_insert ( void )
{
    cout << "**********************************************************************" << endl
         << "Test MinHeap Insert (order of elements may vary):" << endl
         << "**********************************************************************" << endl
         << "\tExpected: MinimumHeap: [1, 2, 3, 4, 5]" << endl
         << "\t  Actual: ";

    MinimumHeap<int> heap;
    for ( int i=5; i>0; i-- )
        heap.insert(i);
    cout << heap << endl;
    if ( heap.empty() )
        cout << "\tempty?: true" << endl;
    else
        cout << "\tempty?: false" << endl;
    if ( is_min_heap(heap, 0) )
        cout << "\tmin heap?: true" << endl;
    else
        cout << "\tmin heap?: false" << endl;
}

/**
 * Int Test 2: creates heap based on existing vector: 5, 4, 3, 2, 1.
 */
void test_int_constr_vector ( void )
{
    cout << "**********************************************************************" << endl
         << "Test MinHeap Constr From Vector: (order of elements may vary)" << endl
         << "**********************************************************************" << endl
         << "\tExpected: MinimumHeap: [1, 2, 3, 4, 5]" << endl
         << "\t  Actual: ";

    vector<int> vec {5, 4, 3, 2, 1};
    MinimumHeap<int> heap (vec);
    cout << heap << endl;

    if ( heap.empty() )
        cout << "\tempty?: true" << endl;
    else
        cout << "\tempty?: false" << endl;
    if ( is_min_heap(heap, 0) )
        cout << "\tmin heap?: true" << endl;
    else
        cout << "\tmin heap?: false" << endl;
}

/**
 * Int Test 3: creates heap based on inserting: 5, 4, 3, 2, 1. Output
 * all the elements from the heap one at a time.
 */
void test_int_pop_from_insert ( void )
{
    cout << "**********************************************************************" << endl
         << "Test MinHeap Pop after insert" << endl
         << "**********************************************************************" << endl
         << "\tExpected: 1 2 3 4 5" << endl
         << "\t  Actual: ";

    MinimumHeap<int> heap;
    for ( int i=5; i>0; i-- )
        heap.insert(i);
    while ( !heap.empty() )
        cout << heap.pop() << " ";
    cout << endl;
}


/**
 * Int Test 4: creates heap based on existing vector: 5, 4, 3, 2, 1. Output
 * all the elements from the heap one at a time.
 */
void test_int_pop_from_vector ( void )
{
    cout << "**********************************************************************" << endl
         << "Test MinHeap Pop after Vector constr:" << endl
         << "**********************************************************************" << endl
         << "\tExpected: 1 2 3 4 5" << endl
         << "\t  Actual: ";

    vector<int> vec {5, 4, 3, 2, 1};
    MinimumHeap<int> heap (vec);
    while ( !heap.empty() )
        cout << heap.pop() << " ";
    cout << endl;
}

/**
 * Double Test 5: An empty minimum heap of doubles.
 */
void test_double_empty ( void )
{
    cout << "**********************************************************************" << endl
         << "Test MinHeap Empty:" << endl
         << "**********************************************************************" << endl
         << "\tExpected: MinimumHeap: []" << endl
         << "\t  Actual: ";

    MinimumHeap<double> heap;
    cout << heap << endl;
    if ( heap.empty() )
        cout << "\tempty?: true" << endl;
    else
        cout << "\tempty?: false" << endl;
    if ( is_min_heap(heap, 0) )
        cout << "\tmin heap?: true" << endl;
    else
        cout << "\tmin heap?: false" << endl;
}

/**
 * Double Test 6: An minimum heap of doubles: 5, 4, 3, 2, 1.
 */
void test_double_insert ( void )
{
    cout << "**********************************************************************" << endl
         << "Test MinHeap Insert (order of elements may vary):" << endl
         << "**********************************************************************" << endl
         << "\tExpected: MinimumHeap: [1, 2, 3, 4, 5]" << endl
         << "\t  Actual: ";

    MinimumHeap<double> heap;
    for ( int i=5; i>0; i-- )
        heap.insert(double(i));
    cout << heap << endl;
    if ( heap.empty() )
        cout << "\tempty?: true" << endl;
    else
        cout << "\tempty?: false" << endl;
    if ( is_min_heap(heap, 0) )
        cout << "\tmin heap?: true" << endl;
    else
        cout << "\tmin heap?: false" << endl;
}

/**
 * Double Test 7: creates heap based on existing vector: 5, 4, 3, 2, 1.
 */
void test_double_constr_vector ( void )
{
    cout << "**********************************************************************" << endl
         << "Test MinHeap Constr From Vector: (order of elements may vary)" << endl
         << "**********************************************************************" << endl
         << "\tExpected: MinimumHeap: [1, 2, 3, 4, 5]" << endl
         << "\t  Actual: ";

    vector<double> vec {5, 4, 3, 2, 1};
    MinimumHeap<double> heap (vec);
    cout << heap << endl;

    if ( heap.empty() )
        cout << "\tempty?: true" << endl;
    else
        cout << "\tempty?: false" << endl;
    if ( is_min_heap(heap, 0) )
        cout << "\tmin heap?: true" << endl;
    else
        cout << "\tmin heap?: false" << endl;
}

/**
 * Double Test 8: creates heap based on inserting: 5, 4, 3, 2, 1. Output
 * all the elements from the heap one at a time.
 */
void test_double_pop_from_insert ( void )
{
    cout << "**********************************************************************" << endl
         << "Test MinHeap Pop after insert" << endl
         << "**********************************************************************" << endl
         << "\tExpected: 1 2 3 4 5" << endl
         << "\t  Actual: ";

    MinimumHeap<double> heap;
    for ( int i=5; i>0; i-- )
        heap.insert((double)i);
    while ( !heap.empty() )
        cout << heap.pop() << " ";
    cout << endl;
}


/**
 * Double Test 9: creates heap based on existing vector: 5, 4, 3, 2, 1. Output
 * all the elements from the heap one at a time.
 */
void test_double_pop_from_vector ( void )
{
    cout << "**********************************************************************" << endl
         << "Test MinHeap Pop after Vector constr:" << endl
         << "**********************************************************************" << endl
         << "\tExpected: 1 2 3 4 5" << endl
         << "\t  Actual: ";

    vector<double> vec {5, 4, 3, 2, 1};
    MinimumHeap<double> heap (vec);
    while ( !heap.empty() )
        cout << heap.pop() << " ";
    cout << endl;
}

/**
 * String Test 10: creates heap based on inserting: "This", "is", "just" "a" "test". Output
 * all the elements from the heap one at a time.
 */
void test_string_pop_from_insert ( void )
{
    cout << "**********************************************************************" << endl
         << "Test MinHeap Pop after insert" << endl
         << "**********************************************************************" << endl
         << "\tExpected: This a is just test" << endl
         << "\t  Actual: ";

    MinimumHeap<string> heap;
    heap.insert("This");
    heap.insert("is");
    heap.insert("just");
    heap.insert("a");
    heap.insert("test");
    while ( !heap.empty() )
    {
        string s = heap.pop();
        cout << s << " ";
    }
    cout << endl;
}

/**
 * Int Test 11: creates a large number of minimum heaps of integers and verifies
 * that each passes the min heap test..
 */
void test_int_stress ( void )
{
    cout << "**********************************************************************" << endl
         << "Test MinHeap Integer Stress:" << endl
         << "**********************************************************************" << endl;

    vector<int> vec;
    MinimumHeap<int> heap;

    cout << "\tTrial\tEmpty?\tMin Heap?\tFirst 10 Elements" << endl;

    // Fill the vector
    for ( int i=1; i<=7500; i++)
        vec.push_back(1 + std::rand()/((RAND_MAX + 1u)/10000));

    for ( int i=0; i<100; i++ )
    {
        random_shuffle(vec.begin(), vec.end());
        for ( size_t j=0; j<5000; j++ )
            heap.insert(vec[j]);
        cout << "\t" << i << ":";
        if ( heap.empty() )
            cout << "\ttrue";
        else
            cout << "\tfalse";
        if ( is_min_heap(heap, 0) )
            cout << "\ttrue";
        else
            cout << "\tfalse";
        cout << "\t\t";
        for ( int j=0; j<10; j++ )
            cout << heap.pop() << " ";
        cout << endl;
        heap.clear();
    }

}

/**
 * Int Test 12: creates a large number of minimum heaps of integers and verifies
 * that each passes the min heap test..
 */
void test_double_stress ( void )
{
    cout << "**********************************************************************" << endl
         << "Test MinHeap Double Stress:" << endl
         << "**********************************************************************" << endl;

    vector<double> vec;
    MinimumHeap<double> heap;

    cout << "\tTrial\tEmpty?\tMin Heap?\tFirst 10 Elements" << endl;

    // Fill the vector
    for ( int i=1; i<=7500; i++)
        vec.push_back(1 + std::rand()/((RAND_MAX + 1u)/1000/(double)100));

    for ( int i=0; i<100; i++ )
    {
        random_shuffle(vec.begin(), vec.end());
        for ( size_t j=0; j<5000; j++ )
            heap.insert(vec[j]);
        cout << "\t" << i << ":";
        if ( heap.empty() )
            cout << "\ttrue";
        else
            cout << "\tfalse";
        if ( is_min_heap(heap, 0) )
            cout << "\ttrue";
        else
            cout << "\tfalse";
        cout << "\t\t";
        for ( int j=0; j<10; j++ )
            cout << heap.pop() << " ";
        cout << endl;
        heap.clear();
    }

}

/**
 * Runs a series of tests on the template class MinimumHeap
 */
int main ( void )
{
    srand(time(nullptr));
    test_int_empty( );
    test_int_insert( );
    test_int_constr_vector( );
    test_int_pop_from_insert( );
    test_int_pop_from_vector( );
    test_double_empty( );
    test_double_insert( );
    test_double_constr_vector( );
    test_double_pop_from_insert( );
    test_double_pop_from_vector( );
    test_string_pop_from_insert( );
    test_int_stress( );
    test_double_stress( );
    return 0;
}
