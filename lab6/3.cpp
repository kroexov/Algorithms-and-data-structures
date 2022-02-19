#include <iostream>
#include <fstream>
#include <list>
 
using namespace std;
ifstream inp("linkedmap.in");
ofstream out("linkedmap.out");
 
struct Element{
    string key;
    string val;
    Element *previous=nullptr;
    Element *nexta=nullptr;
};
Element *cur;
list<Element> Hash [500000];
 
long long int number(string key){
    long long int summ=0;
    long long int power=2;
    for (int i=0;i<key.size();i++){
        summ+=key[i]*power;
        power=power*2;
    }
    return summ%500000;
}
 
void put(string key, string val){
    long long int num=number(key);
    //if (elsize==0){
    //    elsize++;
    //    Element *First = new Element;
    //    First->key=key;
    //    First->val=val;
    //    First->previous=nullptr;
    //    First->nexta=nullptr;
    //    Hash[num][0]=*First;
    //    cur=First;
    //    return;
    // }
    for (list <Element>::iterator i=Hash[num].begin();i!=Hash[num].end();i++){
        if (i->key==key) {
            i->val=val;
            //map[num][i].prev=cur;
            //cur->next=&map[num][i];
            //cur = &map[num][i];
            return; //надо проверить
        }
    }
    Element *newby=new Element;
    newby->val=val;
    newby->key=key;
    Hash[num].push_back(*newby);
    if (cur==nullptr)
        cur=&Hash[num].back();
    else {
        Hash[num].back().previous=cur;
        cur->nexta = &Hash[num].back();
        cur=&Hash[num].back();
    }
}
void get(string key){
    long long int num=number(key);
    if (Hash[num].empty()) {
        out<<"none"<<endl;
        return;
    }
    for (list <Element>::iterator i=Hash[num].begin();i!=Hash[num].end();i++) {
        if (i->key == key) {
            out << i->val << endl;
            return;
        }
    }
    //out<<"Error: no "<<key<<endl;
    out<<"none"<<endl;
}
//bool keyn (Element a, string key){return (a.key==key);}
 
void del(string key){
    long long int num=number(key);
    if (Hash[num].empty()) {
        return;
    }
    for (list <Element>::iterator i=Hash[num].begin();i!=Hash[num].end();i++) {
        if (i->key == key) {
            if (i->key==cur->key) {
                cur = cur->previous;
            }
            if (i->previous!=nullptr)
                i->previous->nexta=i->nexta;
            if (i->nexta!=nullptr)
                i->nexta->previous=i->previous;
            Hash[num].erase(i);
            return;
        }
    }
}
void prev(string key){
    long long int num=number(key);
    if (Hash[num].empty()) {
        out<<"none"<<endl;
        return;
    }
    for (list <Element>::iterator i=Hash[num].begin();i!=Hash[num].end();i++) {
        if (i->key == key) {
            if (i->previous!=nullptr) {
                out <<i->previous->val << endl;
            }
            else
                out<<"none"<<endl;
            //out<<"error: wrong prev"<<endl;
            return;
        }
    }
    //out<<"Error: no "<<key<<endl;
    out<<"none"<<endl;
 
}
void next(string key){
    long long int num=number(key);
    if (Hash[num].empty()) {
        out<<"none"<<endl;
        return;
    }
    for (list <Element>::iterator i=Hash[num].begin();i!=Hash[num].end();i++) {
        if (i->key == key) {
            if (i->nexta!=nullptr) {
                out <<i->nexta->val << endl;
            }
            else
                out<<"none"<<endl;
            //out<<"error: wrong next"<<endl;
            return;
        }
    }
    //out<<"Error: no "<<key<<endl;
    out<<"none"<<endl;
 
}
int main() {
    //Element Hash[50000][10];
    while (!inp.eof()) {
        string command;
        inp >> command;
        if (command=="put"){
            string val;
            string key;
            inp >> key >> val;
            put(key,val);
        }
        if (command=="get"){
            string key;
            inp >> key;
            get(key);
        }
        if (command=="delete"){
            string key;
            inp >> key;
            del(key);
        }
        if (command=="prev"){
            string key;
            inp >> key;
            prev(key);
        }
        if (command=="next"){
            string key;
            inp >> key;
            next(key);
        }
    }
 
    return 0;
}
