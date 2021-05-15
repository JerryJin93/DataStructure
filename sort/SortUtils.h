//
// Created by Jerry on 2021/5/12.
//

#ifndef DATASTRUCTURE_SORTUTILS_H
#define DATASTRUCTURE_SORTUTILS_H


class SortUtils {
private:
    static void swap(int &a, int &b);
    static int partition(int *data, int lo, int hi);

public:
    static void bubbleSort(int *data, int len);
    static void quickSort(int *data, int lo, int hi);
    static void insertionSort(int *data, int len);
    static void selectionSort(int *data, int len);
};


#endif //DATASTRUCTURE_SORTUTILS_H
