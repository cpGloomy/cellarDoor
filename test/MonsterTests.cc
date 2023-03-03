#include <gtest/gtest.h>

#include "../src/monster.h"

struct MonsterTest : public ::testing::Test {
  Monster* monster;
  Monster* monster2;

  virtual void SetUp() override {
    monster = new Monster();
    monster2 = new Monster("Giant Rat");
  }

  virtual void TearDown() override {
    delete monster;
    delete monster2;
  }
};

TEST_F(MonsterTest, CanCreateMonster) { EXPECT_TRUE(monster); }

TEST_F(MonsterTest, CanNameMonsterWithConstructor) {
  EXPECT_EQ(monster2->GetName(), "Giant Rat");
}

TEST_F(MonsterTest, CanNameMonsterWithSetter) {
  monster->SetName("Giant Rat");
  EXPECT_EQ(monster->GetName(), "Giant Rat");
}

TEST_F(MonsterTest, MonsterCreatedAlive) { EXPECT_TRUE(monster->IsAlive()); }