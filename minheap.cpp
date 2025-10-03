#include <iostream>
#include <vector>

template <typename T>
class MinHeap {
private:
    std::vector<T> minheap;  
    size_t m_size;
    size_t m_capacity;     
public:
    MinHeap(size_t cap) : m_size{0}, m_capacity{cap} {
        minheap.resize(m_capacity);
    }

    void buildHeap(const std::vector<T>& vec) {
        m_capacity = vec.size();
        m_size = m_capacity;
        minheap = vec;
        for (int i = (m_size - 1) / 2; i >= 0; --i) heapify(i);
    }

    void heapify(int i) {
        int index = i;           
        int left = 2 * i + 1;      
        int right = 2 * i + 2;     
        if (left < m_size && minheap[left] < minheap[index]) index = left;
        if (right < m_size && minheap[right] < minheap[index]) index = right;
        if (index != i) {
            std::swap(minheap[i], minheap[index]);  
            heapify(index);               
        }
    }

    T top() {
        return minheap[0];
    }
    
    void push(T value) {
        if (m_size == m_capacity) {
            m_capacity *= 2;
            minheap.resize(m_capacity);
        }
        m_size++;
        int i = m_size - 1;
        minheap[i] = value;
        while (i != 0 && minheap[(i - 1) / 2] > minheap[i]) {
            std::swap(minheap[i], minheap[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    void pop() {
        if (m_size <= 0) return; 
        if (m_size == 1) {
            --m_size;
            minheap.pop_back();
            return;
        }
        std::swap(minheap[0], minheap[m_size - 1]);
        minheap.pop_back();
        --m_size;
        heapify(0);  
    }
};