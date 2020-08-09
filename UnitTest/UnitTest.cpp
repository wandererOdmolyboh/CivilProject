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
using namespace Microsoft::VisualStudio::CppUnitTestFramework;


//todo add test for compare double 
namespace UnitTest
{
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
  }//todo test angle
	TEST_CLASS(ImplArcTest)
	{
	public:

 
		TEST_METHOD(TestBaseFunctional)
		{
      try// todo correct processing bad alloc or replace to notrow

        /*
         ArcImpl *p = new(nothrow) ArcImpl();
         if (p == NULL)
        */
      {
        ArcImpl *p = new ArcImpl();

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
        delete p;
      }
      catch (std::bad_alloc&t)
      {
        std::cout << t.what() << std::endl;
      }
     // delete p;
    };

    TEST_METHOD(TestCircumference)
    {
      try
      {
        ArcImpl *p = new ArcImpl();

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
        double L1 = a_d * ConstValue::Pi / 180 * TestDataArc::Radiuse; // todo magic number how to fix?
        double L2 = a_d / 360 * 2 * ConstValue::Pi * TestDataArc::Radiuse;
        Assert::AreEqual(p->circumference(), L1);
        Assert::AreEqual(p->circumference(), L2);

        delete p;
      }
      catch (std::bad_alloc&t)
      {
        std::cout << t.what() << std::endl;
      }
    };


    TEST_METHOD(Test_wIncorectData)
    {//todo add check valid figure
      //try
      //{
      //  ArcImpl *p = new ArcImpl();

      //  p->setAngleFirst(TestDataArcInc::AngleF);
      //  p->setAngleSecond(TestDataArcInc::AngleS);
      //  p->setRadiuse(TestDataArcInc::Radiuse);
      //  Point2d p1(TestDataArcInc::Center.x(), TestDataArc::Center.y());
      //  p->setCenter(p1);

      //  Assert::AreEqual(TestDataArcInc::AngleF, p->getAngleFirst());
      //  Assert::AreEqual(TestDataArcInc::AngleS, p->getAngleSecond());

      //  Assert::AreNotEqual(TestDataArcInc::Radiuse, p->getRadiuse());

      //  Assert::AreEqual(TestDataArcInc::Center.x(), p->getCenter().x());
      //  Assert::AreEqual(TestDataArcInc::Center.y(), p->getCenter().y());
      // 
      //  Assert::AreEqual(p->isValid(), false);

      //  delete p;
      //}
      //catch (std::bad_alloc&t)
      //{
      //  std::cout << t.what() << std::endl;
      //}
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
