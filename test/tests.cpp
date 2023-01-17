
#include <gtest/gtest.h>
#include <memory>

using namespace testing;

class IRequestVerses
{
public:
    virtual std::string giveMeSomePoetry() const = 0; 
};

class PoetryReader : public IRequestVerses
{
public:
    std::string giveMeSomePoetry() const override {
      
      return "I want to sleep\r\nSwat the flies\r\nSoftly, please.\r\n\r\n-- Masaoka Shiki (1867-1902)"; 
    }
};

TEST(poetryTest, shouldGiveVersesWhenAskedForPoetry) {

  // arrange
  std::unique_ptr<IRequestVerses> poetryReader = std::make_unique<PoetryReader>(); 

  // act
  std::string verses = poetryReader->giveMeSomePoetry(); 

  // assert
  EXPECT_EQ(verses, "I want to sleep\r\nSwat the flies\r\nSoftly, please.\r\n\r\n-- Masaoka Shiki (1867-1902)"); 
}