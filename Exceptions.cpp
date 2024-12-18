// Exceptions.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Fernando Lomeli
//

#include <iostream>

//Custom exception class
class customException : public std::exception {
public:
    const char* what() const override {
        return "Custom exception has been thrown.";
    }
};

bool do_even_more_custom_application_logic()
{
    // TODO: Throw any standard exception

    std::cout << "Running Even More Custom Application Logic." << std::endl;

    throw std::exception("Throwing a standard exception.");

    return true;
}
void do_custom_application_logic()
{
    // TODO: Wrap the call to do_even_more_custom_application_logic()
    //  with an exception handler that catches std::exception, displays
    //  a message and the exception.what(), then continues processing
    std::cout << "Running Custom Application Logic." << std::endl;

    try {
        if (do_even_more_custom_application_logic())
        {
            std::cout << "Even More Custom Application Logic Succeeded." << std::endl;
        }
    }

    // Catches the standard exception thrown by the function do_even_more_custom_application_logic()
    catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    // TODO: Throw a custom exception derived from std::exception
    //  and catch it explictly in main
    throw customException();

    std::cout << "Leaving Custom Application Logic." << std::endl;

}

float divide(float num, float den)
{
    // TODO: Throw an exception to deal with divide by zero errors using
    //  a standard C++ defined exception
    if (den == 0) {
        throw std::runtime_error("Divide by zero error caught.");
    }
    return (num / den);
}

void do_division() noexcept
{
    //  TODO: create an exception handler to capture ONLY the exception thrown
    //  by divide.

    float numerator = 10.0f;
    float denominator = 0;

    try {
        auto result = divide(numerator, denominator);
        std::cout << "divide(" << numerator << ", " << denominator << ") = " << result << std::endl;
    }
    catch (const std::runtime_error& e) {
        std::cout << e.what() << std::endl;
    }
}

int main()
{
    std::cout << "Exceptions Tests!" << std::endl;

    // TODO: Create exception handlers that catch (in this order):
    //  your custom exception
    //  std::exception
    //  uncaught exception 
    //  that wraps the whole main function, and displays a message to the console.

    try {
        do_division();
        do_custom_application_logic();
    }
    //Custom exception handler
    catch (const customException& e) {
        std::cout << e.what() << std::endl;
    }
    //std::exception handler 
    catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    //Uncaught exception handler
    catch (...) {
        std::cout << "Uncaught exception has been caught." << std::endl;
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu