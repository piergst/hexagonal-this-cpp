#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <memory>

#include "consoleadapter.h"
#include "poetrylibrary.h"
#include "poetryreader.h"

using namespace testing;
using ::testing::AtLeast;

TEST(poetryTest, shouldGiveVersesWhenAskedForPoetry) {
  // arrange
  auto poetryReader = std::make_unique<PoetryReader>();

  // act
  std::string verses = poetryReader->giveMeSomePoetry();

  // assert
  EXPECT_EQ(verses,
            "I want to sleep\r\nSwat the flies\r\nSoftly, please.\r\n\r\n-- "
            "Masaoka Shiki (1867-1902)");
}

TEST(poetryTest,
     shouldGiveVersesWhenAskedForPoetryWithTheSupportOfAPoetryLibrary) {
  // arrange
  auto poetryLibrary = std::make_shared<PoetryLibrary>();
  auto poetryReader = std::make_unique<PoetryReader>(poetryLibrary);

  // act
  std::string verses = poetryReader->giveMeSomePoetry();

  // assert
  EXPECT_EQ(verses,
            "If you could read a leaf or tree\r\nyou’d have no need of "
            "books.\r\n-- © Alistair Cockburn (1987)");
}

class MockForIWriteLines : public IWriteLines {
 public:
  MOCK_METHOD(void, writeLines, (std::string text), (override));
};

TEST(poetryTest, shouldGiveVersesWhenAskedForPoetryTroughtAConsoleAdapter) {
  // arrange
  auto poetryLibrary = std::make_shared<PoetryLibrary>();
  auto poetryReader = std::make_shared<PoetryReader>(poetryLibrary);
  auto mockForIWriteLines = std::make_shared<MockForIWriteLines>();
  ConsoleAdapter consoleAdapter(poetryReader, mockForIWriteLines);

  // assert
  EXPECT_CALL(*mockForIWriteLines,
              writeLines("If you could read a leaf or tree\r\nyou’d have no "
                         "need of books.\r\n-- © Alistair Cockburn (1987)"))
      .Times(AtLeast(1));

  // act (call of "writeLines" is inside)
  consoleAdapter.ask();
}