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
    Vector(int size, int capacity, int value); // default size, default capcity and filled values if size is non-zero.
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
    // sort
    void bubble_sort();
    void insertion_sort();
    
    // statistical info
    Rank max() const;
    Rank min() const;

    // operator
    T& operator[](Rank r);
    Vector<T> operator+(Vector<T> const& A);
    Vector<T>& operator+=(Vector<T> const& A);
    bool      operator==(Vector<T> const& A);
    bool      operator!=(Vector<T> const& A);
    Vector<T>& operator=(Vector<T> const& A);
};

// ****************** CONSTRUCTOR ************************************

template<class T>
void
Vector<T>::copyfrom(Vector<T> const& A, Rank begin, Rank end){
    _elem = new T[_capacity = max(2*(end - begin),DEFAULT_CAPACITY)];
    for(int i = 0, Rank tmp = begin; i < end - begin;) _elem[i++] = A[tmp++];
    _size = end - begin; // update
}

// constructor default
template<class T>
Vector<T>::Vector(int size = 0, int capacity = DEFAULT_CAPACITY, int value = 0){
    _elem = new T[capacity];
    for(int i = 0; i < size; _elem[i++] = value);
    //update
    _size = size;
    _capacity = capacity;
}

// constructor copy
template<class T>
Vector<T>::Vector(Vector<T> const& A, Rank begin, Rank end){
    copyfrom(A, begin, end);
}

// constructor copy
template<class T>
Vector<T>::Vector(Vector<T> const& A){
    copyfrom(A, 0, A.size());
}

//*********************END OF CONSTRUCTOR********************************

// deconstructor
template<class T>
Vector<T>::~Vector(){delete []_elem;}

// search
template<class T>
T&
Vector<T>::get(Rank r) const{return _elem[r];}

template<class T>
Rank
Vector<T>::find(T const& e) const{
    for(int i = size() - 1; i >= 0; i--)
        if(_elem[i] == e) return i;
    return -1;
}

// expand
template<class T>
void
expand(){
    while (/* condition */)
    {
        /* code */
    }
    (_size >= _capacity) 
}