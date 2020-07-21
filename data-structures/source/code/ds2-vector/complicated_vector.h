/*This is a header file containing the implementation
  of Vector for int type.*/
#define DEFAULT_CAPACITY 10 // 向量的默认大小
typedef int Rank; // Rank秩 本质上就是线性表的索引
class Vector{
protected:
    Rank _size; int _capacity; int* _elem; // 规模，容量，数据区
    void copyFrom(int const* A, Rank begin, Rank end); // 复制数组区间A[begin,end)
    void shrink(); //空间过大的时候要压缩,为其他数据腾出空间
    void expand(); //空间不足的时候要对向量扩容
    bool bubble(Rank begin, Rank end); //扫描交换？
    void bubbleSort(Rank begin, Rank end); // 冒泡排序算法
    Rank max(Rank begin, Rank end); //选取指定区间的最大元素
    void selectionSort(Rank begin, Rank end); //选择排序算法
    
};//注意不要漏掉分号