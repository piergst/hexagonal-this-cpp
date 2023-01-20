#ifndef IWRITELINES_H
#define IWRITELINES_H
#include <iostream>
#include <string>

class IWriteLines {
 public:
  virtual void writeLines(std::string text) = 0;
};

class ConsolePublicationStrategy : public IWriteLines {
 public:
  void writeLines(std::string text) { std::cout << text; }
};

#endif