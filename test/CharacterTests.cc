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

TEST_F(CharacterTest, CanCreateCharacter) { EXPECT_TRUE(character); }

TEST_F(CharacterTest, CanNameCharacterWithConstructor) {
  EXPECT_EQ(character2->GetName(), "Omerye");
}

TEST_F(CharacterTest, CanNameCharacterWithSetter) {
    character->SetName("Omerye");
  EXPECT_EQ(character->GetName(), "Omerye");
}

TEST_F(CharacterTest, CreatedCharacterIsAlive) {
  EXPECT_TRUE(character->IsAlive());
}