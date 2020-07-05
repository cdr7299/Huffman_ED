#include "heap.h"
#include "heapNode.h"
#include <iostream>

using namespace std;

//construtor default
MinHeap ::MinHeap() : heap_size(0)
{
}

//constructor with vector

MinHeap::MinHeap(vector<heapNode *> temp) : heap_size(temp.size()), heap(temp)
{
    Heapify();
}

//destructor
MinHeap::~MinHeap()
{
}

//utility to swap two ints
void MinHeap::swap(heapNode **a, heapNode **b)
{
    heapNode *temp = *a;
    *a = *b;
    *b = temp;
}

//generic Heapify to call with the constructor that get's a un-Heapified vector
void MinHeap ::Heapify()
{
    //Call Min-Heapify for all the internal nodes of the heap
    for (int i = heap.size() / 2; i >= 0; i--)
    {
        MinHeapify(i);
    }
}

void MinHeap ::MinHeapify(int i)
{

    int l = left(i);
    int r = right(i);

    int smallest = i;

    if (l < heap_size && heap[l]->freq < heap[i]->freq)
        smallest = l;

    if (r < heap_size && heap[r]->freq < heap[smallest]->freq)
        smallest = r;

    if (smallest != i)
    {
        swap(&heap[i], &heap[smallest]);
        MinHeapify(smallest);
    }
}

int MinHeap::left(int i)
{
    return 2 * i + 1;
}

int MinHeap::right(int i)
{
    return 2 * i + 2;
}

heapNode *MinHeap::getMin()
{
    return heap[0];
}

heapNode *MinHeap::ExtractMin()
{
    heapNode *to_ret = heap[0];
    heapNode *temp = heap[heap_size - 1];
    heap.erase(heap.end() - 1);
    heap_size--;
    heap[0] = temp;
    MinHeapify(0);
    return to_ret;
}

void MinHeap::test_p()
{
    cout << "Printing heap\n";
    for (auto x : heap)
        cout << x->val << " " << x->freq << " " << endl;

    cout << endl;
}

void MinHeap::insert(char x, int f)
{

    heapNode *temp = new heapNode(x, f);
    heap.push_back(temp);
    heap_size++;
    int i = heap_size - 1;
    while (i >= 0 && heap[i]->freq < heap[(i - 1) / 2]->freq)
    {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void MinHeap::insert(heapNode *temp)
{

    heap.push_back(temp);
    heap_size++;
    int i = heap_size - 1;
    while (i >= 0 && heap[i]->freq < heap[(i - 1) / 2]->freq)
    {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void MinHeap::buildHuffman()
{

    cout << "Building heap now..\n" ;
    while (heap_size != 1)
    {
        // cout << "New iteration..\n";
        heapNode *first = ExtractMin();
        heapNode *second = ExtractMin();
        // cout << "First extracted Node -> " << first->val << " " << first->freq << endl;
        // cout << "Second extracted Node -> " << second->val << " " << second->freq << endl;

        heapNode *newOne = new heapNode('$', (first->freq + second->freq));

        newOne->left = first;
        newOne->right = second;
        insert(newOne);
    }

    // cout << "Top freq is : " << heap[0]->freq << endl;
    // cout << "left child is : " << heap[0]->left->val << " " << heap[0]->left->freq << endl;
    // cout << "right child is : " << heap[0]->right->val << " " << heap[0]->right->freq << endl;
}

void MinHeap::save_tree(heapNode *root, string temp, bool left, bool right)
{

    if (left)
        temp = temp + "0";
    if (right)
        temp = temp + "1";

    if (root == NULL)
        return;

    if (root->left == NULL && root->right == NULL)
    {
        um[root->val] = temp;
        return;
    }

    save_tree(root->left, temp, true, false);
    save_tree(root->right, temp, false, true);
}

void MinHeap::saveCodes()
{
    string temp = "";
    heapNode *root = heap[0];
    save_tree(root, temp, false, false);
}


void MinHeap::printInfo(map<char, int> test,string str){
    //count number of bits in the encoded string
    int ans = 0;
    //print the saved data first
    for(auto i : um){
        if(i.first == ' ' ){
            cout<<"space "<<i.second<<endl;
        }
        else{
            cout<<i.first<<" "<<i.second<<endl;
        }    
    }

    //we need to get the frequency of the characters
    for(auto x: test){
        ans = ans +  um[x.first].length() * x.second;
    }

    cout<<"New number of bits " <<ans<<endl;

    cout << "----------------------------------------" << endl;
    for(auto x:str){
        cout<<um[x]<<" ";
    }
    cout<<endl;
    cout << "----------------------------------------" << endl;

}


void MinHeap::encode(map<char, int> test,string str){
    buildHuffman();
    saveCodes();
    printInfo(test,str);
}