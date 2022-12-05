/**
 * Unit Test suite
**/

#include <gtest/gtest.h>
#include "tappity.h"
 
class tappityTest : public ::testing::Test
{
	protected:
		tappityTest(){} 
		virtual ~tappityTest(){} 
		virtual void SetUp(){}
		virtual void TearDown(){}
};

/* TESTS FOR length_difference() */

TEST(tappityTest, ref_bigger_length)
{
	std::string reference = "reference";
	std::string entry = "entry";

	tappity mytap(reference); //length 9
	mytap.entry(entry); //length 5
	int total = reference.length() - entry.length(); //total difference should be 9-5=4

	int diff = mytap.length_difference();
	ASSERT_EQ(diff, total);

}

TEST(tappityTest, ref_smaller_length)
{
	std::string reference = "small";
	std::string entry = "bigger";

	tappity mytap(reference); //length 5
	mytap.entry(entry); //length 6
	int total = reference.length() - entry.length(); //total difference should be 5-6=-1 or abs(-1)

	int diff = mytap.length_difference();
	ASSERT_EQ(diff, abs(total));
}

TEST(tappityTest, ref_same_length)
{
	std::string reference = "hello";
	std::string entry = "world";

	tappity mytap(reference); //length 5
	mytap.entry(entry); //length 5
	int total = reference.length() - entry.length(); //total difference should be 5-5=0, in other words no difference

	int diff = mytap.length_difference();
	ASSERT_EQ(diff, total);
}

TEST(tappityTest, counting_spaces)
{
	std::string reference = "the cat jumps";
	std::string entry = "thecatjumps";

	tappity mytap(reference); //length 13
	mytap.entry(entry); //length 13 - 2 = 11 (for spaces)
	int total = reference.length() - entry.length(); //total difference should be 13-11 = 2, to account for spaces

	int diff = mytap.length_difference();
	ASSERT_EQ(diff, total);
}

TEST(tappityTest, two_empty_strings)
{
	std::string reference = "";
	std::string entry = "";

	tappity mytap(reference); //length 0
	mytap.entry(entry); //length 0
	int total = reference.length() - entry.length(); //total difference should be 0-0=0

	int diff = mytap.length_difference();
	ASSERT_EQ(diff, total);
}
TEST(tappityTest, one_empty_string)
{
	std::string reference = "non-empty";
	std::string entry = "";

	tappity mytap(reference); //length 9
	mytap.entry(entry); //length 0
	int total = reference.length() - entry.length(); //total difference should be 9-0=9

	int diff = mytap.length_difference();
	ASSERT_EQ(diff, total);
}


/* TESTS FOR accuracy() */

/* calculations for tests:  matches/total length of the longest string */

TEST(tappityTest, 100_accurate_same_num_of_letters)
{
	std::string reference = "cat";
	std::string entry = "cat";

	tappity mytap(reference);
	mytap.entry(entry); 
	double expected = (3.0/3.0)*100; //3/3 = 1 or 1.0 or 100%

	double acc = mytap.accuracy();
	ASSERT_EQ(acc,expected);

}


TEST(tappityTest, spaces_accuracy)
{
	std::string reference = "tu na";
	std::string entry = "tuna";

	tappity mytap(reference);
	mytap.entry(entry); 
	double expected = (2.0/5.0)*100; //first 2 characters out of the biggest string (5 characters) -> 2/5 = .40 or 40%

	double acc = mytap.accuracy();
	ASSERT_EQ(acc,expected);

}

TEST(tappityTest, empty_string_matches)
{
	std::string reference = "";
	std::string entry = "";

	tappity mytap(reference);
	mytap.entry(entry); 
	double expected = (1.0/1.0)*100;

	double acc = mytap.accuracy();
	ASSERT_EQ(acc,expected);

}

TEST(tappityTest, 100_accurate_with_spaces)
{
	std::string reference = "hello my name is";
	std::string entry = "hello my name is";

	tappity mytap(reference);
	mytap.entry(entry); 
	double expected = (16.0/16.0)*100;

	double acc = mytap.accuracy();
	ASSERT_EQ(acc,expected);

}


TEST(tappityTest, long_strings)
{
	std::string reference = "aaaabbbbccccdddd";
	std::string entry = "aaaabbbb";

	tappity mytap(reference);
	mytap.entry(entry); 
	double expected = (8.0/16.0)*100; //8/16 = 50

	double acc = mytap.accuracy();
	ASSERT_EQ(acc,expected);

}

TEST(tappityTest, positional_test)
{
	std::string reference = "axaxaxaxbxbxbxb"; //x's represent a space character in the "entry" string
	std::string entry = "a a a a b b b b";     //1 2 3 4 5 6 7 8 etc..
											   //a x a x a x a x 
	tappity mytap(reference);
	mytap.entry(entry); 
	double expected = (8.0/15.0)*100;

	double acc = mytap.accuracy();
	ASSERT_EQ(acc,expected);

}