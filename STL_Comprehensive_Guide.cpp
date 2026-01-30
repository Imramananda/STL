/*
================================================================================
                    COMPREHENSIVE C++ STL GUIDE
================================================================================
    Covers: vector, list, set, map, unordered_set, unordered_map, queue, stack
    Author: Ramananda Yadav
    C++ Standard: C++17/C++20
================================================================================
*/

#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>
#include <string>

using namespace std;

// Helper function to print section headers
void printSection(const string& title) {
    cout << "\n" << string(80, '=') << endl;
    cout << "  " << title << endl;
    cout << string(80, '=') << endl;
}

void printSubSection(const string& title) {
    cout << "\n--- " << title << " ---" << endl;
}

/*
================================================================================
                            1. VECTOR
================================================================================
    - Dynamic array
    - Contiguous memory
    - Random access: O(1)
    - Insert/Delete at end: O(1) amortized
    - Insert/Delete at middle: O(n)
    - Header: <vector>
================================================================================
*/
void vectorDemo() {
    printSection("VECTOR - Dynamic Array");
    
    // ==================== CONSTRUCTORS ====================
    printSubSection("1. Constructors");
    
    vector<int> v1;                           // Empty vector
    vector<int> v2(5);                        // 5 elements, default initialized (0)
    vector<int> v3(5, 10);                    // 5 elements, all initialized to 10
    vector<int> v4{1, 2, 3, 4, 5};            // Initializer list
    vector<int> v5(v4);                       // Copy constructor
    vector<int> v6(v4.begin(), v4.end());    // Range constructor
    vector<int> v7(move(v5));                 // Move constructor
    
    cout << "v3 (5 elements of 10): ";
    for(int x : v3) cout << x << " ";
    cout << endl;
    
    cout << "v4 (initializer list): ";
    for(int x : v4) cout << x << " ";
    cout << endl;
    
    // ==================== CAPACITY FUNCTIONS ====================
    printSubSection("2. Capacity Functions");
    
    vector<int> vec{1, 2, 3, 4, 5};
    
    cout << "size(): " << vec.size() << endl;           // Number of elements
    cout << "capacity(): " << vec.capacity() << endl;   // Allocated storage
    cout << "max_size(): " << vec.max_size() << endl;   // Maximum possible size
    cout << "empty(): " << (vec.empty() ? "true" : "false") << endl;
    
    vec.reserve(100);    // Request capacity change
    cout << "After reserve(100), capacity(): " << vec.capacity() << endl;
    
    vec.shrink_to_fit(); // Reduce capacity to fit size
    cout << "After shrink_to_fit(), capacity(): " << vec.capacity() << endl;
    
    vec.resize(10);      // Resize to 10 elements (new elements default initialized)
    cout << "After resize(10), size(): " << vec.size() << endl;
    
    vec.resize(15, 99);  // Resize to 15, new elements initialized to 99
    cout << "After resize(15, 99): ";
    for(int x : vec) cout << x << " ";
    cout << endl;
    
    // ==================== ELEMENT ACCESS ====================
    printSubSection("3. Element Access");
    
    vector<int> v{10, 20, 30, 40, 50};
    
    cout << "v[2] (operator[]): " << v[2] << endl;      // No bounds checking
    cout << "v.at(2): " << v.at(2) << endl;             // With bounds checking
    cout << "v.front(): " << v.front() << endl;         // First element
    cout << "v.back(): " << v.back() << endl;           // Last element
    cout << "v.data(): " << v.data() << endl;           // Pointer to underlying array
    cout << "*v.data(): " << *v.data() << endl;         // First element via pointer
    
    // ==================== MODIFIERS ====================
    printSubSection("4. Modifiers");
    
    vector<int> mv{1, 2, 3};
    
    // push_back and emplace_back
    mv.push_back(4);              // Copy/move element to end
    mv.emplace_back(5);           // Construct element in-place at end
    cout << "After push_back(4), emplace_back(5): ";
    for(int x : mv) cout << x << " ";
    cout << endl;
    
    // pop_back
    mv.pop_back();                // Remove last element
    cout << "After pop_back(): ";
    for(int x : mv) cout << x << " ";
    cout << endl;
    
    // insert
    mv.insert(mv.begin() + 1, 100);           // Insert 100 at position 1
    cout << "After insert at pos 1: ";
    for(int x : mv) cout << x << " ";
    cout << endl;
    
    mv.insert(mv.begin(), 3, 0);              // Insert 3 copies of 0 at beginning
    cout << "After insert 3 zeros at begin: ";
    for(int x : mv) cout << x << " ";
    cout << endl;
    
    vector<int> toInsert{99, 98, 97};
    mv.insert(mv.end(), toInsert.begin(), toInsert.end());  // Insert range
    cout << "After insert range at end: ";
    for(int x : mv) cout << x << " ";
    cout << endl;
    
    // emplace
    mv.emplace(mv.begin() + 2, 555);          // Construct in-place at position
    cout << "After emplace at pos 2: ";
    for(int x : mv) cout << x << " ";
    cout << endl;
    
    // erase
    mv.erase(mv.begin());                     // Erase first element
    cout << "After erase first: ";
    for(int x : mv) cout << x << " ";
    cout << endl;
    
    mv.erase(mv.begin(), mv.begin() + 2);     // Erase range
    cout << "After erase range [0,2): ";
    for(int x : mv) cout << x << " ";
    cout << endl;
    
    // clear
    vector<int> toClear{1, 2, 3};
    toClear.clear();                          // Remove all elements
    cout << "After clear(), size: " << toClear.size() << endl;
    
    // swap
    vector<int> sv1{1, 2, 3};
    vector<int> sv2{10, 20, 30, 40};
    sv1.swap(sv2);                            // Swap contents
    cout << "After swap, sv1: ";
    for(int x : sv1) cout << x << " ";
    cout << endl;
    
    // assign
    vector<int> av;
    av.assign(5, 100);                        // Assign 5 copies of 100
    cout << "After assign(5, 100): ";
    for(int x : av) cout << x << " ";
    cout << endl;
    
    av.assign({1, 2, 3, 4});                  // Assign from initializer list
    cout << "After assign({1,2,3,4}): ";
    for(int x : av) cout << x << " ";
    cout << endl;
    
    // ==================== ITERATORS ====================
    printSubSection("5. Iterators");
    
    vector<int> iv{10, 20, 30, 40, 50};
    
    cout << "Forward iteration (begin/end): ";
    for(auto it = iv.begin(); it != iv.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
    
    cout << "Reverse iteration (rbegin/rend): ";
    for(auto it = iv.rbegin(); it != iv.rend(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
    
    cout << "Const iteration (cbegin/cend): ";
    for(auto it = iv.cbegin(); it != iv.cend(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
    
    // ==================== 2D VECTOR ====================
    printSubSection("6. 2D Vector");
    
    // Creating 2D vector
    vector<vector<int>> matrix(3, vector<int>(4, 0));  // 3x4 matrix of zeros
    
    // Initialize with values
    int val = 1;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 4; j++) {
            matrix[i][j] = val++;
        }
    }
    
    cout << "2D Vector (3x4 matrix):" << endl;
    for(const auto& row : matrix) {
        for(int x : row) {
            cout << x << "\t";
        }
        cout << endl;
    }
}

/*
================================================================================
                            2. LIST
================================================================================
    - Doubly linked list
    - Non-contiguous memory
    - No random access
    - Insert/Delete anywhere: O(1) with iterator
    - Search: O(n)
    - Header: <list>
================================================================================
*/
void listDemo() {
    printSection("LIST - Doubly Linked List");
    
    // ==================== CONSTRUCTORS ====================
    printSubSection("1. Constructors");
    
    list<int> l1;                             // Empty list
    list<int> l2(5);                          // 5 default elements
    list<int> l3(5, 10);                      // 5 elements of value 10
    list<int> l4{1, 2, 3, 4, 5};              // Initializer list
    list<int> l5(l4);                         // Copy constructor
    list<int> l6(l4.begin(), l4.end());       // Range constructor
    
    cout << "l4 (initializer list): ";
    for(int x : l4) cout << x << " ";
    cout << endl;
    
    // ==================== CAPACITY ====================
    printSubSection("2. Capacity Functions");
    
    list<int> lst{1, 2, 3, 4, 5};
    
    cout << "size(): " << lst.size() << endl;
    cout << "max_size(): " << lst.max_size() << endl;
    cout << "empty(): " << (lst.empty() ? "true" : "false") << endl;
    
    // ==================== ELEMENT ACCESS ====================
    printSubSection("3. Element Access");
    
    cout << "front(): " << lst.front() << endl;
    cout << "back(): " << lst.back() << endl;
    // Note: No operator[] or at() - no random access!
    
    // ==================== MODIFIERS ====================
    printSubSection("4. Modifiers");
    
    list<int> ml{1, 2, 3};
    
    // push_front and push_back
    ml.push_front(0);                         // Add to front
    ml.push_back(4);                          // Add to back
    cout << "After push_front(0), push_back(4): ";
    for(int x : ml) cout << x << " ";
    cout << endl;
    
    // emplace_front and emplace_back
    ml.emplace_front(-1);                     // Construct at front
    ml.emplace_back(5);                       // Construct at back
    cout << "After emplace_front(-1), emplace_back(5): ";
    for(int x : ml) cout << x << " ";
    cout << endl;
    
    // pop_front and pop_back
    ml.pop_front();                           // Remove first element
    ml.pop_back();                            // Remove last element
    cout << "After pop_front(), pop_back(): ";
    for(int x : ml) cout << x << " ";
    cout << endl;
    
    // insert
    auto it = ml.begin();
    advance(it, 2);                           // Move iterator to position 2
    ml.insert(it, 100);                       // Insert before iterator
    cout << "After insert(100) at pos 2: ";
    for(int x : ml) cout << x << " ";
    cout << endl;
    
    // emplace
    it = ml.begin();
    advance(it, 1);
    ml.emplace(it, 50);                       // Construct before iterator
    cout << "After emplace(50) at pos 1: ";
    for(int x : ml) cout << x << " ";
    cout << endl;
    
    // erase
    it = ml.begin();
    advance(it, 2);
    ml.erase(it);                             // Erase element at iterator
    cout << "After erase at pos 2: ";
    for(int x : ml) cout << x << " ";
    cout << endl;
    
    // clear
    list<int> toClear{1, 2, 3};
    toClear.clear();
    cout << "After clear(), size: " << toClear.size() << endl;
    
    // swap
    list<int> sl1{1, 2, 3};
    list<int> sl2{10, 20};
    sl1.swap(sl2);
    cout << "After swap, sl1: ";
    for(int x : sl1) cout << x << " ";
    cout << endl;
    
    // resize
    list<int> rl{1, 2, 3};
    rl.resize(5, 0);                          // Resize to 5, fill with 0
    cout << "After resize(5, 0): ";
    for(int x : rl) cout << x << " ";
    cout << endl;
    
    // assign
    list<int> al;
    al.assign(4, 100);
    cout << "After assign(4, 100): ";
    for(int x : al) cout << x << " ";
    cout << endl;
    
    // ==================== LIST-SPECIFIC OPERATIONS ====================
    printSubSection("5. List-Specific Operations");
    
    // splice - transfer elements from another list
    list<int> src{100, 200, 300};
    list<int> dest{1, 2, 3};
    auto pos = dest.begin();
    advance(pos, 1);
    dest.splice(pos, src);                    // Move all elements from src
    cout << "After splice(src) at pos 1: ";
    for(int x : dest) cout << x << " ";
    cout << " (src size: " << src.size() << ")" << endl;
    
    // remove - remove all elements with specific value
    list<int> rl2{1, 2, 1, 3, 1, 4, 1};
    rl2.remove(1);                            // Remove all 1s
    cout << "After remove(1): ";
    for(int x : rl2) cout << x << " ";
    cout << endl;
    
    // remove_if - remove elements matching condition
    list<int> rl3{1, 2, 3, 4, 5, 6, 7, 8};
    rl3.remove_if([](int x) { return x % 2 == 0; });  // Remove even numbers
    cout << "After remove_if(even): ";
    for(int x : rl3) cout << x << " ";
    cout << endl;
    
    // unique - remove consecutive duplicates
    list<int> ul{1, 1, 2, 2, 2, 3, 3, 4};
    ul.unique();
    cout << "After unique(): ";
    for(int x : ul) cout << x << " ";
    cout << endl;
    
    // sort
    list<int> sortl{5, 2, 8, 1, 9, 3};
    sortl.sort();                             // Ascending order
    cout << "After sort(): ";
    for(int x : sortl) cout << x << " ";
    cout << endl;
    
    sortl.sort(greater<int>());               // Descending order
    cout << "After sort(descending): ";
    for(int x : sortl) cout << x << " ";
    cout << endl;
    
    // reverse
    list<int> revl{1, 2, 3, 4, 5};
    revl.reverse();
    cout << "After reverse(): ";
    for(int x : revl) cout << x << " ";
    cout << endl;
    
    // merge - merge two sorted lists
    list<int> m1{1, 3, 5, 7};
    list<int> m2{2, 4, 6, 8};
    m1.merge(m2);                             // m2 becomes empty
    cout << "After merge (m1): ";
    for(int x : m1) cout << x << " ";
    cout << " (m2 size: " << m2.size() << ")" << endl;
}

/*
================================================================================
                            3. SET
================================================================================
    - Ordered unique elements
    - Implemented as Red-Black Tree
    - Insert/Delete/Search: O(log n)
    - Elements are sorted automatically
    - Header: <set>
================================================================================
*/
void setDemo() {
    printSection("SET - Ordered Unique Elements");
    
    // ==================== CONSTRUCTORS ====================
    printSubSection("1. Constructors");
    
    set<int> s1;                              // Empty set
    set<int> s2{5, 2, 8, 1, 9, 3, 5};         // Initializer list (duplicates removed)
    set<int> s3(s2);                          // Copy constructor
    set<int> s4(s2.begin(), s2.end());        // Range constructor
    set<int, greater<int>> s5{1, 2, 3, 4, 5}; // Custom comparator (descending)
    
    cout << "s2 (from {5,2,8,1,9,3,5}): ";
    for(int x : s2) cout << x << " ";
    cout << endl;
    
    cout << "s5 (descending order): ";
    for(int x : s5) cout << x << " ";
    cout << endl;
    
    // ==================== CAPACITY ====================
    printSubSection("2. Capacity Functions");
    
    set<int> st{1, 2, 3, 4, 5};
    
    cout << "size(): " << st.size() << endl;
    cout << "max_size(): " << st.max_size() << endl;
    cout << "empty(): " << (st.empty() ? "true" : "false") << endl;
    
    // ==================== MODIFIERS ====================
    printSubSection("3. Modifiers");
    
    set<int> ms;
    
    // insert
    auto result = ms.insert(5);               // Returns pair<iterator, bool>
    cout << "insert(5): " << (result.second ? "success" : "failed") << endl;
    
    result = ms.insert(5);                    // Duplicate - fails
    cout << "insert(5) again: " << (result.second ? "success" : "failed") << endl;
    
    ms.insert({3, 1, 4, 1, 5, 9});            // Insert multiple (duplicates ignored)
    cout << "After insert({3,1,4,1,5,9}): ";
    for(int x : ms) cout << x << " ";
    cout << endl;
    
    // emplace
    auto emp_result = ms.emplace(2);          // Construct in-place
    cout << "emplace(2): " << (emp_result.second ? "success" : "failed") << endl;
    cout << "After emplace: ";
    for(int x : ms) cout << x << " ";
    cout << endl;
    
    // emplace_hint
    ms.emplace_hint(ms.begin(), 0);           // Hint for position
    cout << "After emplace_hint(0): ";
    for(int x : ms) cout << x << " ";
    cout << endl;
    
    // erase
    ms.erase(5);                              // Erase by value
    cout << "After erase(5): ";
    for(int x : ms) cout << x << " ";
    cout << endl;
    
    ms.erase(ms.begin());                     // Erase by iterator
    cout << "After erase(begin): ";
    for(int x : ms) cout << x << " ";
    cout << endl;
    
    // clear
    set<int> toClear{1, 2, 3};
    toClear.clear();
    cout << "After clear(), size: " << toClear.size() << endl;
    
    // swap
    set<int> ss1{1, 2, 3};
    set<int> ss2{10, 20, 30};
    ss1.swap(ss2);
    cout << "After swap, ss1: ";
    for(int x : ss1) cout << x << " ";
    cout << endl;
    
    // ==================== LOOKUP OPERATIONS ====================
    printSubSection("4. Lookup Operations");
    
    set<int> ls{1, 3, 5, 7, 9, 11, 13, 15};
    
    // find
    auto it = ls.find(7);
    if(it != ls.end()) {
        cout << "find(7): found " << *it << endl;
    }
    
    it = ls.find(6);
    cout << "find(6): " << (it != ls.end() ? "found" : "not found") << endl;
    
    // count
    cout << "count(7): " << ls.count(7) << endl;
    cout << "count(6): " << ls.count(6) << endl;
    
    // contains (C++20)
    // cout << "contains(7): " << (ls.contains(7) ? "true" : "false") << endl;
    // cout << "contains(6): " << (ls.contains(6) ? "true" : "false") << endl;
    
    // lower_bound - first element >= value
    it = ls.lower_bound(6);
    cout << "lower_bound(6): " << *it << endl;  // 7
    
    // upper_bound - first element > value
    it = ls.upper_bound(7);
    cout << "upper_bound(7): " << *it << endl;  // 9
    
    // equal_range - returns pair of iterators
    auto range = ls.equal_range(7);
    cout << "equal_range(7): [" << *range.first << ", " << *range.second << ")" << endl;
    
    // ==================== MULTISET ====================
    printSubSection("5. Multiset (allows duplicates)");
    
    multiset<int> mset{5, 2, 8, 2, 5, 1, 5};
    cout << "Multiset {5,2,8,2,5,1,5}: ";
    for(int x : mset) cout << x << " ";
    cout << endl;
    
    cout << "count(5): " << mset.count(5) << endl;
    
    // erase all occurrences of a value
    mset.erase(5);
    cout << "After erase(5): ";
    for(int x : mset) cout << x << " ";
    cout << endl;
}

/*
================================================================================
                            4. MAP
================================================================================
    - Key-value pairs
    - Ordered by key
    - Unique keys
    - Implemented as Red-Black Tree
    - Insert/Delete/Search: O(log n)
    - Header: <map>
================================================================================
*/
void mapDemo() {
    printSection("MAP - Ordered Key-Value Pairs");
    
    // ==================== CONSTRUCTORS ====================
    printSubSection("1. Constructors");
    
    map<int, string> m1;                      // Empty map
    map<int, string> m2{{1, "one"}, {2, "two"}, {3, "three"}};  // Initializer list
    map<int, string> m3(m2);                  // Copy constructor
    map<int, string> m4(m2.begin(), m2.end()); // Range constructor
    map<int, string, greater<int>> m5{{1, "a"}, {2, "b"}, {3, "c"}}; // Custom comparator
    
    cout << "m2: ";
    for(auto& [k, v] : m2) cout << "{" << k << ":" << v << "} ";
    cout << endl;
    
    cout << "m5 (descending keys): ";
    for(auto& [k, v] : m5) cout << "{" << k << ":" << v << "} ";
    cout << endl;
    
    // ==================== CAPACITY ====================
    printSubSection("2. Capacity Functions");
    
    cout << "size(): " << m2.size() << endl;
    cout << "max_size(): " << m2.max_size() << endl;
    cout << "empty(): " << (m2.empty() ? "true" : "false") << endl;
    
    // ==================== ELEMENT ACCESS ====================
    printSubSection("3. Element Access");
    
    map<int, string> am{{1, "one"}, {2, "two"}, {3, "three"}};
    
    cout << "am[1]: " << am[1] << endl;       // Access, creates if not exists
    cout << "am.at(2): " << am.at(2) << endl; // Access with bounds checking
    
    am[4] = "four";                           // Insert using []
    cout << "After am[4] = 'four': ";
    for(auto& [k, v] : am) cout << "{" << k << ":" << v << "} ";
    cout << endl;
    
    am[1] = "ONE";                            // Modify existing
    cout << "After am[1] = 'ONE': ";
    for(auto& [k, v] : am) cout << "{" << k << ":" << v << "} ";
    cout << endl;
    
    // ==================== MODIFIERS ====================
    printSubSection("4. Modifiers");
    
    map<int, string> mm;
    
    // insert
    mm.insert({1, "one"});                    // Insert pair
    mm.insert(make_pair(2, "two"));           // Using make_pair
    mm.insert(pair<int, string>(3, "three")); // Explicit pair
    
    auto result = mm.insert({3, "THREE"});    // Fails - key exists
    cout << "insert({3,'THREE'}): " << (result.second ? "success" : "failed") << endl;
    
    cout << "After inserts: ";
    for(auto& [k, v] : mm) cout << "{" << k << ":" << v << "} ";
    cout << endl;
    
    // insert_or_assign (C++17)
    mm.insert_or_assign(3, "THREE");          // Updates if exists
    cout << "After insert_or_assign(3, 'THREE'): ";
    for(auto& [k, v] : mm) cout << "{" << k << ":" << v << "} ";
    cout << endl;
    
    // emplace
    mm.emplace(4, "four");                    // Construct in-place
    cout << "After emplace(4, 'four'): ";
    for(auto& [k, v] : mm) cout << "{" << k << ":" << v << "} ";
    cout << endl;
    
    // try_emplace (C++17) - doesn't modify if key exists
    mm.try_emplace(4, "FOUR");                // Fails - key exists
    mm.try_emplace(5, "five");                // Success
    cout << "After try_emplace: ";
    for(auto& [k, v] : mm) cout << "{" << k << ":" << v << "} ";
    cout << endl;
    
    // erase
    mm.erase(2);                              // Erase by key
    cout << "After erase(2): ";
    for(auto& [k, v] : mm) cout << "{" << k << ":" << v << "} ";
    cout << endl;
    
    mm.erase(mm.begin());                     // Erase by iterator
    cout << "After erase(begin): ";
    for(auto& [k, v] : mm) cout << "{" << k << ":" << v << "} ";
    cout << endl;
    
    // clear and swap
    map<int, string> mc{{1, "a"}, {2, "b"}};
    mc.clear();
    cout << "After clear(), size: " << mc.size() << endl;
    
    // ==================== LOOKUP OPERATIONS ====================
    printSubSection("5. Lookup Operations");
    
    map<int, string> lm{{1, "one"}, {3, "three"}, {5, "five"}, {7, "seven"}};
    
    // find
    auto it = lm.find(3);
    if(it != lm.end()) {
        cout << "find(3): {" << it->first << ":" << it->second << "}" << endl;
    }
    
    // count
    cout << "count(3): " << lm.count(3) << endl;
    cout << "count(4): " << lm.count(4) << endl;
    
    // contains (C++20)
    //cout << "contains(3): " << (lm.contains(3) ? "true" : "false") << endl;
    
    // lower_bound
    it = lm.lower_bound(4);                   // First key >= 4
    cout << "lower_bound(4): {" << it->first << ":" << it->second << "}" << endl;
    
    // upper_bound
    it = lm.upper_bound(3);                   // First key > 3
    cout << "upper_bound(3): {" << it->first << ":" << it->second << "}" << endl;
    
    // equal_range
    auto range = lm.equal_range(3);
    cout << "equal_range(3): exists=" << (range.first != range.second) << endl;
    
    // ==================== MULTIMAP ====================
    printSubSection("6. Multimap (allows duplicate keys)");
    
    multimap<int, string> mmap;
    mmap.insert({1, "one"});
    mmap.insert({1, "uno"});
    mmap.insert({1, "ein"});
    mmap.insert({2, "two"});
    
    cout << "Multimap with duplicate keys: ";
    for(auto& [k, v] : mmap) cout << "{" << k << ":" << v << "} ";
    cout << endl;
    
    cout << "count(1): " << mmap.count(1) << endl;
    
    // Get all values for a key
    auto [begin, end] = mmap.equal_range(1);
    cout << "All values for key 1: ";
    for(auto it = begin; it != end; ++it) {
        cout << it->second << " ";
    }
    cout << endl;
}

/*
================================================================================
                        5. UNORDERED_SET
================================================================================
    - Hash table implementation
    - Unique elements
    - No ordering
    - Average O(1) for insert/delete/search
    - Worst case O(n)
    - Header: <unordered_set>
================================================================================
*/
void unorderedSetDemo() {
    printSection("UNORDERED_SET - Hash-based Unique Elements");
    
    // ==================== CONSTRUCTORS ====================
    printSubSection("1. Constructors");
    
    unordered_set<int> us1;                   // Empty
    unordered_set<int> us2{5, 2, 8, 1, 9, 3}; // Initializer list
    unordered_set<int> us3(us2);              // Copy
    unordered_set<int> us4(10);               // Bucket count hint
    unordered_set<int> us5(us2.begin(), us2.end()); // Range
    
    cout << "us2 (order may vary): ";
    for(int x : us2) cout << x << " ";
    cout << endl;
    
    // ==================== CAPACITY ====================
    printSubSection("2. Capacity Functions");
    
    cout << "size(): " << us2.size() << endl;
    cout << "max_size(): " << us2.max_size() << endl;
    cout << "empty(): " << (us2.empty() ? "true" : "false") << endl;
    
    // ==================== HASH POLICY ====================
    printSubSection("3. Hash Policy (Bucket Interface)");
    
    unordered_set<int> hp{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    cout << "bucket_count(): " << hp.bucket_count() << endl;
    cout << "max_bucket_count(): " << hp.max_bucket_count() << endl;
    cout << "load_factor(): " << hp.load_factor() << endl;
    cout << "max_load_factor(): " << hp.max_load_factor() << endl;
    
    // bucket() - which bucket an element is in
    cout << "bucket(5): " << hp.bucket(5) << endl;
    
    // bucket_size() - number of elements in a bucket
    size_t b = hp.bucket(5);
    cout << "bucket_size(" << b << "): " << hp.bucket_size(b) << endl;
    
    // rehash - set minimum number of buckets
    hp.rehash(50);
    cout << "After rehash(50), bucket_count(): " << hp.bucket_count() << endl;
    
    // reserve - reserve space for n elements
    hp.reserve(100);
    cout << "After reserve(100), bucket_count(): " << hp.bucket_count() << endl;
    
    // ==================== MODIFIERS ====================
    printSubSection("4. Modifiers");
    
    unordered_set<int> ms;
    
    // insert
    auto result = ms.insert(5);
    cout << "insert(5): " << (result.second ? "success" : "failed") << endl;
    
    result = ms.insert(5);
    cout << "insert(5) again: " << (result.second ? "success" : "failed") << endl;
    
    ms.insert({3, 1, 4, 1, 5, 9, 2, 6});
    cout << "After insert multiple: ";
    for(int x : ms) cout << x << " ";
    cout << endl;
    
    // emplace
    ms.emplace(7);
    cout << "After emplace(7): ";
    for(int x : ms) cout << x << " ";
    cout << endl;
    
    // erase
    ms.erase(5);
    cout << "After erase(5): ";
    for(int x : ms) cout << x << " ";
    cout << endl;
    
    // clear and swap same as set
    
    // ==================== LOOKUP ====================
    printSubSection("5. Lookup Operations");
    
    unordered_set<int> ls{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    // find
    auto it = ls.find(5);
    cout << "find(5): " << (it != ls.end() ? "found" : "not found") << endl;
    
    // count
    cout << "count(5): " << ls.count(5) << endl;
    cout << "count(100): " << ls.count(100) << endl;
    
    // contains (C++20)
    //cout << "contains(5): " << (ls.contains(5) ? "true" : "false") << endl;
    
    // equal_range
    auto range = ls.equal_range(5);
    cout << "equal_range(5): " << (range.first != range.second ? "found" : "not found") << endl;
    
    // ==================== UNORDERED_MULTISET ====================
    printSubSection("6. Unordered_multiset (allows duplicates)");
    
    unordered_multiset<int> ums{5, 2, 5, 1, 5, 3, 2};
    cout << "Unordered_multiset {5,2,5,1,5,3,2}: ";
    for(int x : ums) cout << x << " ";
    cout << endl;
    cout << "count(5): " << ums.count(5) << endl;
}

/*
================================================================================
                        6. UNORDERED_MAP
================================================================================
    - Hash table implementation
    - Key-value pairs
    - Unique keys
    - No ordering
    - Average O(1) for insert/delete/search
    - Header: <unordered_map>
================================================================================
*/
void unorderedMapDemo() {
    printSection("UNORDERED_MAP - Hash-based Key-Value Pairs");
    
    // ==================== CONSTRUCTORS ====================
    printSubSection("1. Constructors");
    
    unordered_map<int, string> um1;           // Empty
    unordered_map<int, string> um2{{1, "one"}, {2, "two"}, {3, "three"}};
    unordered_map<int, string> um3(um2);      // Copy
    unordered_map<int, string> um4(10);       // Bucket count hint
    
    cout << "um2 (order may vary): ";
    for(auto& [k, v] : um2) cout << "{" << k << ":" << v << "} ";
    cout << endl;
    
    // ==================== CAPACITY ====================
    printSubSection("2. Capacity Functions");
    
    cout << "size(): " << um2.size() << endl;
    cout << "max_size(): " << um2.max_size() << endl;
    cout << "empty(): " << (um2.empty() ? "true" : "false") << endl;
    
    // ==================== HASH POLICY ====================
    printSubSection("3. Hash Policy");
    
    cout << "bucket_count(): " << um2.bucket_count() << endl;
    cout << "load_factor(): " << um2.load_factor() << endl;
    cout << "max_load_factor(): " << um2.max_load_factor() << endl;
    
    um2.rehash(50);
    cout << "After rehash(50), bucket_count(): " << um2.bucket_count() << endl;
    
    um2.reserve(100);
    cout << "After reserve(100), bucket_count(): " << um2.bucket_count() << endl;
    
    // ==================== ELEMENT ACCESS ====================
    printSubSection("4. Element Access");
    
    unordered_map<int, string> am{{1, "one"}, {2, "two"}, {3, "three"}};
    
    cout << "am[1]: " << am[1] << endl;
    cout << "am.at(2): " << am.at(2) << endl;
    
    am[4] = "four";                           // Insert
    am[1] = "ONE";                            // Modify
    cout << "After modifications: ";
    for(auto& [k, v] : am) cout << "{" << k << ":" << v << "} ";
    cout << endl;
    
    // ==================== MODIFIERS ====================
    printSubSection("5. Modifiers");
    
    unordered_map<int, string> mm;
    
    // insert
    mm.insert({1, "one"});
    mm.insert(make_pair(2, "two"));
    cout << "After inserts: ";
    for(auto& [k, v] : mm) cout << "{" << k << ":" << v << "} ";
    cout << endl;
    
    // insert_or_assign (C++17)
    mm.insert_or_assign(2, "TWO");
    cout << "After insert_or_assign(2, 'TWO'): ";
    for(auto& [k, v] : mm) cout << "{" << k << ":" << v << "} ";
    cout << endl;
    
    // emplace
    mm.emplace(3, "three");
    cout << "After emplace(3, 'three'): ";
    for(auto& [k, v] : mm) cout << "{" << k << ":" << v << "} ";
    cout << endl;
    
    // try_emplace (C++17)
    mm.try_emplace(3, "THREE");               // Fails - exists
    mm.try_emplace(4, "four");                // Success
    cout << "After try_emplace: ";
    for(auto& [k, v] : mm) cout << "{" << k << ":" << v << "} ";
    cout << endl;
    
    // erase
    mm.erase(1);
    cout << "After erase(1): ";
    for(auto& [k, v] : mm) cout << "{" << k << ":" << v << "} ";
    cout << endl;
    
    // ==================== LOOKUP ====================
    printSubSection("6. Lookup Operations");
    
    unordered_map<int, string> lm{{1, "one"}, {2, "two"}, {3, "three"}};
    
    // find
    auto it = lm.find(2);
    if(it != lm.end()) {
        cout << "find(2): {" << it->first << ":" << it->second << "}" << endl;
    }
    
    // count
    cout << "count(2): " << lm.count(2) << endl;
    cout << "count(100): " << lm.count(100) << endl;
    
    // contains (C++20)
    //cout << "contains(2): " << (lm.contains(2) ? "true" : "false") << endl;
    
    // equal_range
    auto range = lm.equal_range(2);
    if(range.first != range.second) {
        cout << "equal_range(2): {" << range.first->first << ":" << range.first->second << "}" << endl;
    }
    
    // ==================== UNORDERED_MULTIMAP ====================
    printSubSection("7. Unordered_multimap (allows duplicate keys)");
    
    unordered_multimap<int, string> umm;
    umm.insert({1, "one"});
    umm.insert({1, "uno"});
    umm.insert({1, "ein"});
    umm.insert({2, "two"});
    
    cout << "Unordered_multimap with duplicate keys: ";
    for(auto& [k, v] : umm) cout << "{" << k << ":" << v << "} ";
    cout << endl;
    cout << "count(1): " << umm.count(1) << endl;
}

/*
================================================================================
                            7. QUEUE
================================================================================
    - FIFO (First In First Out)
    - Container adapter (uses deque by default)
    - Insert at back, remove from front
    - No iteration
    - Header: <queue>
================================================================================
*/
void queueDemo() {
    printSection("QUEUE - FIFO Container Adapter");
    
    // ==================== CONSTRUCTORS ====================
    printSubSection("1. Constructors");
    
    queue<int> q1;                            // Empty queue
    deque<int> d{1, 2, 3, 4, 5};
    queue<int> q2(d);                         // From deque
    queue<int> q3(q2);                        // Copy constructor
    
    // ==================== ALL QUEUE OPERATIONS ====================
    printSubSection("2. Queue Operations");
    
    queue<int> q;
    
    // push - add to back
    q.push(10);
    q.push(20);
    q.push(30);
    cout << "After push(10), push(20), push(30)" << endl;
    
    // emplace - construct at back
    q.emplace(40);
    cout << "After emplace(40)" << endl;
    
    // front - access first element
    cout << "front(): " << q.front() << endl;
    
    // back - access last element
    cout << "back(): " << q.back() << endl;
    
    // size
    cout << "size(): " << q.size() << endl;
    
    // empty
    cout << "empty(): " << (q.empty() ? "true" : "false") << endl;
    
    // pop - remove from front
    cout << "Popping all elements: ";
    while(!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
    
    // swap
    queue<int> qa, qb;
    qa.push(1); qa.push(2);
    qb.push(10); qb.push(20); qb.push(30);
    qa.swap(qb);
    cout << "After swap - qa size: " << qa.size() << ", qb size: " << qb.size() << endl;
    
    // ==================== PRIORITY QUEUE ====================
    printSubSection("3. Priority Queue (Heap-based)");
    
    // Default: max-heap (largest element first)
    priority_queue<int> pq;
    pq.push(30);
    pq.push(10);
    pq.push(50);
    pq.push(20);
    pq.push(40);
    
    cout << "Priority Queue (max-heap) popping: ";
    while(!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;
    
    // Min-heap
    priority_queue<int, vector<int>, greater<int>> minPQ;
    minPQ.push(30);
    minPQ.push(10);
    minPQ.push(50);
    minPQ.push(20);
    minPQ.push(40);
    
    cout << "Priority Queue (min-heap) popping: ";
    while(!minPQ.empty()) {
        cout << minPQ.top() << " ";
        minPQ.pop();
    }
    cout << endl;
    
    // Custom comparator with pairs
    auto cmp = [](pair<int,string>& a, pair<int,string>& b) {
        return a.first > b.first;  // Min by first element
    };
    priority_queue<pair<int,string>, vector<pair<int,string>>, decltype(cmp)> customPQ(cmp);
    
    customPQ.push({3, "three"});
    customPQ.push({1, "one"});
    customPQ.push({2, "two"});
    
    cout << "Custom Priority Queue (min by first): ";
    while(!customPQ.empty()) {
        auto [num, str] = customPQ.top();
        cout << "{" << num << ":" << str << "} ";
        customPQ.pop();
    }
    cout << endl;
    
    // Priority Queue functions summary
    printSubSection("4. Priority Queue Functions");
    priority_queue<int> pqf;
    pqf.push(5);
    pqf.push(3);
    pqf.push(7);
    
    cout << "top(): " << pqf.top() << endl;           // Access top (doesn't remove)
    cout << "size(): " << pqf.size() << endl;
    cout << "empty(): " << (pqf.empty() ? "true" : "false") << endl;
    
    pqf.pop();                                        // Remove top
    cout << "After pop(), top(): " << pqf.top() << endl;
    
    pqf.emplace(10);                                  // Construct in place
    cout << "After emplace(10), top(): " << pqf.top() << endl;
}

/*
================================================================================
                            8. STACK
================================================================================
    - LIFO (Last In First Out)
    - Container adapter (uses deque by default)
    - Insert and remove from top only
    - No iteration
    - Header: <stack>
================================================================================
*/
void stackDemo() {
    printSection("STACK - LIFO Container Adapter");
    
    // ==================== CONSTRUCTORS ====================
    printSubSection("1. Constructors");
    
    stack<int> s1;                            // Empty stack
    deque<int> d{1, 2, 3, 4, 5};
    stack<int> s2(d);                         // From deque (5 is on top)
    stack<int> s3(s2);                        // Copy constructor
    
    // Using different underlying container
    stack<int, vector<int>> sv;               // Stack using vector
    stack<int, list<int>> sl;                 // Stack using list
    
    // ==================== ALL STACK OPERATIONS ====================
    printSubSection("2. Stack Operations");
    
    stack<int> s;
    
    // push - add to top
    s.push(10);
    s.push(20);
    s.push(30);
    cout << "After push(10), push(20), push(30)" << endl;
    
    // emplace - construct at top
    s.emplace(40);
    cout << "After emplace(40)" << endl;
    
    // top - access top element
    cout << "top(): " << s.top() << endl;
    
    // size
    cout << "size(): " << s.size() << endl;
    
    // empty
    cout << "empty(): " << (s.empty() ? "true" : "false") << endl;
    
    // pop - remove from top
    cout << "Popping all elements: ";
    while(!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
    
    // swap
    stack<int> sa, sb;
    sa.push(1); sa.push(2);
    sb.push(10); sb.push(20); sb.push(30);
    sa.swap(sb);
    cout << "After swap - sa size: " << sa.size() << ", sb size: " << sb.size() << endl;
    
    // ==================== PRACTICAL EXAMPLES ====================
    printSubSection("3. Practical Examples");
    
    // Example 1: Reverse a string
    string str = "Hello";
    stack<char> charStack;
    for(char c : str) {
        charStack.push(c);
    }
    
    string reversed;
    while(!charStack.empty()) {
        reversed += charStack.top();
        charStack.pop();
    }
    cout << "Original: " << str << ", Reversed: " << reversed << endl;
    
    // Example 2: Check balanced parentheses
    auto isBalanced = [](const string& expr) -> bool {
        stack<char> st;
        for(char c : expr) {
            if(c == '(' || c == '[' || c == '{') {
                st.push(c);
            } else if(c == ')' || c == ']' || c == '}') {
                if(st.empty()) return false;
                char top = st.top();
                if((c == ')' && top != '(') ||
                   (c == ']' && top != '[') ||
                   (c == '}' && top != '{')) {
                    return false;
                }
                st.pop();
            }
        }
        return st.empty();
    };
    
    cout << "Is '([{}])' balanced? " << (isBalanced("([{}])") ? "Yes" : "No") << endl;
    cout << "Is '([{]})' balanced? " << (isBalanced("([{]})") ? "Yes" : "No") << endl;
}

/*
================================================================================
                        COMPARISON TABLE
================================================================================
Container        | Ordered | Unique | Access    | Insert/Del | Search
-----------------|---------|--------|-----------|------------|--------
vector           | No*     | No     | O(1)      | O(n)/O(1)  | O(n)
list             | No*     | No     | O(n)      | O(1)       | O(n)
set              | Yes     | Yes    | O(log n)  | O(log n)   | O(log n)
multiset         | Yes     | No     | O(log n)  | O(log n)   | O(log n)
map              | Yes     | Yes    | O(log n)  | O(log n)   | O(log n)
multimap         | Yes     | No     | O(log n)  | O(log n)   | O(log n)
unordered_set    | No      | Yes    | O(1) avg  | O(1) avg   | O(1) avg
unordered_map    | No      | Yes    | O(1) avg  | O(1) avg   | O(1) avg
queue            | FIFO    | No     | front/back| O(1)       | N/A
priority_queue   | Heap    | No     | top O(1)  | O(log n)   | N/A
stack            | LIFO    | No     | top O(1)  | O(1)       | N/A

* Maintains insertion order
================================================================================
*/

int main() {
    cout << "\n";
    cout << "╔══════════════════════════════════════════════════════════════════════════════╗\n";
    cout << "║              COMPREHENSIVE C++ STL GUIDE - ALL FUNCTIONS DEMO                ║\n";
    cout << "╚══════════════════════════════════════════════════════════════════════════════╝\n";
    
    vectorDemo();
    listDemo();
    setDemo();
    mapDemo();
    unorderedSetDemo();
    unorderedMapDemo();
    queueDemo();
    stackDemo();
    
    cout << "\n";
    cout << "================================================================================\n";
    cout << "                           END OF STL GUIDE\n";
    cout << "================================================================================\n";
    
    return 0;
}
