#ifndef IWRITELINES_H
#define IWRITELINES_H
#include <iostream>
#include <string>

class IWriteLines {
 public:
  virtual void writeLines(const std::string &lines) = 0;
};

class ConsolePublicationStrategy : public IWriteLines {
 public:
  void writeLines(const std::string &lines) { std::cout << lines; }
};

#endif