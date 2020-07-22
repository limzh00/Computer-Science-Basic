/*This is a header file containing the implementation
  of Vector for int type.*/
#define DEFAULT_CAPACITY 10 // 向量的默认大小
typedef int Rank; // Rank秩 本质上就是线性表的索引
class Vector{
protected:
    Rank _size; int _capacity; int* _elem; // 规模，容量，数据区
public:
    Vector(int capacity, int size, int value);//初始函数（构造函数）
    ~Vector();//析构函数
    Rank size() const{return _size;}
    bool empty() const{return !_size;}
    void expand();
    Rank insert(Rank r, int const& e);
    Rank insert(int const& e){return insert(_size, e);}    
    int remove(Rank r);
    int get(Rank r);
    void replace(Rank r, int const& e);
};//注意不要漏掉分号

Vector::Vector(int capacity = DEFAULT_CAPACITY, int size = 0, int value = 0){
    _capacity = capacity;
    _size = size;
    _elem = new int[_capacity];
    for(int i = 0; i < _capacity; i++) _elem[i] = value;
}

Vector::~Vector() {delete [] _elem;}

void
Vector::expand(){
    if(_size < _capacity) return;
    if(_capacity < DEFAULT_CAPACITY) _capacity = DEFAULT_CAPACITY;
    int* oldElem = _elem; _elem = new int[_capacity << 1];
    for(int i = 0; i < _size; i++) _elem[i] = oldElem[i];
    delete [] oldElem;
    _capacity = _capacity << 1;
}

Rank
Vector::insert(Rank r, int const& e){
    expand();
    for(int i = _size - 1; i >= r; i--) _elem[i+1] = _elem[i];
    _elem[r] = e; 
    _size ++;
} 

int
Vector::remove(Rank r){
    for(int i = r; i < _size - 1; i++) _elem[i] = _elem[i+1];
    _size --;
}

int
Vector::get(Rank r){return _elem[r];}

void 
Vector::replace(Rank r, int const& e){
    _elem[r] = e;
}