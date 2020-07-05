#pragma once


class heapNode{

    public:
        char val;
        int freq;
        heapNode* left;
        heapNode* right;

    heapNode();
    heapNode(char val,int freq);
    ~heapNode();
  
};