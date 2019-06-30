/////////////////////////////////////////////////////////////////////////////
// PassFunc.cpp - function accepting both function pointer and functor     //
//                                                                         //
// Jim Fawcett, CSE687 - Object Oriented Design, Demonstration Spring 2013 //
/////////////////////////////////////////////////////////////////////////////

#include <iostream>

typedef void (*fptr)(double d);

template<typename T>
void testFunction(T t)
{
  std::cout << "\n  from function: value is " << t;
}

template<typename T>
class TestFunctor {
public:
  void operator()(T t)
  {
    std::cout << "\n  from functor:  value is " << t;
  }
};

template <typename Arg>
void TestArgs(Arg arg)
{
  arg(3.1415927);
}

int main()
{
  TestArgs(testFunction<double>);
  TestArgs(TestFunctor<double>());
  TestArgs(testFunction<int>);
  TestArgs(TestFunctor<int>());

  std::cout << "\n\n";
  return 0;
}