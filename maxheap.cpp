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
        maxheap.push_back(value);
        m_size++;
        size_t i = m_size - 1;
        while (i != 0 && maxheap[(i - 1) / 2] < maxheap[i]) {
            std::swap(maxheap[i], maxheap[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    void pop() {
        if (m_size <= 0) return; 
        std::swap(maxheap[0], maxheap[m_size - 1]);
        maxheap.pop_back();
        --m_size;
        heapify(0);  
    }
};

int main() {
    std::vector<int> vec = {3, 10, 5, 6, 2, 9};
    MaxHeap<int> h(vec.size());
    h.buildHeap(vec);

    std::cout << "Top after buildHeap: " << h.top() << std::endl; 
    h.push(15);
    h.push(7);
    std::cout << "Top after pushes: " << h.top() << std::endl;
    h.pop();
    std::cout << "Top after one pop: " << h.top() << std::endl;
    h.pop();
    std::cout << "Top after second pop: " << h.top() << std::endl;

    return 0;
}
