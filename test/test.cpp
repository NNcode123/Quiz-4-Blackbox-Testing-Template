// Note - the autograder expects this exact include for your catch code! If you use the manual catch compilation method, be sure you put this include back before submitting.
#include <catch2/catch_test_macros.hpp>
#include <vector>
#include "GatorBST.h"

using namespace std;

GatorBST buildTree(vector<pair<int, string>> Students) {
	GatorBST tree;
	for (const auto& [iD, name]: Students) {
		tree.Insert(iD,name);
	}
	return tree;
}




TEST_CASE("Height function") {
	SECTION("Empty Tree") {
		GatorBST bst;
		REQUIRE(bst.Height() == 0);
	};
	SECTION("Perfect Trees") {
		vector<pair<int, string>> data = {
			{15, "a"},
			{8,  "b"},
			{24, "c"},
			{6,  "d"},
			{10, "e"},
			{20, "f"},
			{32, "g"},
			{4,  "h"},
			{7,  "i"},
			{9,  "j"},
			{12, "k"},
			{19, "l"},
			{21, "m"},
			{35, "n"}
		};
		GatorBST bst = buildTree(data);
		REQUIRE(bst.Height() == 4);
	};


	SECTION("Full Trees") {
		vector<pair<int, string>> data = {
			{15, "a"},
			{8,  "b"},
			{24, "c"},
			{6,  "d"},
			{10, "e"},
			{20, "f"},
			{32, "g"},
			{4,  "h"},
			{7,  "i"},
			{9,  "j"},
			{12, "k"},
			{19, "l"},
			{21, "m"},
			{35, "n"},
            {36,"o"},
            {33,"p"}
		};
		GatorBST bst = buildTree(data);
		REQUIRE(bst.Height() == 5);


	};

	SECTION("Complete Trees") {
		vector<pair<int, string>> data = {
			{15, "a"},
			{8,  "b"},
			{24, "c"},
			{6,  "d"},
			{10, "e"},
			{20, "f"},
			{32, "g"},
			{4,  "h"}
		};
		GatorBST bst = buildTree(data);
		REQUIRE(bst.Height() == 4);

	};

	SECTION("General Trees") {
		vector<pair<int, string>> data = {
			{15, "a"},
			{8,  "b"},
			{24, "c"},
			{6,  "d"},
			{32, "e"}
		};
		GatorBST bst = buildTree(data);
		REQUIRE(bst.Height() == 3);

	};
}

TEST_CASE("Insertion funtion") {

	SECTION("Duplicate Check") {

		vector<pair<int,string>> data = {
				{15, "a"},
                {8,  "b"},
				{24, "c"},
				{6,  "d"},
				{32, "e"}
		};
		GatorBST bst = buildTree(data);
		REQUIRE(bst.Insert(8,"YOOOO!") == false);
	};
	SECTION("Insertion works for Empty Tree Bst") {
		GatorBST bst;
		REQUIRE(bst.Insert(89, "That guy!") == true);
	};

	SECTION("If Insertion is valid, it inserts data into the correct place") {
		vector<pair<int, string>> data = {
			{15, "a"},
			{8,  "b"},
			{24, "c"},
			{6,  "d"},
			{10, "e"},
			{20, "f"},
			{32, "g"},
			{4,  "h"}
		};
		GatorBST bst = buildTree(data);
		REQUIRE(bst.Insert(67, "BrainRot") == true);

	};



}

TEST_CASE("SEARCH_ID Function") {
	SECTION("Empty Tree") {
		GatorBST bst;
		REQUIRE(bst.SearchID(9) == std::nullopt);
	};

	SECTION("Correctly finds the associated name with an ID") {
		vector<pair<int, string>> data = {
			{15, "a"},
			{8,  "b"},
			{24, "c"},
			{6,  "d"},
			{10, "e"},
			{20, "f"},
			{32, "g"},
			{4,  "h"},
			{7,  "i"},
			{9,  "j"},
			{12, "k"},
			{19, "l"},
			{21, "m"},
			{35, "n"},
			{36,"o"},
			{33,"p"}
		};
		GatorBST bst = buildTree(data);
		for (const auto& [id, name]: data) {
			REQUIRE(bst.SearchID(id) == name);
		}

	};

	SECTION("Returns Null if assoicated ID is in list.") {
		vector<pair<int, string>> data = {
			{15, "a"},
			{8,  "b"},
			{24, "c"},
			{6,  "d"},
			{10, "e"},
			{20, "f"},
			{32, "g"},
			{4,  "h"}
		};
		GatorBST bst = buildTree(data);
		vector<int> faulty_vals = {67,6700,67000, 123, 5, 9, 95, 59};

		for (const auto& elm: faulty_vals) {
			REQUIRE(bst.SearchID(elm) == std::nullopt);
		};


	};

}


// You are free to write as many tests as you want. Your credit for this
// assignment will be based on the proportion of passing tests as well as the
// number of mutants caught, so it might be a good idea to write many small,
// focused tests over a few large, potentially buggy tests...
