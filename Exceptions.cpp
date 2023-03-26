// Exceptions.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

// custom exception
class myexception : public std::exception
{
    public:
        virtual const char* what() const throw()
        {
            return "My Custom CPP Exception Thrown";
        }
};

bool do_even_more_custom_application_logic()
{
  // TODO: Throw any standard exception , done

  throw std::invalid_argument("throwing standard exception");

  std::cout << "Running Even More Custom Application Logic." << std::endl;

  return true;
}

void do_custom_application_logic()
{
  // TODO: Wrap the call to do_even_more_custom_application_logic()
  //  with an exception handler that catches std::exception, displays
  //  a message and the exception.what(), then continues processing. done
  std::cout << "Running Custom Application Logic." << std::endl;

  try {
      do_even_more_custom_application_logic();
  }
  catch (const std::invalid_argument& e) {
      std::cout << "Error: " << e.what() << '\n';
  }

  // TODO: Throw a custom exception derived from std::exception
  //  and catch it explictly in main, done

  myexception e;
  throw e;

  std::cout << "Leaving Custom Application Logic." << std::endl;

}

float divide(float num, float den)
{
  // TODO: Throw an exception to deal with divide by zero errors using
  //  a standard C++ defined exception, done

  if (den == 0) {
    throw std::runtime_error("Divide by zero error");
  }

  return (num / den);
}

void do_division() noexcept
{
  //  TODO: create an exception handler to capture ONLY the exception thrown
  //  by divide.  done

  float numerator = 10.0f;
  float denominator = 0;

  try {
      auto result = divide(numerator, denominator);
      std::cout << "divide(" << numerator << ", " << denominator << ") = " << result << std::endl;
  }
  catch (const std::runtime_error& e) {
      std::cout << "Error: " << e.what() << '\n';
  }
}

int main()
{
  std::cout << "Exceptions Tests!" << std::endl;

  // TODO: Create exception handlers that catch (in this order):
  //  your custom exception, done 
  //  std::exception, done
  //  uncaught exception 
  //  that wraps the whole main function, and displays a message to the console.  done
  try {
      do_division();

      try {
          do_custom_application_logic();
      }
      catch (myexception me) {
          std::cout << "Error: " << me.what() << '\n';
      }
  }
  catch (...) {
      std::cout << "Error: Uncaught exception found" << '\n';
  }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu