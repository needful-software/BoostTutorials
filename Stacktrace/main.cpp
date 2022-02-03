#define BOOST_STACKTRACE_USE_BACKTRACE
#include <boost/stacktrace.hpp>
#include <iostream>

int main(int argc, char* argv[])
{
    std::cout << boost::stacktrace::stacktrace() << std::endl;
    std::cout << "hello" << std::endl;
}
