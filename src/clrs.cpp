#include "clrs.hpp"
#include <assert.h>
#include <limits>

Status Insertion_Sort_Nondec(vector<int> &vi)
{
    /* 空数组 */
    if (!vi.size())
        return Status::ARRAY_IS_EMPTY;

    int i, j, key;
    for(i = 1; i < vi.size(); i++) {
        key = vi[i];
        // 将 A[i] 插入已经排序好的序列
        j = i - 1;
        // 从后往前移动
        while (j >= 0 && vi[j] > key) {
            vi[j+1] = vi[j];
            --j;
        }
        vi[j+1] = key;
    }

    return Status::OK;
}

/*
 *
 * exercise 2.1-2  非升序排序
 *
 */
Status Insertion_Sort_Nonasc(vector<int> &vi)
{
    /* 空数组 */
    if (!vi.size())
        return Status::ARRAY_IS_EMPTY;

    int i, j, key;
    for(i = 1; i < vi.size(); i++) {
        key = vi[i];
        // 将 A[i] 插入已经排序好的序列
        j = i - 1;
        // 从后往前移动
        while (j >= 0 && vi[j] < key) {
            vi[j+1] = vi[j];
            --j;
        }
        vi[j+1] = key;
    }

    return Status::OK;
}



/*
 *
 * exercise 2.1-3 查找问题
 *
 */
Status Find_value(vector<int> &vi, int n, int &index) {
    if (!vi.size())
        return Status::ARRAY_IS_EMPTY;
    
    for (int i=0; i < vi.size(); ++i) {
        if (vi[i] == n) {
            index = i;
            return Status::OK;
        }
    }
    return Status::VAL_NOT_FOUND;
}
ostream& operator<<(ostream &os, vector<int> &v)
{
    os << "vector<int> : [ ";
    for (auto i : v) {
        os << i << " ";
    }
    os << "]";

    return os;
}


/*
 *
 * exercise 2.1-4  两个数的二进制相加
 *
 */
vector<int> Bin_Addition(vector<int> &v1, vector<int> &v2)
{
    assert(v1.size() == v2.size());
    int carry = 0; // 进位标志
    vector<int> ret;
    int tmp;
    for (int i = v1.size() - 1; i >= 0; --i) {
        tmp = v1[i] + v2[i] + carry;
        if (tmp >= 2)
            carry = 1;
        else
            carry = 0;
        
        ret.push_back(tmp % 2);
    }
    ret.push_back(carry);


    vector<int> v3;
    for (int i=ret.size()-1; i >= 0 ; --i)
    {
        v3.push_back(ret[i]);
    }

    return v3;
}

/*
 *
 * 练习 2.2-2  选择排序
 *
 */
template <typename T>
void swap(T &a, T &b)
{
    T c = a;
    a = b;
    b = c;
}

Status Select_Sort_Nondec(vector<int> &vi)
{
    if (!vi.size())
        return Status::ARRAY_IS_EMPTY;
    
    int tmpMin;
    for (int i = 0; i < vi.size() - 1; ++i) {
        tmpMin = i;
        for (int j = i; j < vi.size(); ++j) {
            if (vi[tmpMin] > vi[j])
                tmpMin = j;
            else
                continue;
        }
        if (tmpMin != i)
            swap<int>(vi[tmpMin], vi[i]);
        else
            continue;
    }
    return Status::OK;
}


/*
 *
 * 归并排序
 *
 */
void Merge(vector<int> &A, int p, int q, int r)
{
    int n1 = q - p + 1; // 左子序列长度
    int n2 = r - q;     // 右子序列长度

    vector<int> L;
    vector<int> R;

    int i, j;
    for (i = 0; i < n1; ++i) 
        L.push_back(A[p + i]);
    
    for (j = 0; j < n2; ++j)
        R.push_back(A[q+j]);
    
    L.push_back(INT_MAX);
    R.push_back(INT_MAX);

    i = 0;
    j = 0;
    for (int k = p; k <= r; ++k) {
        if (L[i] <= R[j]) {
            A[k] = L[i];
            ++i;
        } else {
            A[k] = R[j];
            ++j;
        }
    }
}


Status Merge_Sort_Impl(vector<int> &A, int p, int r)
{
    int q = (p + r) / 2;
    Merge_Sort_Impl(A, p, q);
    Merge_Sort_Impl(A, q+1, r);
    Merge(A, p, q, r);

    return Status::OK;
}

Status Merge_Sort(vector<int> &A)
{
    if (!A.size())
        return Status::ARRAY_IS_EMPTY;
    Merge_Sort_Impl(A, 0, A.size()-1);
    return Status::OK;
}