/*
    Copyright (c) 2020 Xavier Leclercq
    Released under the MIT License
    See https://github.com/NeedfulSoftware/BoostTutorials/blob/master/LICENSE.txt
*/

#include <boost/chrono.hpp>
#include <boost/thread/thread.hpp> 
#include <iostream>

int main(int argc, char* argv[])
{
    // Wait for 2 seconds just to slow down child program enough that it becomes
    // visible that we are waiting for its completion in the parent program
    boost::this_thread::sleep_for(boost::chrono::seconds(2));

    std::cout << "Hello World!" << std::endl;

    return 0;
}
