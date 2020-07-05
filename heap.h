#pragma once
#include<vector>
#include "heapNode.h"
#include <string>
#include <map>

using namespace std;

class MinHeap{

    private:
        vector<heapNode *> heap;
        unsigned int heap_size;
        //for easily saving the codes
        map<char,string> um;

    public:
     
    MinHeap();
    MinHeap(vector<heapNode * > temp);
    ~MinHeap();
    void insert(char x , int f);
    void insert(heapNode* temp);
    void findMin();
    void deleteMin();
    void Heapify();
    void MinHeapify(int i);
    int left(int i);
    int right(int i);
    void swap(heapNode **a, heapNode ** b);
    heapNode* getMin();
    heapNode* ExtractMin();
    void test_p();
    void buildHuffman();
    void saveCodes();
    void save_tree(heapNode* root, string temp, bool left, bool right);
    void printInfo(map<char, int> test,string str);
    void encode(map<char, int> test,string str);
};