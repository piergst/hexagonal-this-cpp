#include <gtest/gtest.h>

#include "poetrylibrary.h"
#include "poetryreader.h"
#include <memory>

using namespace testing;


TEST(poetryTest, shouldGiveVersesWhenAskedForPoetry) {
  // arrange
  std::unique_ptr<IRequestVerses> poetryReader = std::make_unique<PoetryReader>(); 

  // act
  std::string verses = poetryReader->giveMeSomePoetry(); 

  // assert
  EXPECT_EQ(verses, "I want to sleep\r\nSwat the flies\r\nSoftly, please.\r\n\r\n-- Masaoka Shiki (1867-1902)"); 
}



TEST(poetryTest, shouldGiveVersesWhenAskedForPoetryWithTheSupportOfAPoetryLibrary) {

  // arrange
  std::shared_ptr<IObtainPoems> poetryLibrary = std::make_shared<PoetryLibrary>(); 
  std::unique_ptr<IRequestVerses> poetryReader = std::make_unique<PoetryReader>(poetryLibrary); 

  // act
  std::string verses = poetryReader->giveMeSomePoetry(); 

  // assert
  EXPECT_EQ(verses, "If you could read a leaf or tree\r\nyou’d have no need of books.\r\n-- © Alistair Cockburn (1987)"); 

}