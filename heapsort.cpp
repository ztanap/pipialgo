#include <iostream>
#include <vector>
#include <algorithm> 


using namespace std;

class MinHeap {
public:
    MinHeap() {
        data.push_back(-1);
        lastIndex = 0;
    }

    vector<int> data;
    int lastIndex;

    void push(int n);
    int pop();

};

void MinHeap::push(int n) {
    data.push_back(n);
    int l = ++lastIndex;

    while (l != 1) {
        if (data[l] > data[l / 2]) break;
        swap(data[l], data[l / 2]);
        l = l / 2;
    }
}

int MinHeap::pop() {
    if (lastIndex < 1) return -1;
    int r = data[1];
    int l = 1;
    
    swap(data[1], data[lastIndex--]);
    while (l <= lastIndex) {
        int cl = l * 2 > lastIndex ? INT_MAX : data[l * 2];
        int cr = l * 2 + 1 > lastIndex ? INT_MAX : data[l * 2 + 1];

        if (cl == INT_MAX && cr == INT_MAX) break;   

        if(data[l] > min(cl, cr)) swap(data[l], cl < cr ? data[l*2] : data[l*2 + 1]);
        l = min(cl, cr);
    }

    return r;
}

void main() {
    MinHeap* mh = new MinHeap();
    mh->push(5);
    mh->push(3);
    mh->push(1);
    mh->push(6);
    mh->push(2);
    cout << mh->pop() << endl;
    cout << mh->pop() << endl;
    cout << mh->pop() << endl;
    cout << mh->pop() << endl;
    cout << mh->pop() << endl;

	getchar();
	return;
}
