//
// Created by akhtyamovpavel on 5/1/20.
//
#include "TreeTestCase.h"
#include "Tree.h"

void dir(const std::string& path) {
    boost::filesystem::create_directory(boost::filesystem::unique_path(path));
}


void touch(const std::string& path) {
    std::ofstream u(path);
    u.close();
}

TEST(A, B) {
	try{
		GetTree("ghjkhdfkjlsvhfhkjdsb", false);
		ASSERT_EQ(1,532);
	} catch (std::invalid_argument) {}

	dir("/tmp/1/");
	touch("/tmp/1/file/");

	try{
		GetTree("/tmp/1/file", false);
		ASSERT_EQ(234, 4334);
	} catch (std::invalid_argument) {}

	dir("/tmp/1/2/");
	touch("/tmp/1/2/file/");
	dir("/tmp/1/2/3/");
	touch("/tmp/1/2/3/file/");
	dir("/tmp/1/2/4");
	touch("/tmp/1/2/4/file/");

	ASSERT_EQ(GetTree("/tmp/1/", false), GetTree("/tmp/1/", false));
	ASSERT_EQ(GetTree("/tmp/1/", true), GetTree("/tmp/1/", true));

	ASSERT_EQ(true, GetTree("/tmp/1/", false) == GetTree("/tmp/1/", false));
	ASSERT_EQ(false, GetTree("/tmp/1/", true) == GetTree("/tmp/1/", false));
	ASSERT_EQ(false, GetTree("/tmp/1/2/", false) == GetTree("/tmp/1/", false));

	dir("/tmp/1/2/4/5/");
	FilterEmptyNodes(GetTree("/tmp/1/2/", false), "./4/5/");
	FilterEmptyNodes(GetTree("/tmp/1/",false), "./2/3/file/");

	boost::filesystem::remove_all("/tmp/1/");
}

