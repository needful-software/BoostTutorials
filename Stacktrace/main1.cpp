#include <iostream>
#include <unistd.h>
#include <execinfo.h>

int main(int argc, char* argv[])
{
    std::cout << getpid() << std::endl;

    system(("cat /proc/" + std::to_string(getpid()) + "/maps").c_str());

    system(("pstack " + std::to_string(getpid())).c_str());

    system(("cat /proc/" + std::to_string(getpid()) + "/stack").c_str());
   
   void* addrlist[100];

    // retrieve current stack addresses
    int addrlen = backtrace(addrlist, sizeof(addrlist) / sizeof(void*));

    if (addrlen == 0) {
	return 0;
    }

    // resolve addresses into strings containing "filename(function+address)",
    // this array must be free()-ed
    backtrace_symbols_fd(addrlist, addrlen, 1); 
    int* i = 0;
    *i = 5;

    return 0;
}
