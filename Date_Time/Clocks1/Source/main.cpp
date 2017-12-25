/*
    Copyright (c) 2015-2017 Xavier Leclercq

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

#include <boost/date_time/posix_time/posix_time.hpp>
#include <iostream>

int main(int argc, char* argv[])
{
    // In this example we will use different clocks to get the current time
    // with different resolution levels
    
    // Get the current day only
    boost::gregorian::date currentDay = boost::gregorian::day_clock::universal_day();
    std::cout << "Day: " << currentDay << std::endl;

    // Get the current time with a resolution of 1 second
    boost::posix_time::ptime currentSecond = boost::posix_time::second_clock::universal_time();
    std::cout << "Time: " << currentSecond << std::endl;

    // Get the current time with a resolution of 1 microsecond
    boost::posix_time::ptime currentMicrosecond = boost::posix_time::microsec_clock::universal_time();
    std::cout << "Time: " << currentMicrosecond << std::endl;

    return 0;
}
