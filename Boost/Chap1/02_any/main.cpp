#include <boost/any.hpp>
#include <iostream>
#include <vector>
#include <string>

int main(){
  std::vector<boost::any> some_values;
  some_values.push_back(10);
  const char* c_str = "Hello there!";
  some_values.push_back(c_str);
  some_values.push_back(std::string("Wow! "));

  std::string& s = boost::any_cast<std::string&>(some_values.back());
  s += " That is great!\n";
  std::cout << s;
  return 0;
}

void example_func(){
  boost::any variable(std::string("Hello world!"));

  std::string s1 = boost::any_cast<std::string>(variable);

  std::string* s2 = boost::any_cast<std::string>(&variable);
}