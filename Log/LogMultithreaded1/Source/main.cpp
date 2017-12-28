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

#include <boost/log/trivial.hpp>
#include <boost/thread/thread.hpp>

// A function that counts from 0 to 4 and sleeps for 1ms between each
// number. That time was chosen because it produces good interleaving 
// on my computer.
void CountSlowly()
{
    BOOST_LOG_TRIVIAL(info) << "Thread id: " << boost::this_thread::get_id();
    for (int i = 0; i < 5; ++i)
    {
        BOOST_LOG_TRIVIAL(info) << "i: " << i;

        boost::this_thread::sleep_for(boost::chrono::milliseconds(1));
    }
}

int main(int argc, char* argv[])
{
    BOOST_LOG_TRIVIAL(info) << "Main thread id: " << boost::this_thread::get_id();

    // Create and run 2 threads that execute CountSlowly()
    boost::thread thread1(CountSlowly);
    boost::thread thread2(CountSlowly);

    // The main thread also executes CountSlowly()
    CountSlowly();

    // Wait for the launched threads to complete
    thread1.join();
    thread2.join();

    return 0;
}
