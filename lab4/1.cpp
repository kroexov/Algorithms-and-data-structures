#include <iostream>
#include <fstream>
 
using namespace std;
 
class stackcomm {
private:
    int* stack;
    int num = 0;
public:
    stackcomm(const int size) {
        stack = new int[size];
    }
 
    void push(int val) {
        stack[num] = val;
        num++;
    }
 
    int pop() {
        num--;
        return stack[num];
    }
};
 
 
int main() {
    ifstream inp("stack.in");
    ofstream out("stack.out");
 
 
    int n;
    inp >> n;
    stackcomm stack(n);
 
    for (int i = 0; i < n; i++) {
        char command;
        inp >> command;
        if (command == '+') {
            int val;
            inp >> val;
            stack.push(val);
        }
        if (command == '-') {
            out << stack.pop() << endl;
        }
    }
 
    return 0;
}
