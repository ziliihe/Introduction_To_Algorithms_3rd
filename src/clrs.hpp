#ifndef CLRS_HPP_
#define CLRS_HPP_

#include <vector>
#include <iostream>
enum class Status {
    OK,
    ARRAY_IS_EMPTY,
    VAL_NOT_FOUND
};

using std::vector;
using std::ostream;
using std::endl;
using std::cout;

/*
 *
 * cout 直接输出数组
 *
 */
ostream& operator<<(ostream &os, vector<int> &v);



/*
 *
 * 插入排序： 少量元素的排序，是一个有效的算法
 *
 */


Status Insertion_Sort_Nondec(vector<int> &vi);
// 练习 2.1-2
Status Insertion_Sort_Nonasc(vector<int> &vi);
// 练习 2.1-3
Status Find_value(vector<int> &vi, int n, int &index);
// 练习 2.1-4
vector<int> Bin_Addition(vector<int> &v1, vector<int> &v2);
// 练习 2.2-3
Status Select_Sort_Nondec(vector<int> &vi);
template <typename T>
void swap(T &a, T &b);

void Merge(vector<int> &A, int p, int q, int r);
Status Merge_Sort_Impl(vector<int> &A, int p, int r);
Status Merge_Sort(vector<int> &A);
#endif