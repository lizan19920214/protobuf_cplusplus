#include <stdio.h>
#include <stdlib.h>
#include <iostream>
 
 using namespace std;

 int main(int argc, char *argv[])
 {
    for (int i = 0; i < argc; i++)
    {
        std::string str = argv[i];
        cout << str << endl;
    }
    
    system("pause");
    return 0;
 }