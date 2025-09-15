#ifndef ULLISTSTR_H
#define ULLISTSTR_H
#include <string>

#define ARRSIZE 10
class ULListStr {
 public:

  int countNodes() const;

  struct Item { 
  // Note to self: 
  //when we want to access the data inside each node, we use prev*, next*, first, last, val[].
  // But, if we want to manipulate the node itself, we use what's listed in ULListStr
  // like head_, tail_, size_.
  // In this case, while struct Item represents one node, ULListStr is a class that represents the whole linked list.
  // What is difference between class, struct, and object?
  // Struct and class are both user defined, but struct defaults as public while class defaults
  // as private. An object is an instance (variable) created from the struct/class definition.
  // Use . with objects. Use -> with pointers to objects.

    std::string val[ARRSIZE];
    /**
     * first and last indicate the occupied/used 
     * elements of the array where first is an
     * inclusive index and last is an exclusive
     * index (i.e. first=0, last=0 indicates none
     * of the elements of the array are used and
     * first=0, last=ARRSIZE indicates the array
     * is fully occupied
     */
    size_t first, last;
    Item *prev;
    Item *next;

    /**
     * Default constructor
     */
    Item(){
      first = last = 0;
      prev = next = NULL;
    }
  };

  /**
   * Default constructor - empty list
   */
  ULListStr();

  /**
   * Destructor
   */
  ~ULListStr();

  /**
   * Returns the current number of items in the list (NOT the number of nodes)
   *   - MUST RUN in O(1)
   */
  size_t size() const;

  /**
   * Returns true if the list is empty, false otherwise
   *   - MUST RUN in O(1)
   */
  bool empty() const;

  /**
   * Adds a new value to the back of the list
   *   - MUST RUN in O(1)
   */
  void push_back(const std::string& val);

  /**
   * Removes a value from the back of the list
   *   - MUST RUN in O(1)
   */

  void pop_back();
  
  /**
   * Adds a new value to the front of the list.
   * If there is room before the 'first' value in
   * the head node add it there, otherwise, 
   * allocate a new head node.
   *   - MUST RUN in O(1)
   */
  void push_front(const std::string& val);

  /**
   * Removes a value from the front of the list
   *   - MUST RUN in O(1)
   */
  void pop_front();
  
  /**
   * Returns a const reference to the back element
   *   - MUST RUN in O(1)
   */
  std::string const & back() const;

  /**
   * Returns a const reference to the front element
   *   - MUST RUN in O(1)
   */
  std::string const & front() const;
  
  /**
   * Overwrites the old value at index, pos, with val
   *   - Can run in O(n)
   */
  void set(size_t pos, const std::string& val);

  /**
   * Returns the value at index, pos
   *   - Can run in O(n)
   */
  std::string& get(size_t pos);

  /**
   * Returns the value at index, pos
   *   - Can run in O(n)
   */
  std::string const & get(size_t pos) const;

  /**
   * Deletes all items in the list
   */
  void clear();

  int nodeCount() const;

 private:
  /** 
   * Returns a pointer to the item at index, loc,
   *  if loc is valid and NULL otherwise
   *   - MUST RUN in O(n) 
   */
  std::string* getValAtLoc(size_t loc) const;


  /**
   * Data members
   *  You MUST keep these members though you
   *  may add more if desired.
   */
  Item* head_;
  Item* tail_;
  size_t size_;
};

#endif