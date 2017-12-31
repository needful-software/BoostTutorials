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

#include <boost/system/system_error.hpp>
#include <boost/system/windows_error.hpp>
#include <boost/system/linux_error.hpp>
#include <iostream>

void MockOpenFileFailure()
{
    boost::system::error_code errorCode;

#ifdef _WIN32
    errorCode = boost::system::windows_error::make_error_code(boost::system::windows_error::path_not_found);
#else
    errorCode = boost::system::error_code(boost::system::errc::no_such_file_or_directory, boost::system::system_category());
#endif

    throw boost::system::system_error(errorCode);
}

int main(int argc, char* argv[])
{
    try
    {
        MockOpenFileFailure();
    }
    catch (const boost::system::system_error& e)
    {
        std::cout << "Exception thrown: " << e.code() << ", " << e.what() << std::endl;

        boost::system::error_condition errorCondition = e.code().default_error_condition();
        std::cout << "error_condition: " << errorCondition.value() << ", " << errorCondition.message() << std::endl;
    }

    return 0;
}
