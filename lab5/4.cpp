#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <map>
#include <vector>
 
using namespace std;
 
ifstream inp("quack.in");
ofstream out("quack.out");
 
#define vec vector<string>
 
class Interpreter {
private:
    queue<unsigned short> QUE;
    map<string,int> labels;
    map<char,int> registers;
    vec commands;
    ofstream out;
public:
    void Start() {
        int i = 0;
        while (i < commands.size()) {
            string command = commands[i];
            unsigned short a;
            unsigned short b;
            if (command.empty())
                continue;
            switch (command[0]) {
                case '+':
                    a = deque();
                    b = deque();
                    QUE.push(a + b);
                    i++;
                    break;
                case '-':
                    a = deque();
                    b = deque();
                    QUE.push(a - b);
                    i++;
                    break;
                case '*':
                    a = deque();
                    b = deque();
                    QUE.push(a*b);
                    i++;
                    break;
                case '/':
                    a = deque();
                    b = deque();
                    if (b!=0)
                        QUE.push(a/b);
                    else
                        QUE.push(0);
                    i++;
                    break;
                case '%':
                    a = deque();
                    b = deque();
                    if (b!=0)
                        QUE.push(a%b);
                    else
                        QUE.push(0);
                    i++;
                    break;
                case '>':
                    registers[command[1]] = deque();
                    i++;
                    break;
                case'<':
                    QUE.push(registers[command[1]]);
                    i++;
                    break;
                case 'P':
                    if (command.size() == 1)
                        out<<deque()<<endl;
                    else
                        out<<registers[command[1]]<<endl;
                    i++;
                    break;
                case 'C':
                    if (command.size() == 1)
                        out<<char(deque()%256);
                    else
                        out<<char(registers[command[1]]%256);
                    i++;
                    break;
                case 'Z':
                    if (registers[command[1]] == 0)
                        i = labels[command.substr(2)];
                    else
                        i++;
                    break;
                case 'J':
                    i = labels[command.substr(1)];
                    break;
                case 'E':
                    if (registers[command[1]] == registers[command[2]])
                        i = labels[command.substr(3)];
                    else
                        i++;
                    break;
                case 'G':
                    if (registers[command[1]] > registers[command[2]])
                        i = labels[command.substr(3)];
                    else
                        i++;
                    break;
                case ':':
                    i++;
                    break;
                case 'Q':
                    return;
                default:
                    QUE.push(stoi(command));
                    i++;
                    break;
            }
        }
    }
    void regs_init() {
        for (int i = 0; i < 26; i++)
            registers[i] = 0;
        out.open("quack.out");
    }
    unsigned short deque(){
        unsigned short first=QUE.front();
        QUE.pop();
        return first;
    }
    void command_get(){
        while (!inp.eof()) {
            string command;
            getline(inp, command);
            if (!command.empty())
                commands.push_back(command);
        }
 
    }
    void label_set(){
        for (int i = 0; i < commands.size(); i++) {
            string command = commands[i];
            if (command[0] == ':') {
                labels[command.substr(1)] = i;
            }
        }
    }
    void run() {
        regs_init();
        command_get();
        label_set();
        Start();
    }
 
};
int main() {
    Interpreter inter;
    inter.run();
    return 0;
}
