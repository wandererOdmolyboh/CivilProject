#include "pch.h"
#include "CppUnitTest.h"
//#include "../CivilProject/Arc.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
      Assert::AreEqual(1, 1);
		}
	};

  TEST_CLASS(UCopyConstruct)
  {
  public:

    TEST_METHOD(TestMethod1)
    {
      Assert::AreEqual(1, 1);
    }
  };

  TEST_CLASS(USetTest)
  {
  public:

    TEST_METHOD(TestMethod1)
    {
      Assert::AreEqual(1, 1);
    }
  };

  TEST_CLASS(UDrawTest)
  {
  public:
    TEST_METHOD(TestMethod1)
    {
      Assert::AreEqual(1, 1);
    }
  };
  TEST_CLASS(UIsValidTest)
  {
  public:

    TEST_METHOD(TestMethod1)
    {
      Assert::AreEqual(1, 1);
    }
  };

}
