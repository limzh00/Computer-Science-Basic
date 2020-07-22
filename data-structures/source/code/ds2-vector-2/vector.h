# define DEFAULT_CAPACITY 2
typedef int Rank;

template<class T>
class Vector{
private:
    T* _elem; int _size; int _capacity; // data area, size and its capacity
    // expand
    void expand(); // expand the vector to enlarge its capacity.
    void copyfrom(Vector<T> const& A, Rank begin, Rank end);
public:
    // constructors
    Vector(int size = 0, int capacity = DEFAULT_CAPACITY, int value = 0); // default size, default capcity and filled values if size is non-zero.
    Vector(Vector<T> const& A, Rank begin, Rank end); // copy a sub-vector [begin, end) from an another vector.
    Vector(Vector<T> const& A); // copy the whole vector from an another one, sharing the same elements.
    // deconstructor
    ~Vector();
    // search
    T& get(Rank r) const; // Given a rank r, return the corresponding element at such rank.
    Rank find(T const& e) const; // Given a target element e, we try to return its rank in the array.
                                // If duplicated ones exist, return the one of highest rank.
                                // If none exists, return -1.
    // dynamic-add
    void insert(Rank r, T const& e); // Given a certain rank r, insert e into index r. 
    void insert(T const& e);// If not stated, we insert after the end of the vector.
    // dynamic-remove
    void remove(Rank r);
    // check whether it is empty
    bool empty() const;
    // // sort
    // void bubble_sort();
    // void insertion_sort();
    
    // statistical info
    Rank max() const;
    Rank min() const;
    int size() const;

    // operator
    T& operator[](Rank r) const;
    Vector<T> operator+(Vector<T> const& A);
    Vector<T>& operator+=(Vector<T> const& A);
    bool      operator==(Vector<T> const& A);
    bool      operator!=(Vector<T> const& A);
    Vector<T>& operator=(Vector<T> const& A);
};