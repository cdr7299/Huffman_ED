#include "heap.h"
// This program shows how C++-based file I/O works.
// It will print a file to the screen two times.

// included so we can use cout
#include <iostream>
// file I/O
#include <fstream>
// cstdlib is where exit() lives
#include <cstdlib>
#include<unordered_map>

// using namespace std;

// // we want to use parameters

using namespace std;

int main(int argc,char** argv)
{

    if (argc != 2) {
        cout << "Must supply the input file name as the one and only parameter" << endl;
        exit(1);
    }


    ifstream file(argv[1]);
    if (!file.is_open()) {
        cout << "Unable to open '" << argv[1] << "' for reading" << endl;
        exit(2);
    }

    char g;
    while (file.get(g)) {
        cout << g;
    }

    cout << "----------------------------------------" << endl;

    file.clear(); // Clears the _state_ of the file, not its contents!
    file.seekg(0);

    //test will read the data and help to build the heap
    map<char, int> test;
    string str = "";
    int count = 0;
    while (file.get(g)) {
        
        if(g != '\n'){
            str = str + g;
            test[g]++;
            count++;
        }
    }

    cout<<"Total bits : "<<sizeof(char) * count * 8 <<endl;

    file.close();

    //now we make a vector out of heapNodes.
    vector<heapNode*> rD;
    for(auto x : test){
        heapNode* temp = new heapNode(x.first,x.second);
        rD.push_back(temp);
    }
    
    MinHeap minheap(rD);
    minheap.encode(test,str);
    return 0;

}


