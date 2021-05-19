//
// Created by Jerry on 2021/5/13.
//

#include "SearchUtils.h"

int SearchUtils::binarySearch(const int *const data, int size, int toFind) {
    int lo = 0;
    int hi = size - 1;
    while (lo <= hi) {
        int mid = lo + ((hi - lo) >> 1);
        int midVal = *(data + mid);
        if (midVal > toFind) {
            hi = mid - 1;
        } else if (midVal < toFind) {
            lo = mid + 1;
        } else {
            return mid;
        }
    }
    return ~lo;
}
