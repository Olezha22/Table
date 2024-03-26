#include "pch.h"
#include "CppUnitTest.h"
#include "../Table/table.h" 

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(TableTests)
	{
	public:

		TEST_METHOD(TestAdd)
		{
			Table<int, string> table;
			table.add(1, "One");
			string val;
			table.find(1, val);
			Assert::AreEqual("One", val.c_str());
		}

		
		TEST_METHOD(TestRemove)
		{
			Table<int, string> table;
			table.add(1, "One");
			table.add(2, "Two");
			table.remove(1);
			string val1;
			string val2;
			Assert::AreEqual(false, table.find(1, val1));
			Assert::AreEqual(true, table.find(2, val2));
		}

		
		TEST_METHOD(TestFind)
		{
			Table<int, string> table;
			table.add(1, "One");
			table.add(2, "Two");
			string value;
			Assert::AreEqual(true, table.find(1, value));
			Assert::AreEqual("One", value.c_str());
			Assert::AreEqual(true, table.find(2, value));
			Assert::AreEqual("Two", value.c_str());
			Assert::AreEqual(false, table.find(3, value));
		}

		TEST_METHOD(TestClear)
		{
			Table<int, string> table;
			table.add(1, "One");
			table.add(2, "Two");
			table.clear();
			string value;
			Assert::AreEqual(false, table.find(1, value));
			Assert::AreEqual(false, table.find(2, value));
		}

		
	};
}
