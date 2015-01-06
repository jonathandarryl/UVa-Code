#include <iostream>
#include <string>
#include <algorithm>

int main(void)
{
    std::string astring(" Test Test Test ");
    std::remove(astring.begin(), astring.end(), ' ');
    std::cout << astring << std::endl;
    return 0;
}
