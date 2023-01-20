#ifndef POETRYLIBRARYFILEADAPTER_H
#define POETRYLIBRARYFILEADAPTER_H
#include <fstream>
#include <iostream>

#include "../domain/iobtainpoems.h"

class PoetryLibraryFileAdapter : public IObtainPoems {
 public:
  PoetryLibraryFileAdapter(const std::string &filePath) {
    try {
      m_poem = this->stringFromFile(filePath);

    } catch (const std::exception &e) {
      std::cerr << e.what();
    }
  }

  std::string stringFromFile(const std::string &filePath) {
    std::fstream file;
    file.open(filePath);
    if (!file.is_open()) {
      throw std::runtime_error(std::string("Cannot find file : " + filePath) +
                               std::string("\nIn function : ") + __func__);
    }
    std::string line;
    std::string fileContent;
    while (file) {
      std::getline(file, line);
      fileContent += line;
    }
    file.close();
    return fileContent;
  }

  std::string getMeAPoem() const override { return m_poem; }

 private:
  std::string m_poem;
};

#endif
