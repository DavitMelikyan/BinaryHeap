#include <iostream>
#include <vector>

template <typename T>
class MaxHeap {
private:
    std::vector<T> maxheap;  
    size_t m_size;
    size_t m_capacity;     
public:
    MaxHeap(size_t cap) : m_size{0}, m_capacity{cap} {
        maxheap.resize(m_capacity);
    }

    void buildHeap(const std::vector<T>& vec) {
        m_capacity = vec.size();
        m_size = m_capacity;
        maxheap = vec;
        for (int i = (m_size - 1) / 2; i >= 0; --i) heapify(i);
    }

    void heapify(int i) {
        int index = i;           
        int left = 2 * i + 1;      
        int right = 2 * i + 2;     
        if (left < m_size && maxheap[left] > maxheap[index]) index = left;
        if (right < m_size && maxheap[right] > maxheap[index]) index = right;
        if (index != i) {
            std::swap(maxheap[i], maxheap[index]);  
            heapify(index);               
        }
    }

    T top() {
        return maxheap[0];
    }
    
    void push(T value) {
        if (m_size == m_capacity) {
            m_capacity *= 2;
            maxheap.resize(m_capacity);
        }
        maxheap.push_back(value);
        m_size++;
        while (i != 0 && maxheap[(i - 1) / 2] < maxheap[i]) {
            std::swap(maxheap[i], maxheap[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    void pop() {
        if (m_size <= 0) return; 
        if (m_size == 1) {
            --m_size;
            maxheap.pop_back();
            return;
        }
        std::swap(maxheap[0], maxheap[m_size - 1]);
        maxheap.pop_back();
        --m_size;
        heapify(0);  
    }
};