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

// ****************** CONSTRUCTOR ************************************

template<class T>
void
Vector<T>::copyfrom(Vector<T> const& A, Rank begin, Rank end){
    _elem = new T[_capacity = 2*(end - begin) > DEFAULT_CAPACITY ? 2*(end - begin): DEFAULT_CAPACITY];
    Rank tmp = begin;
    for(int i = 0; i < end - begin;) _elem[i++] = A[tmp++];
    _size = end - begin; // update
}

// constructor default
template<class T>
Vector<T>::Vector(int size, int capacity, int value){
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
Vector<T>::expand(){
    if(_size < _capacity) return;
    if(_capacity < DEFAULT_CAPACITY) _capacity = DEFAULT_CAPACITY;
    T* tmp = _elem;
    _elem = new T[_capacity <<= 1];
    for(int i = 0; i < _size; i++) _elem[i] = tmp[i];
    delete []tmp;    
}

// dynamic-add
template<class T>
void
Vector<T>::insert(Rank r, T const& e){
    expand();
    for(int i = size() - 1; i >= r; i--) _elem[i+1] = _elem[i];
    _elem[r] = e;
    _size ++;
}

template<class T>
void
Vector<T>::insert(T const& e){
    insert(size(), e);
}

// remove
template<class T>
void
Vector<T>::remove(Rank r){
    for(int i = r; i < size() - 1; i++) _elem[i] = _elem[i+1];
    _size --;
}

// isempty
template<class T>
bool
Vector<T>::empty() const{return !_size;}

// max() and min()
template<class T>
Rank
Vector<T>::max() const{
    T max = _elem[size() - 1]; Rank index = size() - 1;
    for(int i = size() - 1; i >= 0; i--)
        if(max < _elem[i]){max = _elem[i]; index = i;}
    return index;
}

template<class T>
Rank
Vector<T>::min() const{
    T min = _elem[size() - 1]; Rank index = size() - 1;
    for(int i = size() - 1; i >= 0; i--)
        if(min > _elem[i]){min = _elem[i]; index = i;}
    return index;
}

template<class T>
int 
Vector<T>::size() const{
    return _size;
}

// **************************OPERATORS************************
template<class T>
T& 
Vector<T>::operator[](Rank r) const{ return get(r);}

template<class T>
Vector<T>
Vector<T>::operator+(Vector<T> const& A){
    int tmp_size = A.size() + size();
    int tmp_capacity = tmp_size << 1;
    Vector<T> vec(tmp_size, tmp_capacity);
    for(int i = 0; i < size(); vec[i++] = _elem[i]);
    for(int i = this -> size(), j = 0; i < vec.size(); i++) vec[i] = A[j++];        
    return vec;
}

template<class T>
Vector<T>& 
Vector<T>::operator+=(Vector<T> const& A){
    *this = *this + A;
    return *this;
}

template<class T>
Vector<T>&
Vector<T>::operator=(Vector<T> const& A){
    T* tmp = _elem;
    _elem = new T[_capacity = A.size() << 1];
    for(int i = 0; i < A.size(); _elem[i++] = A[i]);
    _size = A.size(); //update
    delete [] tmp;
    return *this;
}

template<class T>
bool
Vector<T>::operator==(Vector<T> const& A){
    if(size() != A.size()) return false;
    for(int i = 0; i < size(); i++){
        if(_elem[i] != A[i]) return false;
    }
    return true;
}

template<class T>
bool
Vector<T>::operator!=(Vector<T> const& A){
    return !(*this == A);
}
