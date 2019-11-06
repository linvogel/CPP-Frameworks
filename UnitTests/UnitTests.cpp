#include "pch.h"
#include "CppUnitTest.h"

#include "linvogel_colour_framework.h"
#include "linvogel_logger_framework.h"


lvSetupLoggerModule("UnitTestMain")

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{


	TEST_CLASS(UnitTests)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{

			lvInitColour();
			

		}
	};
}
