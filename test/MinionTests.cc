#include <gtest/gtest.h>

#include <string>

#include "../src/minion.h"

struct MinionTest : public ::testing::Test {
  Minion* minion;
  MinionType* skeleton;

  virtual void SetUp() override {
    skeleton = new MinionType("Skeleton", "45", "1", "0");
    minion = new Minion(skeleton);
  }

  virtual void TearDown() override { delete minion; }
};

struct MinionJSONTest : public ::testing::Test {
  Json::Value value;
  MinionType* skeleton;
  Minion* minion;

  virtual void SetUp() override {
    value["name"] = "Skeleton";
    value["baseHP"] = "45";
    value["startingLevel"] = "1";
    value["startingExps"] = "0";

    MinionType obj = fromJson<MinionType>(value);
    skeleton = new MinionType(obj);
    minion = new Minion(skeleton);
  }

  virtual void TearDown() override { delete minion; }
};

TEST_F(MinionJSONTest, MinionJSONCreatedWithName) {
  EXPECT_EQ(minion->GetName(), "Skeleton");
}

TEST_F(MinionJSONTest, MinionJSONCreatedIsAlive) {
  EXPECT_TRUE(minion->IsAlive());
}

TEST_F(MinionJSONTest, MinionJSONCreatedIsAlly) {
  EXPECT_TRUE(minion->IsAlly());
}

TEST_F(MinionJSONTest, MinionJSONCreatedWith45StartingHealth) {
  EXPECT_EQ(minion->GetStats(MobilesStatSheet::Stats::maxHP), 45);
}

TEST_F(MinionJSONTest, MinionJSONCreatedWith1StartingLevel) {
  EXPECT_EQ(minion->GetStats(MobilesStatSheet::Stats::level), 1);
}

TEST_F(MinionJSONTest, MinionJSONCreatedWith0StartingExp) {
  EXPECT_EQ(minion->GetStats(MobilesStatSheet::Stats::experience), 0);
}

TEST_F(MinionTest, MinionCreatedWithName) {
  EXPECT_EQ(minion->GetName(), "Skeleton");
}

TEST_F(MinionTest, MinionCreatedIsAlive) { EXPECT_TRUE(minion->IsAlive()); }

TEST_F(MinionTest, MinionCreatedIsAlly) { EXPECT_TRUE(minion->IsAlly()); }

TEST_F(MinionTest, MinionCreatedWith45StartingHealth) {
  EXPECT_EQ(minion->GetStats(MobilesStatSheet::Stats::maxHP), 45);
}

TEST_F(MinionTest, MinionCreatedWith1StartingLevel) {
  EXPECT_EQ(minion->GetStats(MobilesStatSheet::Stats::level), 1);
}

TEST_F(MinionTest, MinionCreatedWith0StartingExp) {
  EXPECT_EQ(minion->GetStats(MobilesStatSheet::Stats::experience), 0);
}