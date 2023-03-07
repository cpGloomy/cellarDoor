#include <gtest/gtest.h>

#include <string>

#include "../src/monster.h"

struct MonsterTest : public ::testing::Test {
  Monster* monster;
  MobilesType* giantRat;

  virtual void SetUp() override {
    giantRat = new MobilesType("Giant Rat", "45", "1", "0");
    monster = new Monster(giantRat);
  }

  virtual void TearDown() override { delete monster; }
};

TEST_F(MonsterTest, MonsterCreatedWithName) {
  EXPECT_EQ(monster->GetName(), "Giant Rat");
}

TEST_F(MonsterTest, MonsterCreatedIsAlive) { EXPECT_TRUE(monster->IsAlive()); }

TEST_F(MonsterTest, MonsterCreatedIsNotAlly) {
  EXPECT_FALSE(monster->IsAlly());
}

TEST_F(MonsterTest, MonsterCreatedWith45StartingHealth) {
  EXPECT_EQ(monster->GetStats(MobilesStatSheet::Stats::maxHP), 45);
}

TEST_F(MonsterTest, MonsterCreatedWith1StartingLevel) {
  EXPECT_EQ(monster->GetStats(MobilesStatSheet::Stats::level), 1);
}

TEST_F(MonsterTest, MonsterCreatedWith0StartingExp) {
  EXPECT_EQ(monster->GetStats(MobilesStatSheet::Stats::experience), 0);
}

struct MonsterJSONTest : public ::testing::Test {
  Json::Value value;
  MobilesType* giantRat;
  Monster* monster;

  virtual void SetUp() override {
    value["name"] = "Giant Rat";
    value["baseHP"] = "45";
    value["startingLevel"] = "1";
    value["startingExps"] = "0";

    MobilesType obj = fromJson<MobilesType>(value);
    giantRat = new MobilesType(obj);
    monster = new Monster(giantRat);
  }

  virtual void TearDown() override { delete monster; }
};

TEST_F(MonsterJSONTest, MonsterJSONCreatedWithName) {
  EXPECT_EQ(monster->GetName(), "Giant Rat");
}

TEST_F(MonsterJSONTest, MonsterJSONCreatedIsAlive) {
  EXPECT_TRUE(monster->IsAlive());
}

TEST_F(MonsterJSONTest, MonsterJSONCreatedIsNOTAlly) {
  EXPECT_FALSE(monster->IsAlly());
}

TEST_F(MonsterJSONTest, MonsterJSONCreatedWith45StartingHealth) {
  EXPECT_EQ(monster->GetStats(MobilesStatSheet::Stats::maxHP), 45);
}

TEST_F(MonsterJSONTest, MonsterJSONCreatedWith1StartingLevel) {
  EXPECT_EQ(monster->GetStats(MobilesStatSheet::Stats::level), 1);
}

TEST_F(MonsterJSONTest, MonsterJSONCreatedWith0StartingExp) {
  EXPECT_EQ(monster->GetStats(MobilesStatSheet::Stats::experience), 0);
}
