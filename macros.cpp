
#include <iostream>
#include <string>
#include <sstream>
std::string getOsName()
{
#ifdef _WIN32
    return "Windows 32-bit";
#elif _WIN64
    return "Windows 64-bit";
#elif __linux__
    return "Linux";
#elif __FreeBSD__
    return "FreeBSD";
#elif __unix || __unix__
    return "Unix";
#elif __APPLE__ || __MACH__
    return "Mac OSX";
#else
    return "Other";
#endif
}
using namespace std;
int main()
{
    std::string str = "Helloworld";
    std::istringstream in(str);
    std::string word1, word2;
    cout << in.tellg() << endl;
    in >> word1;
    cout << in.tellg() << endl;
    in.seekg(5); // rewind
    cout << in.tellg() << endl;
    in >> word2;
    cout << in.tellg() << endl;

    std::cout << "word1 = " << word1 << '\n'
              << "word2 = " << word2 << '\n';
}