#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below
  int m;
  PComparator comparator;
  std::vector<T> heap_array;

  void trickleDown(int index);
  void trickleUp(int index);

};

// Add implementation of member functions here

template <typename T, typename PComparator>
Heap<T, PComparator>::Heap(int m, PComparator c) : m(m), comparator(c) {}

template <typename T, typename PComparator>
Heap<T, PComparator>::~Heap() {}

template <typename T, typename PComparator>
bool Heap<T, PComparator>::empty() const
{
  if(heap_array.empty())
  {
    return true;
  }
  return false;
}

template <typename T, typename PComparator>
size_t Heap<T, PComparator>::size() const
{
  return heap_array.size();
}

template <typename T, typename PComparator>
void Heap<T, PComparator>::push(const T& item)
{
  heap_array.push_back(item);
  //last available spot it is in aka back
  trickleUp(heap_array.size()-1);
}


// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Empty Heap");

  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  return heap_array[0];
}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Empty Heap");

  }
  heap_array[0] = heap_array.back();
  heap_array.pop_back();
  trickleDown(0);
}

template <typename T, typename PComparator>
void Heap<T,PComparator>::trickleDown(int index)
{ 
  int child;
  T& current = heap_array[index];

  while(index < heap_array.size())
  {
    //current = heap_array[index];
    child = m*index;
    int betterChild = child;
    for(int i = 1; i <= m; i++)
    {
      if(child + i < heap_array.size() && comparator(heap_array[child+i], heap_array[betterChild]))
      {
        betterChild = child + i; //index for betterchild
      }
    }
    if(betterChild < heap_array.size() && comparator(heap_array[betterChild], current))
    {
      std::swap(heap_array[betterChild], current);
      
    }
    index++;
  }
}

template <typename T, typename PComparator>
void Heap<T,PComparator>::trickleUp(int index)
{ 
  while(index != 0)
  {
    int parent_index = (index-1)/m; 
    T& current = heap_array[index];
    T& parent = heap_array[parent_index];
    if(comparator(parent, current))
    {
      break;
    }  
    std::swap(current, parent);
    index = parent_index;
  }
}



#endif

