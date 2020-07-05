#include "heapNode.h"
#include<iostream>

heapNode::heapNode()
{
    freq = 0;
    val = 'a';
}

heapNode::heapNode(char v,int freq) : freq(freq), val(v),  left(NULL),right(NULL)
{
}

heapNode::~heapNode()
{
}
