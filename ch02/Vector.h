typedef int Rank;
#define DEFAULT_CAPACITY 3
#include <cstdlib>
template <typename T> class Vector {
protected:
    Rank _size; int _capacity; T* _elem;
    void copyFrom(T const* A, Rank lo, Rank hi);// const* T A?
    void expand();
    void shrink();
    bool bubble(Rank lo, Rank hi);
    void bubbleSort(Rank lo, Rank hi);
    Rank max(Rank lo, Rank hi);
    void selectionSort(Rank lo, Rank hi);
    void merge(Rank lo, Rank mi, Rank hi);
    void mergeSort(Rank lo, Rank hi);
    Rank partion(Rank lo, Rank hi);
    void quickSort(Rank lo, Rank hi);
    void heapSort(Rank lo, Rank hi);
public:
    //构造函数
    Vector(int c = DEFAULT_CAPACITY, int s = 0; T v = 0) 
    {   _elem = new T[_capacity = c];
        for(_size = 0; _size < s; _elem[_size++] = v);
    }
    Vector(T const* A, Rank n) { copyFrom(A, 0, n);}
    Vector(T const* A, Rank lo, Rank hi) {copyFrom(A, lo, hi);}
    Vector(Vector<T> const& V) {copyFrom(V._elem, 0, V._size);}//常量引用？
    Vector(Vector<T> const& V, Rank lo, Rank hi) {copyFrom(V._elem, lo, hi);}
    //析构函数
    ~Vector() {delete [] _elem;}
    //只读访问接口
    Rank size() const {return _size;}
    bool empty() const {return !_size;}
    int disordered() const;
    Rank find (T const& e) const {return find(e, 0, _size);}
    Rank find(T const& e, Rank lo, Rank hi) const;
    Rank search(T const& e, ) const {
        return (_size <= 0) ? -1 : search(e, 0, _size);
    }
    Rank search(T const& e, Rank lo, Rank hi) const;
    //可写访问接口
    T& operator[] (Rank r) const;
    Vector<T> & operator= (Vector<T> const& );
    T remove (Rank r);
    int remove(Rank lo, Rank hi);
    Rank insert(Rank r, T const& e);
    Rank insert(T const& e) {return insert(_size, e);}
    void sort(Rank lo, Rank hi);
    void sort() {sort(0, _size);}
    void unsort(Rank lo, Rank hi);
    void unsort() {unsort(0, _size);}
    int deduplicate();
    int uniquify();
    //遍历
    void traverse(void(*)(T&) );
    template <typename VST> void traverse(VST&);



};
template <typename T> void swap(T &a, T &b) {
    T temp = a;
    a = b;
    b = tmp;
}
//置乱算法
template <typename T> void permute(Vector <T> V) {
    for(int i = V._size; i > 0; i --) {
        swap(V[i-1], V[rand()%i]);
    }
}

template <typename T>void Vector<T> :: copyFrom (T const* A, Rank lo, Rank hi) {
    _elem = new T[_capacity = (hi -lo) * 2];
    _size = 0;
    while(lo < hi) {
        _elem[_size ++] = A[lo ++];
    }
}

//重载赋值运算符
template <typename T> Vector<T>& Vector<T>::operator= (Vector const & V) {
    if(_elem) delete _elem[];
    copyFrom(V._elem, 0, _size);
    return this;
}

//扩容算法的实现
template <typename T> void Vector<T>::expand() {
    if (_size < _capacity) return;
    if (_capacity < DEFAULT_CAPACITY) _capacity = DEFAULT_CAPACITY;

    T* oldElem = _elem;
    _elem = new T[_capacity <<= 1];
    for (int i = 0; i < _size; i ++) {
        _elem[i] = oldElem[i];
    }
    delete [] oldElem;
    
    
}
//向量内部功能shrink()
template <typename T> void Vector<T> :: shrink() {
    if (_capacity < DEFAULT_CAPACITY<<1) return;
    if(_capacity < _size<<2) return;
    T* oldElem = _elem;
    _elem = new T[_capacity >>= 1]
    for(int i = 0; i < _size; i ++) {
        _elem[i] = oldElem[i];
    }
    delete[] oldElem;
}

//重载向量操作符[]
template <typename T> T& Vector<T> :: operator[] (Rank r) const {
    return _elem[r];
}

//区间置乱接口unsrot
template <typename T > void Vector<T>::unsort(Rank lo, Rank hi) {
    T* V = _elem + lo;
    for(int i = hi - lo; i > 0; i --) {
        swap(V[i-1], V[rand() % i]);
    }
}

//无序向量元素查找接口find()
template <typename T> Rank Vector<T>::find(T const &e, Rank lo, Rank hi) const {
    while((lo < hi--) && (_elem[hi] != e));
    return hi;
}
//向量元素插入接口Insert()
template <typename T> Rank Vector<T>::insert(Rank r, T const &e) {
    expand();
    for(int i = _size; i > r; i --) _elem[i] =  _elem[i-1];
    _elem[r] = e; _size ++;
    return r;
}
//向量区间删除接口
template <typename T> int Vector<T> :: remove(Rank lo, Rank hi) {
    if(lo == hi) return 0;
    while(hi < _size ) _elem[lo++] = _elem[hi++];
    _size = lo;
    shrink();
    return hi-lo;
}

//向量氮元素删除接口
template <typename T> T Vector<T> :: remove(Rank r) {
    T e = elem[r];
    remove(r, r+1);
    return e;
}
//无序向量清楚重复元素接口 deduplicate()
template <typename T> int Vector<T> :: deduplicate() {
    int oldSize = _size;
    Rank i = 1;
    while(i < _size)
        (find(0, i, _elem[i])) < 0 ? i ++ : remove(i);
    return oldSize = _size;
}
//遍历接口

template <typename T> void  Vector<T> :: traverse(void(* visit) (T&)) {
    for(int i = 0; i < _size; i ++) visit(_elem[i]);
}

template <typename T> template <typename VST>
void Vector<T> :: traverse(VST &visit) {
    for (int i = 0; i < _size; i ++) visit(_elem[i]);
}
