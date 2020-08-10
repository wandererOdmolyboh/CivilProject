#include "pch.h"
#include "CppUnitTest.h"
#include "../CivilProject/Point2d.h"
#include "../CivilProject/Point2d.cpp"
#include "../CivilProject/ArcImpl.h"
#include "../CivilProject/ArcImpl.cpp"
#include "../CivilProject/IBaseObject.h"
#include "../CivilProject/IBaseObject.cpp"
#include "../../CivilProject/CivilProject/BaseImpl.h"
#include "../../CivilProject/CivilProject/BaseImpl.cpp"
#include "../CivilProject/operation_w_double.h"
#include "../CivilProject/operation_w_double.cpp"
#include "../CivilProject/Arc.h"
#include "../CivilProject/Arc.cpp"
#include "../CivilProject/Rect.h"
#include "../CivilProject/Rect.cpp"
#include "../CivilProject/AParallelogram.h"
#include "../CivilProject/AParallelogram.cpp"
#include "../CivilProject/PalalImpl.h"
#include "../CivilProject/PalalImpl.cpp"
#include "../CivilProject/FindBoundigBox.h"
#include "../CivilProject/FindBoundigBox.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
namespace DataForCompare
{
  const double d1 = 0.;
  const double d2 = 0.05;
  const double d3 = 0.06;
  const double d4 = -0.;
  const double d5 = 0.5;
}
namespace TestDataArc
{
  const double Radiuse = 5.0;
  const double AngleF = 0.;
  const double AngleS = 160.;
  const Point2d Center = Point2d(0., 5.);
}
namespace TestDataArcInc
{
  const double Radiuse = -2;
  const double AngleF = 0.;
  const double AngleS = 160.;
  const Point2d Center = Point2d(0., 5.);
}

//todo add test for compare double 
namespace CompareTest
{
  TEST_CLASS(TestCompare)
  {
  public:
    TEST_METHOD(TestBaseFunctional)
    {
      if (CompareDoubleLess(DataForCompare::d2, DataForCompare::d1))
        Assert::Fail();
      if (CompareDoubleLess(DataForCompare::d3, DataForCompare::d2))
        Assert::Fail();
      if (CompareDoubleLess(DataForCompare::d5, DataForCompare::d4))
        Assert::Fail();

      if (CompareDoubleGreater(DataForCompare::d1, DataForCompare::d2))
        Assert::Fail();
      if (CompareDoubleGreater(DataForCompare::d2, DataForCompare::d3))
        Assert::Fail();
      if (CompareDoubleGreater(DataForCompare::d4, DataForCompare::d5))
        Assert::Fail();

      if (CompareDoubleEquall(DataForCompare::d1, DataForCompare::d2))
        Assert::Fail();
      if (CompareDoubleEquall(DataForCompare::d2, DataForCompare::d3))
        Assert::Fail();
      if (CompareDoubleEquall(DataForCompare::d4, DataForCompare::d5))
        Assert::Fail();
    };
  };
}

namespace ImplTest
{
	TEST_CLASS(ImplArcTest)
	{
	public:
		TEST_METHOD(TestBaseFunctional)
		{
      try
      {
        std::shared_ptr<ArcImpl> p = std::make_shared<ArcImpl>();
        p->setAngleFirst(TestDataArc::AngleF);
        p->setAngleSecond(TestDataArc::AngleS);
        p->setRadiuse(TestDataArc::Radiuse);
        Point2d p1(TestDataArc::Center.x(), TestDataArc::Center.y());
        p->setCenter(p1);

        Assert::AreEqual(TestDataArc::AngleF, p->getAngleFirst());
        Assert::AreEqual(TestDataArc::AngleS, p->getAngleSecond());

        Assert::AreEqual(TestDataArc::Radiuse, p->getRadiuse());

        Assert::AreEqual(TestDataArc::Center.x(), p->getCenter().x());
        Assert::AreEqual(TestDataArc::Center.y(), p->getCenter().y());
      }
      catch (std::bad_weak_ptr)
      {
        Assert::Fail();
      }
      catch (...)
      {
        Assert::Fail();
      }
    };

    TEST_METHOD(TestCircumference)
    {
     
      try
      {
        std::shared_ptr<ArcImpl> p = std::make_shared<ArcImpl>();
        p->setAngleFirst(TestDataArc::AngleF);
        p->setAngleSecond(TestDataArc::AngleS);
        p->setRadiuse(TestDataArc::Radiuse);
        Point2d p1(TestDataArc::Center.x(), TestDataArc::Center.y());
        p->setCenter(p1);

        Assert::AreEqual(TestDataArc::AngleF, p->getAngleFirst());
        Assert::AreEqual(TestDataArc::AngleS, p->getAngleSecond());

        Assert::AreEqual(TestDataArc::Radiuse, p->getRadiuse());

        Assert::AreEqual(TestDataArc::Center.x(), p->getCenter().x());
        Assert::AreEqual(TestDataArc::Center.y(), p->getCenter().y());

     
        double a_d = abs(TestDataArc::AngleF - TestDataArc::AngleS);
        double L1 = a_d * ConstValue::Pi / ConstValue::PiDegree * TestDataArc::Radiuse;
        double L2 = a_d / ConstValue::Pi2Degree * 2 * ConstValue::Pi * TestDataArc::Radiuse;
        Assert::AreEqual(p->circumference(), L1);
        Assert::AreEqual(p->circumference(), L2);
      }
      catch (std::bad_weak_ptr)
      {
        Assert::Fail();
      }
      catch(...)
      {
        Assert::Fail();
      }

    };
	};

