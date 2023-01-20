#include <consoleadapter.h>
#include <poetryreader.h>

#include <iostream>

int main() {
  auto poetryReader = std::make_shared<PoetryReader>();
  ConsoleAdapter consoleAdapter(poetryReader);
  std::cout << "Here is some poems : \n\n";
  consoleAdapter.ask();
  std::cout << "\n\nType enter to exit";
  std::cin.get();

  return 0;
}
