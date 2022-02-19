#include <iostream>
#include <fstream>
#include <string>
#include <vector>
 
using namespace std;
 
class element {
public:
    int n, x;
 
    element(int val, int str_num) {
        x = val;
        n = str_num;
    }
};
 
bool operator<(element a, element b) {
    return a.x < b.x;
}
 
class Queue {
private:
    vector<element> A;
 
    void heapify(int pos) {
        int left = pos * 2 + 1;
        int right = pos * 2 + 2;
        int smallest = pos;
 
        if (left < A.size() && A[left] < A[smallest])
            smallest = left;
        if (right < A.size() && A[right] < A[smallest])
            smallest = right;
 
        if (pos != smallest) {
            swap(A[pos], A[smallest]);
            heapify(smallest);
        }
    }
 
    void build_heap() {
        int mid = A.size() / 2;
        for (int i = mid; i >= 0; i--)
            heapify(i);
    }
 
public:
    void push(element new_el) {
        A.push_back(new_el);
        build_heap();
    }
 
    string extract_min() {
        if (A.empty())
            return "*";
 
        string result;
        result = to_string(A[0].x);
        A.erase(A.begin());
        build_heap();
        return result;
    }
 
    void decrease_key(int str_num, int new_val) {
        int pos = 0;
        while (A[pos].n != str_num)
            pos++;
        A[pos].x = new_val;
        build_heap();
    }
};
 
int main() {
    ifstream inp("priorityqueue.in");
    ofstream out("priorityqueue.out");
 
    Queue A;
    int str_num = 1;
    while (!inp.eof()) {
        string command;
        inp >> command;
        if (command == "push") {
            int val;
            inp >> val;
            element buff(val, str_num);
            A.push(buff);
        }
        if (command == "extract-min") {
            out << A.extract_min() << endl;
        }
        if (command == "decrease-key") {
            int str, new_val;
            inp >> str >> new_val;
            A.decrease_key(str, new_val);
        }
        str_num++;
    }
 
    inp.close();
    out.close();
    return 0;
}