  TEST_CLASS(ArcTest)
  {
  public:

    TEST_METHOD(TestCatch2)
    {
        try
        {
          std::shared_ptr<Arc> p = std::make_shared<Arc>();
          p->set(TestDataArcInc::Center, TestDataArcInc::Radiuse, TestDataArcInc::AngleF, TestDataArcInc::AngleS);
          double a_d = abs(TestDataArc::AngleF - TestDataArc::AngleS);
          double L1 = a_d * ConstValue::Pi / ConstValue::PiDegree * TestDataArc::Radiuse;
          double L2 = a_d / ConstValue::Pi2Degree * 2 * ConstValue::Pi * TestDataArc::Radiuse;
          if (!CompareDoubleEquall(p->circumference(), L1))
            Assert::Fail();
          if (!CompareDoubleEquall(p->circumference(), L2))
            Assert::Fail();
          Assert::AreEqual(p->circumference(), L1);
          Assert::AreEqual(p->circumference(), L2);
          Assert::Fail();
        }
        catch (std::bad_weak_ptr&)
        {
          
        }
        catch (ErorDataFigure&)
        {
          
        }
    };

  public:

    TEST_METHOD(TestBaseFunctional)
    {
      try
      {
        std::shared_ptr<Arc> p = std::make_shared<Arc>();
        p->set(TestDataArc::Center, TestDataArc::Radiuse, TestDataArc::AngleF, TestDataArc::AngleS);
        double a_d = abs(TestDataArc::AngleF - TestDataArc::AngleS);
        double L1 = a_d * ConstValue::Pi / ConstValue::PiDegree * TestDataArc::Radiuse;
        double L2 = a_d / ConstValue::Pi2Degree * 2 * ConstValue::Pi * TestDataArc::Radiuse;
        if (!CompareDoubleEquall(p->circumference(), L1))
          Assert::Fail();
        if (!CompareDoubleEquall(p->circumference(), L2))
          Assert::Fail();
        Assert::AreEqual(p->circumference(), L1);
        Assert::AreEqual(p->circumference(), L2);
        
      }
      catch (std::bad_weak_ptr&)
      {
        Assert::Fail();
      }
      catch (ErorDataFigure&)
      {
        Assert::Fail();
      }
    };
  };

  //TEST_CLASS(UCopyConstruct)
  //{
  //public:

  //  TEST_METHOD(TestMethod1)
  //  {
  //    Assert::AreEqual(1, 1);
  //  }
  //};

  //TEST_CLASS(USetTest)
  //{
  //public:

  //  TEST_METHOD(TestMethod1)
  //  {
  //    Assert::AreEqual(1, 1);
  //  }
  //};

  //TEST_CLASS(UDrawTest)
  //{
  //public:
  //  TEST_METHOD(TestMethod1)
  //  {
  //    Assert::AreEqual(1, 1);
  //  }
  //};
  //TEST_CLASS(UIsValidTest)
  //{
  //public:

  //  TEST_METHOD(TestMethod1)
  //  {
  //    Assert::AreEqual(1, 1);
  //  }
  //};

}
