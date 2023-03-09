#include <gtest/gtest.h>

#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <string>

#include "../src/loader.h"
#include "../src/mobilestype.h"
#include "../src/saver.h"

struct MobilesTypeConstructorTest : public ::testing::Test {
  MobilesType* skeleton_;

  virtual void SetUp() override {
    skeleton_ = new MobilesType("Skeleton", 45, 1, 0);
  }

  virtual void TearDown() override { delete skeleton_; }
};

TEST_F(MobilesTypeConstructorTest, CreateMobileWithNameSkeleton) {
  EXPECT_EQ(skeleton_->GetName(), "Skeleton");
}

TEST_F(MobilesTypeConstructorTest, CreateMobileWithHP45) {
  EXPECT_EQ(skeleton_->GetHP(), 45);
}

TEST_F(MobilesTypeConstructorTest, CreateMobileWithLevel1) {
  EXPECT_EQ(skeleton_->GetLevel(), 1);
}

TEST_F(MobilesTypeConstructorTest, CreateMobileWith) {
  EXPECT_EQ(skeleton_->GetExp(), 0);
}

struct MobilesTypeSaveTest : public ::testing::Test {
  MobilesType* skeleton_;
  Saver* saver_;
  std::string filename_;

  virtual void SetUp() override {
    saver_ = Saver::GetInstance();
    skeleton_ = new MobilesType("Skeleton", 45, 1, 0);
    filename_ += "./data/";
    filename_ += skeleton_->GetName() += ".txt";
  }

  virtual void TearDown() override { delete skeleton_; }
};

TEST_F(MobilesTypeSaveTest, FilenameIsDataSkeletonTxt) {
  EXPECT_EQ(filename_, "./data/Skeleton.txt");
}

TEST_F(MobilesTypeSaveTest, SaverSaveDoesNotThrowException) {
  EXPECT_NO_THROW(
      { Saver::GetInstance()->save(*skeleton_, filename_.c_str()); });
}

struct MobilesTypeLoadTest : public ::testing::Test {
  MobilesType* skeleton_;
  Loader* loader_;
  std::string filename_;

  virtual void SetUp() override {
    loader_ = Loader::GetInstance();
    skeleton_ = new MobilesType();
    filename_ += "./data/Skeleton.txt";
    loader_->load(*skeleton_, filename_.c_str());
  }

  virtual void TearDown() override { delete skeleton_; }
};

TEST_F(MobilesTypeLoadTest, FilenameIsDataSkeletonTxt) {
  EXPECT_EQ(filename_, "./data/Skeleton.txt");
}

TEST_F(MobilesTypeLoadTest, LoadedMobilesTypeHasNameSkeleton) {
  EXPECT_EQ(skeleton_->GetName(), "Skeleton");
}

TEST_F(MobilesTypeLoadTest, LoadedMobilesTypeHPis45) {
  EXPECT_EQ(skeleton_->GetHP(), 45);
}
TEST_F(MobilesTypeLoadTest, LoadedMobilesTypeHasLevel1) {
  EXPECT_EQ(skeleton_->GetLevel(), 1);
}
TEST_F(MobilesTypeLoadTest, LoadedMobilesTypeHasEXP0) {
  EXPECT_EQ(skeleton_->GetExp(), 0);
}