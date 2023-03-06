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

TEST(TestMonster, CanCreateMonsterAsMobile) {
  Mobiles* monster = new Monster();
  EXPECT_TRUE(monster);
  delete monster;
}

TEST(TestMonster, CanCreateMonsterWithName) {
  Mobiles* monster = new Monster("Giant Rat");
  EXPECT_EQ(monster->GetName(), "Giant Rat");
  delete monster;
}

TEST(TestMonster, CanNameMonsterWithSetter) {
  Mobiles* monster = new Monster();
  monster->SetName("Giant Rat");
  EXPECT_EQ(monster->GetName(), "Giant Rat");
  delete monster;
}

TEST(TestMonster, MonsterCreatedAlive) {
  Mobiles* monster = new Monster();
  EXPECT_TRUE(monster->IsAlive());
  delete monster;
}

TEST(TestMonster, CreateGiantRat) {
  Mobiles* monster = new Monster(new GiantRat());
  EXPECT_EQ(monster->GetName(), "Giant Rat");
}