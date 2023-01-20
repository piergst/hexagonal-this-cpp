#ifndef CONSOLEADAPTER_H
#define CONSOLEADAPTER_H

#include "irequestverses.h"
#include "iwritelines.h"

class ConsoleAdapter {
 public:
  ConsoleAdapter(std::shared_ptr<IRequestVerses> poetryReader,
                 std::shared_ptr<IWriteLines> publicationStrategy)
      : m_poetryReader(poetryReader),
        m_publicationStrategy(publicationStrategy) {}

  ~ConsoleAdapter() {}

  void ask() {
    std::string verses = m_poetryReader->giveMeSomePoetry();
    m_publicationStrategy->writeLines(verses);
  }

 private:
  std::shared_ptr<IRequestVerses> m_poetryReader;
  std::shared_ptr<IWriteLines> m_publicationStrategy;
};

#endif