#include <gtest/gtest.h>

#include <string>

#include "../src/character.h"
#include "../src/combantant.h"
#include "../src/monster.h"

struct CombantantTests : public ::testing::Test {
  Monster* monster;
  MobilesType* giantRat;
  Character* player;
  Combantant* c1;
  Combantant* c2;

  virtual void SetUp() override {
    giantRat = new MobilesType("Giant Rat", 45, 1, 0);
    monster = new Monster(giantRat);
    player = new Character("Omerye", new MobilesStatSheet(100, 1, 0));
    c1 = new Combantant(player);
    c1->SetTarget(monster);
    c2 = new Combantant(monster);
    c2->SetTarget(player);
  }

  virtual void TearDown() override {
    delete monster;
    delete player;
    delete c1;
    delete c2;
  }
};
TEST_F(CombantantTests, C1TriesToAttackC2AliveFalse) {
  c2->self_->SetAlive(false);
  EXPECT_FALSE(c1->DoAttack());
}
TEST_F(CombantantTests, C1TriesToAttackC2AliveTrue) {
  c2->self_->SetAlive(true);
  EXPECT_TRUE(c1->DoAttack());
}
TEST_F(CombantantTests, C1Deals10DamageToC2) {
  c2->self_->SetStats(STATS::currentHP, 45);
  c1->DoAttack();
  EXPECT_EQ(c2->self_->GetStats(STATS::currentHP), 35);
}
/*TEST_F(CombantantTests, C1Deals45DamagetoC2ExpectC2Dead) {
  c2->self_->SetStats(STATS::currentHP, 45);
  c1->DoAttack();
  EXPECT_FALSE(c2->self_->IsAlive());
}*/