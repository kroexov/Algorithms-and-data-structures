#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <map>
 
const int ALPH_POWER = 'z' - 'A' + 1;
 
int main() {
    std::ifstream inp("search1.in");
    std::ofstream out("search1.out");
    std::string text, pattern;
    inp >> pattern >> text;
 
    int *pi = new int[pattern.length() + 1];
    pi[0] = 0;
    pi[1] = 0;
    for (int i = 1, j = 0; i < pattern.length();) {
        if (pattern[i] == pattern[j]) {
            pi[i + 1] = j + 1;
            i++, j++;
        } else if (j > 0)
            j = pi[j];
        else {
            pi[i + 1] = 0;
            i++;
        }
    }
 
    auto transitions = *(new std::vector<std::map<int, int>>(pattern.length() + 1));
 
    for (int i = 0; i < pattern.length(); i++)
        transitions[i][pattern[i] - 'A'] = i + 1;
 
    for (int i = 1; i <= pattern.length(); i++) {
        for (int j = 0; j < ALPH_POWER; j++)
            if (transitions[i].find(j) == transitions[i].end() && transitions[pi[i]].find(j) != transitions[pi[i]].end())
                transitions[i][j] = transitions[pi[i]][j];
    }
 
    std::vector<int> positions;
    int currentState = 0;
    for (int i = 0; i < text.length(); i++) {
        currentState = transitions[currentState][text[i] - 'A'];
        if (currentState == pattern.length())
            positions.push_back(i - pattern.length() + 2);
    }
 
    out << positions.size() << '\n';
    for (auto pos : positions)
        out << pos << ' ';
 
    inp.close();
    out.close();
 
    return 0;
}
