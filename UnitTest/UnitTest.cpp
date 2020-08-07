#include "pch.h"
#include "CppUnitTest.h"
#include "../CivilProject/Arc.h"
#include "../CivilProject/ArcImpl.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(ImplArcTest)
	{
	public:
		TEST_METHOD(BaseFunctional)
		{
      try// todo correct processing bad alloc or replace to notrow

        /*
         ArcImpl *p = new(nothrow) ArcImpl();
         if (p == NULL)
        */
      {
        ArcImpl *p = new ArcImpl();
        p->setAngleFirst(0.);
        p->setAngleSecond(160.);
        p->setRadiuse(0.4);
        p->setCenter(Point2d(5., 5.));

        Assert::AreEqual(0., p->getAngleFirst());
        Assert::AreEqual(160., p->getAngleSecond());

        Assert::AreEqual(0.4, p->getRadiuse());

        Assert::AreEqual(5., p->getCenter().x());
        Assert::AreEqual(5., p->getCenter().y());
        delete p;
      }
      catch (std::bad_alloc&t)
      {
        std::cout << t.what() << std::endl;
      }


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
