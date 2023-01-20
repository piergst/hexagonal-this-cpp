#ifndef POETRYREADER_H
#define POETRYREADER_H
#include "iobtainpoems.h"
#include "irequestverses.h"

// Hexagon definition
class PoetryReader : public IRequestVerses {
 public:
  PoetryReader()
      : m_poetryLibrary{std::make_shared<HardCodedPoetryLibrary>()} {}

  PoetryReader(std::shared_ptr<IObtainPoems> poetryLibrary)
      : m_poetryLibrary{poetryLibrary} {}

  std::string giveMeSomePoetry() const override {
    return m_poetryLibrary->getMeAPoem();
  }

 private:
  std::shared_ptr<IObtainPoems> m_poetryLibrary;
};
#endif