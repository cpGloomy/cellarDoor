#include <gtest/gtest.h>

#include "../src/character.h"

struct CharacterTest : public ::testing::Test {
  Character* character;
  Character* character2;

  virtual void SetUp() override {
    character = new Character();
    character2 = new Character("Omerye");
  }

  virtual void TearDown() override {
    delete character;
    delete character2;
  }
};

TEST(TestCharacter, CanCreatecharacterAsMobile) {
  Mobiles* character = new Character();
  EXPECT_TRUE(character);
  delete character;
}

TEST(TestCharacter, CanCreatecharacterWithName) {
  Mobiles* character = new Character("Omerye");
  EXPECT_EQ(character->GetName(), "Omerye");
  delete character;
}

TEST(TestCharacter, CanNamecharacterWithSetter) {
  Mobiles* character = new Character();
  character->SetName("Omerye");
  EXPECT_EQ(character->GetName(), "Omerye");
}

TEST(TestCharacter, characterCreatedAlive) {
  Mobiles* character = new Character();
  EXPECT_TRUE(character->IsAlive());
}