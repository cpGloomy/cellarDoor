#include <gtest/gtest.h>

#include "../src/character.h"

struct CharacterTest : public ::testing::Test {
  Character* character;

  virtual void SetUp() override {
    character = new Character("Omerye", new MobilesStatSheet(100, 1, 0, 5, 15));
  }

  virtual void TearDown() override { delete character; }
};

TEST_F(CharacterTest, CharacterCreatedWithName) {
  EXPECT_EQ(character->GetName(), "Omerye");
}

TEST_F(CharacterTest, CharacterCreatedIsAlive) {
  EXPECT_TRUE(character->IsAlive());
}

TEST_F(CharacterTest, CharacterCreatedIsAlly) {
  EXPECT_TRUE(character->IsAlly());
}

TEST_F(CharacterTest, CharacterCreatedWith100StartingHealth) {
  EXPECT_EQ(character->GetStats(MobilesStatSheet::Stats::maxHP), 100);
}

TEST_F(CharacterTest, CharacterCreatedWith1StartingLevel) {
  EXPECT_EQ(character->GetStats(MobilesStatSheet::Stats::level), 1);
}

TEST_F(CharacterTest, CharacterCreatedWith0StartingExp) {
  EXPECT_EQ(character->GetStats(MobilesStatSheet::Stats::experience), 0);
}