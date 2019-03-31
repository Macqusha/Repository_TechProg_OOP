#include "CppUnitTest.h"
#include "../OOP/container_atd.h"
#include "../OOP/code_atd.h"
#include "../OOP/cezar_atd.h"
#include "../OOP/numeric_atd.h"
#include "../OOP/zamena_atd.h"
#include <string.h>
#include <fstream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace simple_codes;
using namespace std;

namespace simple_codes {
	const int moreThanMax = maxStringeSize + 20;
	// Сигнатуры используемых внешних функций
	string CodingCezar(char message[maxStringeSize], int rot);
	string CodingZamena(char message[maxStringeSize], int rule);
	string CodingNumeric(char message[maxStringeSize], int digit);	
} // end simple_codes namespace

namespace Coding_test {
	TEST_CLASS(testing_CodingCezar)
	{
	public:

		TEST_METHOD(Test1)
		{
			char message[maxStringeSize];
			int rot = 0;
			char testMes[moreThanMax] = "AbcdeFG 123 %^&";
			for (int i = 0; i < maxStringeSize; i++)
				message[i] = testMes[i];

			string actual = CodingCezar(message, rot);
			string expected = "AbcdeFG 123 %^&";

			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(Test2)
		{
			char message[maxStringeSize];
			int rot = 1;
			char testMes[moreThanMax] = "AbcdeFG 123 %^&";
			for (int i = 0; i < maxStringeSize; i++)
				message[i] = testMes[i];

			string actual = CodingCezar(message, rot);
			string expected = "BcdefGH 123 %^&";

			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(Test3)
		{
			char message[maxStringeSize];
			int rot = 25;
			char testMes[moreThanMax] = "AbcdeFG 123 %^&";
			for (int i = 0; i < maxStringeSize; i++)
				message[i] = testMes[i];

			string actual = CodingCezar(message, rot);
			string expected = "ZabcdEF 123 %^&";

			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(Test4)
		{
			char message[maxStringeSize];
			int rot = 26;
			char testMes[moreThanMax] = "AbcdeFG 123 %^&";
			for (int i = 0; i < maxStringeSize; i++)
				message[i] = testMes[i];

			string actual = CodingCezar(message, rot);
			string expected = "AbcdeFG 123 %^&";

			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(Test5)
		{
			char message[maxStringeSize];
			int rot = 53;
			char testMes[moreThanMax] = "AbcdeFG 123 %^&";
			for (int i = 0; i < maxStringeSize; i++)
				message[i] = testMes[i];

			string actual = CodingCezar(message, rot);
			string expected = "BcdefGH 123 %^&";

			Assert::AreEqual(expected, actual);
		}
	};

	TEST_CLASS(testing_CodingZamena)
	{
	public:

		TEST_METHOD(Test1)
		{
			char message[maxStringeSize];
			int rule = 1;
			char testMes[moreThanMax] = "AbcdeFG..yZ 123 %^&";
			for (int i = 0; i < maxStringeSize; i++)
				message[i] = testMes[i];

			string actual = CodingZamena(message, rule);
			string expected = "ZyxwvUT..bA 123 %^&";

			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(Test2)
		{
			char message[maxStringeSize];
			int rule = 2;
			char testMes[moreThanMax] = "AbcdeFG..yZ 123 %^&";
			for (int i = 0; i < maxStringeSize; i++)
				message[i] = testMes[i];

			string actual = CodingZamena(message, rule);
			string expected = "BadcfEH..zY 123 %^&";

			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(Test3)
		{
			char message[maxStringeSize];
			int rule = 2;
			char testMes[moreThanMax] = "BadcfEH..zY 123 %^&";
			for (int i = 0; i < maxStringeSize; i++)
				message[i] = testMes[i];

			string actual = CodingZamena(message, rule);
			string expected = "AbcdeFG..yZ 123 %^&";

			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(Test4)
		{
			char message[maxStringeSize];
			int rule = 3;
			char testMes[moreThanMax] = "AbcdeFG..yZ 123 %^&";
			for (int i = 0; i < maxStringeSize; i++)
				message[i] = testMes[i];

			string actual = CodingZamena(message, rule);
			string expected = "ShifrZA..wX 123 %^&";

			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(Test5)
		{
			char message[maxStringeSize];
			int rule = 3;
			char testMes[moreThanMax] = "90 %(^& TEST";
			for (int i = 0; i < maxStringeSize; i++)
				message[i] = testMes[i];

			string actual = CodingZamena(message, rule);
			string expected = "90 %(^& PROP";

			Assert::AreEqual(expected, actual);
		}
	};

	TEST_CLASS(testing_CodingNumeric)
	{
	public:

		TEST_METHOD(Test1)
		{
			char message[maxStringeSize];
			int digit = 0;
			char testMes[moreThanMax] = "ABCDEFGHIJKlmnopqrstuvwxyz 12390 !@#$%^&*";
			for (int i = 0; i < maxStringeSize; i++)
				message[i] = testMes[i];

			string actual = CodingNumeric(message, digit);
			string expected = "012345678910111213141516171819202122232425 12390 !@#$%^&*";

			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(Test2)
		{
			char message[maxStringeSize];
			int digit = 1;
			char testMes[moreThanMax] = "ABCDEFGHIJKlmnopqrstuvwxyz 12390 !@#$%^&*";
			for (int i = 0; i < maxStringeSize; i++)
				message[i] = testMes[i];

			string actual = CodingNumeric(message, digit);
			string expected = "123456789101112131415161718192021222324250 12390 !@#$%^&*";

			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(Test3)
		{
			char message[maxStringeSize];
			int digit = 25;
			char testMes[moreThanMax] = "ABCDEFGHIJKlmnopqrstuvwxyz 12390 !@#$%^&*";
			for (int i = 0; i < maxStringeSize; i++)
				message[i] = testMes[i];

			string actual = CodingNumeric(message, digit);
			string expected = "250123456789101112131415161718192021222324 12390 !@#$%^&*";

			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(Test4)
		{
			char message[maxStringeSize];
			int digit = 26;
			char testMes[moreThanMax] = "ABCDEFGHIJKlmnopqrstuvwxyz 12390 !@#$%^&*";
			for (int i = 0; i < maxStringeSize; i++)
				message[i] = testMes[i];

			string actual = CodingNumeric(message, digit);
			string expected = "012345678910111213141516171819202122232425 12390 !@#$%^&*";

			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(Test5)
		{
			char message[maxStringeSize];
			int digit = 53;
			char testMes[moreThanMax] = "ABCDEFGHIJKlmnopqrstuvwxyz 12390 !@#$%^&*";
			for (int i = 0; i < maxStringeSize; i++)
				message[i] = testMes[i];

			string actual = CodingNumeric(message, digit);
			string expected = "123456789101112131415161718192021222324250 12390 !@#$%^&*";

			Assert::AreEqual(expected, actual);
		}
	};
} // end Coding_test namespace

TEST_CLASS(testing_In_lower)
{
public:

	TEST_METHOD(Test1_cezar_owner)
	{
		cezar* testing_type = new cezar;
		ifstream test_file("../OOP/Test_Files/In_low_cezar.txt");
		testing_type->InData(test_file);
		string actual = testing_type->owner;
		string expected = "Aleev";
		Assert::AreEqual(expected, actual);
	}

	TEST_METHOD(Test2_cezar_message)
	{
		cezar* testing_type = new cezar;
		ifstream test_file("../OOP/Test_Files/In_low_cezar.txt");
		testing_type->InData(test_file);
		string actual = testing_type->message;
		string expected = "test";
		Assert::AreEqual(expected, actual);
	}

	TEST_METHOD(Test3_cezar_rot)
	{
		cezar* testing_type = new cezar;
		ifstream test_file("../OOP/Test_Files/In_low_cezar.txt");
		testing_type->InData(test_file);
		int actual = testing_type->rot;
		int expected = 53;
		Assert::AreEqual(expected, actual);
	}

	TEST_METHOD(Test1_zamena_owner)
	{
		zamena* testing_type = new zamena;
		ifstream test_file("../OOP/Test_Files/In_low_zamena.txt");
		testing_type->InData(test_file);
		string actual = testing_type->owner;
		string expected = "Aleev";
		Assert::AreEqual(expected, actual);
	}

	TEST_METHOD(Test2_zamena_message)
	{
		zamena* testing_type = new zamena;
		ifstream test_file("../OOP/Test_Files/In_low_zamena.txt");
		testing_type->InData(test_file);
		string actual = testing_type->message;
		string expected = "test";
		Assert::AreEqual(expected, actual);
	}

	TEST_METHOD(Test3_zamena_rule)
	{
		zamena* testing_type = new zamena;
		ifstream test_file("../OOP/Test_Files/In_low_zamena.txt");
		testing_type->InData(test_file);
		int actual = testing_type->rule;
		int expected = 3;
		Assert::AreEqual(expected, actual);
	}

	TEST_METHOD(Test1_numeric_owner)
	{
		numeric* testing_type = new numeric;
		ifstream test_file("../OOP/Test_Files/In_low_numeric.txt");
		testing_type->InData(test_file);
		string actual = testing_type->owner;
		string expected = "Aleev";
		Assert::AreEqual(expected, actual);
	}

	TEST_METHOD(Test2_numeric_message)
	{
		numeric* testing_type = new numeric;
		ifstream test_file("../OOP/Test_Files/In_low_numeric.txt");
		testing_type->InData(test_file);
		string actual = testing_type->message;
		string expected = "test";
		Assert::AreEqual(expected, actual);
	}

	TEST_METHOD(Test3_numeric_digit)
	{
		numeric* testing_type = new numeric;
		ifstream test_file("../OOP/Test_Files/In_low_numeric.txt");
		testing_type->InData(test_file);
		int actual = testing_type->digit;
		int expected = 10;
		Assert::AreEqual(expected, actual);
	}
};

TEST_CLASS(testing_In_higher)
{
public:

	TEST_METHOD(Test_cont_IN_OUT)
	{
		ifstream test_file_in("../OOP/Test_files/In_higher_1_in.txt");
		simple_codes::container* begin = new simple_codes::container;
		begin->In(test_file_in);
		ofstream test_file_out("../OOP/Test_Files/In_higher_2_res.txt");
		begin->Out(test_file_out);

		int expected = true;
		int actual = true;

		int i = 0;
		char ch_1[20], ch_2[20];
		FILE *file_1 = fopen("../OOP/Test_Files/In_higher_2_res.txt", "r");;
		FILE *file_2 = fopen("../OOP/Test_Files/In_higher_3_etalon.txt", "r");
		while (!feof(file_1) && !feof(file_2))
		{
			fgets(ch_1, 20, file_1);
			fgets(ch_2, 20, file_2);
			i++;
			if (strcmp(ch_1, ch_2))
				actual = false;
		}
		Assert::AreEqual(expected, actual);
	}
};

TEST_CLASS(testing_Out_lower)
{
public:

	TEST_METHOD(Test1_cezar)
	{
		cezar testing_type;
		testing_type.rot = 3;
		char tmp_mes[maxStringeSize] = "TestMes";
		strcpy(testing_type.message, tmp_mes);
		char tmp_own[maxStringeSize] = "TestOwn";
		strcpy(testing_type.owner, tmp_own);
		ofstream test_file_out("../OOP/Test_Files/Out_lower_cezar.txt");
		testing_type.Out(test_file_out);
		test_file_out.close();

		ifstream test_file_in("../OOP/Test_Files/Out_lower_cezar.txt");
		string actual;
		getline(test_file_in, actual);
		test_file_in.close();
		string expected = "It is Cezar: rot = 3, open = TestMes, code = WhvwPhv, owner = TestOwn. ";

		Assert::AreEqual(expected, actual);
	}
	
	TEST_METHOD(Test2_zamena)
	{
		zamena testing_type;
		testing_type.rule = 3;
		char tmp_mes[maxStringeSize] = "TestMes";
		strcpy(testing_type.message, tmp_mes);
		char tmp_own[maxStringeSize] = "TestOwn";
		strcpy(testing_type.owner, tmp_own);
		ofstream test_file_out("../OOP/Test_Files/Out_lower_zamena.txt");
		testing_type.Out(test_file_out);
		test_file_out.close();

		ifstream test_file_in("../OOP/Test_Files/Out_lower_zamena.txt");
		string actual;
		getline(test_file_in, actual);
		test_file_in.close();
		string expected = "It is Zamena: rule = Keyword-change, open = TestMes, code = PropCro, owner = TestOwn. ";

		Assert::AreEqual(expected, actual);
	}

	TEST_METHOD(Test3_numeric)
	{
		numeric testing_type;
		testing_type.digit = 3;
		char tmp_mes[maxStringeSize] = "TestMes";
		strcpy(testing_type.message, tmp_mes);
		char tmp_own[maxStringeSize] = "TestOwn";
		strcpy(testing_type.owner, tmp_own);
		ofstream test_file_out("../OOP/Test_Files/Out_lower_numeric.txt");
		testing_type.Out(test_file_out);
		test_file_out.close();

		ifstream test_file_in("../OOP/Test_Files/Out_lower_numeric.txt");
		string actual;
		getline(test_file_in, actual);
		test_file_in.close();
		string expected = "It is Numeric: digit = 3, open = TestMes, code = 227212215721, owner = TestOwn. ";

		Assert::AreEqual(expected, actual);
	}
};

TEST_CLASS(testing_Out_higher)
{
public:

	TEST_METHOD(Test_cont_IN_OUT)
	{
		ifstream test_file_in("../OOP/Test_files/Out_higher_1_in.txt");
		simple_codes::container* begin = new simple_codes::container;
		begin->In(test_file_in);
		ofstream test_file_out("../OOP/Test_Files/Out_higher_2_res.txt");
		begin->Out(test_file_out);

		int expected = true;
		int actual = true;

		int i = 0;
		char ch_1[20], ch_2[20];
		FILE *file_1 = fopen("../OOP/Test_Files/Out_higher_2_res.txt", "r");;
		FILE *file_2 = fopen("../OOP/Test_Files/Out_higher_3_etalon.txt", "r");
		while (!feof(file_1) && !feof(file_2))
		{
			fgets(ch_1, 20, file_1);
			fgets(ch_2, 20, file_2);
			i++;
			if (strcmp(ch_1, ch_2))
				actual = false;
		}
		Assert::AreEqual(expected, actual);
	}
};

TEST_CLASS(testing_Sort)
{
public:

	TEST_METHOD(Test_sort_IN_OUT)
	{
		
		ifstream test_file_in("../OOP/Test_files/Sort_1_in.txt");
		simple_codes::container* begin = new simple_codes::container;
		begin->In(test_file_in);
		begin->Sort();
		ofstream test_file_out("../OOP/Test_Files/Sort_2_res.txt");
		begin->Out(test_file_out); 

		int expected = true;
		int actual = true;

		int i = 0;
		char ch_1[20], ch_2[20];
		FILE *file_1 = fopen("../OOP/Test_Files/Sort_2_res.txt", "r");;
		FILE *file_2 = fopen("../OOP/Test_Files/Sort_3_etalon.txt", "r");
		while (!feof(file_1) && !feof(file_2))
		{
			fgets(ch_1, 20, file_1);
			fgets(ch_2, 20, file_2);
			i++;
			if (strcmp(ch_1, ch_2))
				actual = false;
		}
		Assert::AreEqual(expected, actual);
	}
};

TEST_CLASS(testing_Filter)
{
public:

	TEST_METHOD(Test_filter_IN_OUT)
	{
		ifstream test_file_in("../OOP/Test_files/Filter_1_in.txt");
		simple_codes::container* begin = new simple_codes::container;
		begin->In(test_file_in);
		ofstream test_file_out("../OOP/Test_Files/Filter_2_res.txt");
		begin->OutZamena(test_file_out);

		int expected = true;
		int actual = true;

		int i = 0;
		char ch_1[20], ch_2[20];
		FILE *file_1 = fopen("../OOP/Test_Files/Filter_2_res.txt", "r");;
		FILE *file_2 = fopen("../OOP/Test_Files/Filter_3_etalon.txt", "r");
		while (!feof(file_1) && !feof(file_2))
		{
			fgets(ch_1, 20, file_1);
			fgets(ch_2, 20, file_2);
			i++;
			if (strcmp(ch_1, ch_2))
				actual = false;
		}
		Assert::AreEqual(expected, actual);
	}
};

TEST_CLASS(testing_MesLength)
{
public:

	TEST_METHOD(Test1_cezar)
	{
		cezar s;
		char testMes[moreThanMax] = "";
		for (int i = 0; i < moreThanMax; i++)
			s.message[i] = testMes[i];
		int actual = s.MesLength();

		Assert::AreEqual(0, actual);
	}
	
	TEST_METHOD(Test2_cezar)
	{
		cezar s;
		char testMes[moreThanMax] = "ABC abc 1234567!@#&*";
		for (int i = 0; i < moreThanMax; i++)
			s.message[i] = testMes[i];
		int actual = s.MesLength();

		Assert::AreEqual(20, actual);
	}

	TEST_METHOD(Test3_cezar)
	{
		cezar s;
		char testMes[moreThanMax] = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
		for (int i = 0; i < moreThanMax; i++)
			s.message[i] = testMes[i];
		int actual = s.MesLength();

		Assert::AreEqual(79, actual);
	}

	TEST_METHOD(Test4_cezar)
	{
		cezar s;
		char testMes[moreThanMax] = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
		for (int i = 0; i < moreThanMax; i++)
			s.message[i] = testMes[i];
		int actual = s.MesLength();

		Assert::AreEqual(80, actual);
	}

	TEST_METHOD(Test5_cezar)
	{
		cezar s;
		char testMes[moreThanMax] = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
		for (int i = 0; i < moreThanMax; i++)
			s.message[i] = testMes[i];
		int actual = s.MesLength();

		Assert::AreEqual(80, actual);
	}

	TEST_METHOD(Test1_zamena)
	{
		zamena s;
		char testMes[moreThanMax] = "";
		for (int i = 0; i < moreThanMax; i++)
			s.message[i] = testMes[i];
		int actual = s.MesLength();

		Assert::AreEqual(0, actual);
	}

	TEST_METHOD(Test2_zamena)
	{
		zamena s;
		char testMes[moreThanMax] = "ABC abc 1234567!@#&*";
		for (int i = 0; i < moreThanMax; i++)
			s.message[i] = testMes[i];
		int actual = s.MesLength();

		Assert::AreEqual(20, actual);
	}

	TEST_METHOD(Test3_zamena)
	{
		zamena s;
		char testMes[moreThanMax] = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
		for (int i = 0; i < moreThanMax; i++)
			s.message[i] = testMes[i];
		int actual = s.MesLength();

		Assert::AreEqual(79, actual);
	}

	TEST_METHOD(Test4_zamena)
	{
		zamena s;
		char testMes[moreThanMax] = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
		for (int i = 0; i < moreThanMax; i++)
			s.message[i] = testMes[i];
		int actual = s.MesLength();

		Assert::AreEqual(80, actual);
	}

	TEST_METHOD(Test5_zamena)
	{
		zamena s;
		char testMes[moreThanMax] = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
		for (int i = 0; i < moreThanMax; i++)
			s.message[i] = testMes[i];
		int actual = s.MesLength();

		Assert::AreEqual(80, actual);
	}

	TEST_METHOD(Test1_numeric)
	{
		numeric s;
		char testMes[moreThanMax] = "";
		for (int i = 0; i < moreThanMax; i++)
			s.message[i] = testMes[i];
		int actual = s.MesLength();

		Assert::AreEqual(0, actual);
	}

	TEST_METHOD(Test2_numeric)
	{
		numeric s;
		char testMes[moreThanMax] = "ABC abc 1234567!@#&*";
		for (int i = 0; i < moreThanMax; i++)
			s.message[i] = testMes[i];
		int actual = s.MesLength();

		Assert::AreEqual(20, actual);
	}

	TEST_METHOD(Test3_numeric)
	{
		numeric s;
		char testMes[moreThanMax] = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
		for (int i = 0; i < moreThanMax; i++)
			s.message[i] = testMes[i];
		int actual = s.MesLength();

		Assert::AreEqual(79, actual);
	}

	TEST_METHOD(Test4_numeric)
	{
		numeric s;
		char testMes[moreThanMax] = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
		for (int i = 0; i < moreThanMax; i++)
			s.message[i] = testMes[i];
		int actual = s.MesLength();

		Assert::AreEqual(80, actual);
	}

	TEST_METHOD(Test5_numeric)
	{
		numeric s;
		char testMes[moreThanMax] = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
		for (int i = 0; i < moreThanMax; i++)
			s.message[i] = testMes[i];
		int actual = s.MesLength();

		Assert::AreEqual(80, actual);
	}
};
