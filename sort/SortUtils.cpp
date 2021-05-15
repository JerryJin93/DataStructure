//
// Created by Jerry on 2021/5/12.
//
#include "SortUtils.h"

void SortUtils::bubbleSort(int *data, int len) {
    for (int i = 0; i < len; ++i) {
        bool flag = false;
        for (int j = 0; j < len - i - 1; ++j) {
            if (data[j] > data[j + 1]) {
                swap(data[j], data[j + 1]);
                flag = true;
            }
        }
        if (!flag) break;
    }
}

void SortUtils::quickSort(int *data, int lo, int hi) {
    if (lo < hi) {
        int loc = partition(data, lo, hi);
        quickSort(data, lo, loc - 1);
        quickSort(data, loc + 1, hi);
    }
}

int SortUtils::partition(int *data, int lo, int hi) {
    int pivotal = *(data + lo);
    int start = lo;
    int end = hi;

    while (start < end) {
        while (*(data + start) <= pivotal) {
            start++;
        }
        while (*(data + end) > pivotal) {
            end--;
        }
        if (start < end) {
            swap(*(data + start), *(data + end));
        }
    }
    swap(*(data + lo), *(data + end));
    return end;
}

void SortUtils::swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

void SortUtils::insertionSort(int *data, int len) {
    int temp;
    int j;
    for (int i = 1; i < len; ++i) {
        temp = *(data + i);
        j = i - 1;
        while (j >= 0 && *(data + j) > temp) {
            *(data + j + 1) = *(data + j);
            j--;
        }
        *(data + j + 1) = temp;
    }
}

void SortUtils::selectionSort(int *data, int len) {
    for (int i = 0; i < len - 1; ++i) {
        int min = i;
        for (int j = i + 1; j < len; ++j) {
            if(*(data + j) < *(data + min)) {
                min = j;
            }
        }
        if (min != i) {
            swap(*(data + i), *(data + min));
        }
    }
}
