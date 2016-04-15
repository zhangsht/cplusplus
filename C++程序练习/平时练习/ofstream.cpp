#include <fstream>
#include <iostream>
//#include <string>
#include <stdlib.h>
int main() {
    char buf[255];
    std::ifstream in("tem.txt");
    if (!in.eof()) {
        in.getline(buf, 30);
        std::cout << buf << std::endl;
    }
    return 0;
}
