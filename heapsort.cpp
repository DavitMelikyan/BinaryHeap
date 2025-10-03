#include <iostream>
#include <vector>

template <typename T>
void heapify(std::vector<T>& vec, int size, int i) {
    int index = i; 
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < size && vec[left] > vec[index]) index = left;
    if (right < size && vec[right] > vec[index]) index = right;
    if (index != i) {
        std::swap(vec[i], vec[index]);
        heapify(vec, size, index);
    }
}

template <typename T>
void buildHeap(std::vector<T>& vec) {
    for (int i = vec.size() / 2 - 1; i >= 0; --i) heapify(vec, vec.size(), i);
}

template <typename T>
void heapSort(std::vector<T>& vec) {
    buildHeap(vec);
    for (int i = vec.size() - 1; i >= 0; --i) {
        std::swap(vec[0], vec[i]);
        heapify(vec, i, 0);
    }
}

int main() {
    std::vector<int> vec = {8, 5, 7, 30, 99, 3, 42, 11, 11, 0, 2, 2};
    heapSort(vec);
    for (auto& it : vec) std::cout << it << " ";
    std::cout << std::endl;
}