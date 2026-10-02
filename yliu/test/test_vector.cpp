#include <gtest/gtest.h>
#include "yliu/vector.hpp"


TEST(VectorTest, DefaultConstructEmpty)
{
  yliu::vector<int> v;

  EXPECT_TRUE(v.empty());
  EXPECT_EQ(v.size(), 0u);
  EXPECT_EQ(v.capacity(), 0u);
}

TEST(VectorTest, TestPushBackL)
{
  yliu::vector<int> v;
  int x = 5;

  v.push_back(x);

  EXPECT_FALSE(v.empty());
  EXPECT_EQ(v.size(), 1);
  EXPECT_EQ(v.capacity(), 2);
}

TEST(VectorTest, TestPushBackR)
{
  yliu::vector<std::string> v;

  v.push_back("hello there");

  EXPECT_FALSE(v.empty());
  EXPECT_EQ(v.size(), 1);
  EXPECT_EQ(v.capacity(), 2);
}

TEST(VectorTest, TestIncCap)
{
  yliu::vector<int> v;

  for (int i = 0; i < 1000; i++) {
    v.push_back(i);
  }

  EXPECT_EQ(v.capacity(), 1024);
  EXPECT_EQ(v.size(), 1000);

  for (int i = 0; i < 1000; ++i) {
    EXPECT_EQ(v[i], i);
  }
}

TEST(VectorTest, TestClear)
{
  yliu::vector<int> v;

  for (int i = 0; i < 1000; ++i) {
    v.push_back(i);
  }

  v.clear();

  EXPECT_EQ(v.capacity(), 1024);
  EXPECT_EQ(v.size(), 0);
  EXPECT_TRUE(v.empty());
  EXPECT_THROW(v[0], std::out_of_range);
}


TEST(VectorTest, TestEquality)
{
  yliu::vector<int> v;
  yliu::vector<int> x;

  EXPECT_TRUE((x == v));

  for (int i = 0; i < 1000; ++i) {
    v.push_back(i);
    x.push_back(i);
  }

  EXPECT_TRUE((x == v));
}

TEST(VectorTest, TestCopyConstruct)
{
  yliu::vector<int> v;


  for (int i = 0; i < 1000; ++i) {
    v.push_back(i);
  }

  yliu::vector<int> x(v);

  EXPECT_TRUE((x == v));
  EXPECT_EQ(x.capacity(), v.capacity());
}

TEST(VectorTest, TestMoveConstruct)
{
  yliu::vector<std::string> v;


  for (int i = 0; i < 1000; ++i) {
    v.push_back(std::to_string(i));
  }

  yliu::vector<std::string> x(std::move(v));

  EXPECT_FALSE((x == v));
  EXPECT_FALSE(x.capacity() == v.capacity());
  EXPECT_EQ(v.capacity(), 0);
  EXPECT_EQ(v.size(), 0);
  EXPECT_EQ(x.capacity(), 1024);
  EXPECT_EQ(x.size(), 1000);

  for (int i = 0; i < 1000; ++i) {
    EXPECT_EQ(x[i], std::to_string(i));
  }
}
