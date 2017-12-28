/*
    Copyright (c) 2017 Xavier Leclercq

    Permission is hereby granted, free of charge, to any person obtaining a
    copy of this software and associated documentation files (the "Software"),
    to deal in the Software without restriction, including without limitation
    the rights to use, copy, modify, merge, publish, distribute, sublicense,
    and/or sell copies of the Software, and to permit persons to whom the
    Software is furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in
    all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
    THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
    FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
    IN THE SOFTWARE.
*/

#include <boost/thread/thread.hpp>
#include <iostream>

void ThreadMain()
{
    std::cout << "Printed from thread: " << boost::this_thread::get_id() << std::endl;
}

int main(int argc, char* argv[])
{
    // This creates a thread and immediately starts executing it
    boost::thread thread1(ThreadMain);

    std::cout << "Printed from thread: " << boost::this_thread::get_id() << std::endl;

    // Give some time for the other thread to print its message
    // to the console. There are better ways to do this but we
    // keep it simple for now.
    boost::this_thread::sleep_for(boost::chrono::seconds(1));

    return 0;
}
