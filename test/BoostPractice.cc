#include "../src/boostpractice.h"

#include <gtest/gtest.h>

struct BoostTestSave : public ::testing::Test {
  mobilestypeBoost* m_;
  std::string file_ = "./data/boostTest.txt";
  std::ofstream ofs;

  virtual void SetUp() override {
    ofs = std::ofstream(file_.c_str());
    m_ = new mobilestypeBoost("Giant Rat", 45, 1, 0);
  }
  virtual void TearDown() override { delete m_; }
};

TEST_F(BoostTestSave, OFSIsOpen) { EXPECT_TRUE(ofs.is_open()); }

TEST_F(BoostTestSave, OFSWritesToFileWithoutException) {
  EXPECT_NO_THROW({
    boost::archive::text_oarchive oa(ofs);
    oa << *m_;
  });
}

struct BoostTestLoad : public ::testing::Test {
  mobilestypeBoost* m_;
  std::string file_ = "./data/boostTest.txt";
  std::ifstream ifs;

  virtual void SetUp() override {
    ifs = std::ifstream(file_.c_str());
    m_ = new mobilestypeBoost();
    boost::archive::text_iarchive ia(ifs);
    ia >> *m_;
  }

  virtual void TearDown() override { delete m_; }
};

TEST_F(BoostTestLoad, IFSIsOpen) { EXPECT_TRUE(ifs.is_open()); }

TEST_F(BoostTestLoad, LoadedMobilesTypeHasNameGiantRat) {
  EXPECT_EQ(m_->GetName(), "Giant Rat");
}

TEST_F(BoostTestLoad, LoadedMobilesTypeHPis45) { EXPECT_EQ(m_->GetHP(), 45); }
TEST_F(BoostTestLoad, LoadedMobilesTypeHasLevel1) {
  EXPECT_EQ(m_->GetLevel(), 1);
}
TEST_F(BoostTestLoad, LoadedMobilesTypeHasEXP0) { EXPECT_EQ(m_->GetExp(), 0); }