#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <memory>

#include "consoleadapter.h"
#include "poetrylibrary.h"
#include "poetrylibraryfileadapter.h"
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
  MOCK_METHOD(void, writeLines, (const std::string &lines), (override));
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

TEST(poetryTest, shouldGiveVersesWhenAskedForPoetryWithSupportOfAFileAdapter) {
  auto fileAdapter = std::make_shared<PoetryLibraryFileAdapter>(
      std::string(PROJECT_PATH) + "/test/poem.txt");

  PoetryReader poetryReader(fileAdapter);

  std::string verses = poetryReader.giveMeSomePoetry();

  EXPECT_EQ(
      verses,
      "Le Dormeur du ValC'est un trou de verdure o\xC3\xB9 chante une "
      "rivi\xC3\xA8reAccrochant follement aux herbes des haillonsD'argent ; "
      "o\xC3\xB9 le soleil, de la montagne fi\xC3\xA8re,Luit : c'est un petit "
      "val qui mousse de rayons.Un soldat jeune, bouche ouverte, t\xC3\xAAte "
      "nue,Et la nuque baignant dans le frais cresson bleu,Dort ; il est "
      "\xC3\xA9tendu dans l'herbe sous la nue,P\xC3\xA2le dans son lit vert "
      "o\xC3\xB9 la lumi\xC3\xA8re pleut.Les pieds dans les gla\xC3\xAF"
      "euls, il dort. Souriant commeSourirait un enfant malade, il fait un "
      "somme :Nature, berce-le chaudement : il a froid.Les parfums ne font pas "
      "frissonner sa narine ;Il dort dans le soleil, la main sur sa "
      "poitrineTranquille. Il a deux trous rouges au c\xC3\xB4t\xC3\xA9 "
      "droit.-- Arthur Rimbaud");
}
