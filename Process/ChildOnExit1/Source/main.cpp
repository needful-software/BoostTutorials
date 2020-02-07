/*
    Copyright (c) 2020 Xavier Leclercq
    Released under the MIT License
    See https://github.com/NeedfulSoftware/BoostTutorials/blob/master/LICENSE.txt
*/

#include <boost/process/child.hpp>
#include <boost/process/async.hpp>
#include <iostream>

int main(int argc, char* argv[])
{
    // We need to pass in our own execution context if we want to use an exit handler.
    boost::asio::io_context execution_context;

    // The exit handler.
    auto on_exit_handler = [](int exit, const std::error_code& ec_in)
    {
        std::cout << "Child process has finished." << std::endl;
    };
    
    // Create the child process, pass in our execution context and our exit handler.
    boost::process::child childProcess("HelloWorld", execution_context, boost::process::on_exit = on_exit_handler);
    
    std::cout << "Child process has been created." << std::endl;

    // When we run the execution context it will wait until the exit handler has been called.
    // Note that if we didn't do this the parent program would not wait at all and the boost::process::child would
    // terminate the child program if it was still running.
    execution_context.run();
   
    return 0;
}
