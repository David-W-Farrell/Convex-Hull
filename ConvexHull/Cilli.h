// David Farrell

#ifndef CILLI_H
#define CILLI_H

#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;

struct CNode{
    int val; 
        CNode *next; 
        CNode *prev;
    
    public:
        CNode(int B) : val(B), next(nullptr), prev(nullptr){}
};

class Cilli{

    public:
        Cilli();
        ~Cilli();
        void insertItem(int v);
        void dumpForwards() const;
        void moveHandleForward();
        void moveHandleBack(); 
        int getValAtHandle() const;
        void deleteItem();   

    private:

        CNode* handle;
        CNode* firstNode;

};

#endif
