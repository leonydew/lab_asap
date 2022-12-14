#include <iostream>
int main() {
    unsigned short x;
    std::cin >> x;
    unsigned char* y = (unsigned char*)&x;
    std::cout << (int)(*y) << std::endl;
    std::cout << (int)(*(y+1)) << std::endl;
    return 0;
}