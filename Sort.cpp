#include <queue>
#include <iostream>
using std::cout;
using std::queue;

template<typename T>
queue<T> merge(T* begin, T* end) {
    if(end - begin == 1) {
        return queue<T>({*begin});
    }

    T* mid = begin + (end-begin)/2;
    auto left = merge(begin, mid);
    auto right = merge(mid, end);

    queue<T> res;
    while(!left.empty() && !right.empty()) {
        if(left.front() < right.front()) {
            res.push(left.front());
            left.pop();
        } else {
            res.push(right.front());
            right.pop();
        }
    }
    while(!left.empty()) {
        res.push(left.front());
        left.pop();
    }
    while(!right.empty()) {
        res.push(right.front());
        right.pop();
    }
    return res;
}

template<typename T>
void MergeSort(T* begin, T* end) {
    auto s = merge(begin, end);
    for(T* p = begin; p != end; p++) {
        *p = s.front();
        s.pop();
    }
}


int main() {
    int mas[10] = {5, 2, 1, 9, 3, 4, 1, 0, -1, 1};
    for(int val: mas) {
        cout << val << ' ';
    }
    cout << '\n';
    MergeSort(mas, mas + 10);
    for(int val: mas) {
        cout << val << ' ';
    }
    cout << '\n';
}