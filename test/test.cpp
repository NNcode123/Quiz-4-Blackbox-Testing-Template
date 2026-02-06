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

bool Traversal(const vector<int>& data, GatorBST& bst, int type = 0) {
	/*
	 0 is in order traversal
	 1 is for pre-order traversal
	 2 is for post-order traversal
	 */
	vector<Node*> nodes;
	if (type == 0) nodes = bst.TraverseInorder();
	else if (type == 1) nodes = bst.TraversePreorder();
	else if (type == 2)	nodes = bst.TraversePostorder();
	if (data.size() < nodes.size()) {return false;}
	int i = 0;
	for (const auto& elm: data) {
		if (elm != nodes[i]->ufid) {
			return false;
		}
		++i;
	}
	return true;

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
            {3,"o"},
            {5,"p"}
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
			{3,"o"},
			{5,"p"}
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

TEST_CASE("SEARCH_NAME Function") {

	SECTION("Empty Vector Returned for Empty Tree") {
		GatorBST bst;
		vector<int> vec{};
		REQUIRE(bst.SearchName("Fraud") == vec);
	};
	SECTION("Empty Vector Returned for Tree that doesn't contain the Name") {
		vector<pair<int, string>> data = {
			{15, "a"},
			{8,  "b"},
			{24, "c"},
			{6,  "d"},
			{32, "e"}
		};
		GatorBST bst = buildTree(data);
		vector<int> vec{};
		REQUIRE(bst.SearchName("Fraud") == vec);

	};
	SECTION("If name is in Tree, Return a vector with proper order") {
		vector<pair<int, string>> data = {
			{15, "a"},
			{8,  "Remus"},
			{24, "c"},
			{6,  "Remus"},
			{10, "e"},
			{20, "Remus"},
			{32, "g"},
			{4,  "Remus"},
			{7,  "i"},
			{9,  "j"},
			{12, "k"},
			{19, "l"},
			{21, "m"},
			{35, "n"}
		};
		GatorBST bst = buildTree(data);
		vector<int> vec{4,6,8,20};
		REQUIRE(bst.SearchName("Remus") == vec);
	};


}

TEST_CASE("REMOVE FUNCTION") {
	SECTION("REMOVE for Node with 2 and 1 Sucessor Nodes") {
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
		for (const auto& [elm, chara] : data) {
			REQUIRE(bst.Remove(elm) == true);
		}


	};

	SECTION("Remove for Empty Tree Does Nothing") {
		GatorBST bst;
		REQUIRE(bst.Remove(8) == false);

	};
	SECTION("Remove for Node with Only 1 Sucessor Nodes") {
		vector<pair<int, string>> data = {{1,"apple"}, {2,"beta"}};
		GatorBST bst = buildTree(data);
		for (const auto& [elm, chara] : data) {
			REQUIRE(bst.Remove(elm) == true);
		}
	};
	SECTION("Remove Returns false when the target UFID is not in list") {
		vector<pair<int, string>> data = {
			{15, "a"},
			{8,  "Remus"},
			{24, "c"},
			{6,  "Remus"},
			{10, "e"},
			{20, "Remus"},
			{32, "g"},
			{4,  "Remus"},
			{7,  "i"},
			{9,  "j"},
			{12, "k"},
			{19, "l"},
			{21, "m"},
			{35, "n"}
		};
		GatorBST bst = buildTree(data);
		REQUIRE(bst.Remove(36) == false);

	};
}


TEST_CASE("In Order Traversals") {

	SECTION("InOrder traversal for an empty list should return nothing."){
		GatorBST bst;
		REQUIRE(Traversal({},bst) == true);
	};
	SECTION("InOrder traversal works for a complete list") {
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
		REQUIRE(Traversal({4,6,8,10,15,20,24,32},bst) == true);

	};

	SECTION("InOrder traversal works for a Perfect List") {
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
		REQUIRE(Traversal({4,6,7,8,9,10,12,15,19,20,21,24,32,35},bst) == true);

	};

	SECTION("InOrder Traversal works for a Full List") {

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
                 {3,"o"},
                 {5,"p"}

			};
			GatorBST bst = buildTree(data);
		REQUIRE(Traversal({3,4,5,6,7,8,9,10,12,15,19,20,21,24,32,35},bst) == true);






	};

	SECTION("InOrder Traversal works for a Degernate List") {
		vector<pair<int, string>> data = {
			{15, "a"},
			{8,  "b"},
			{24, "c"},
			{6,  "d"},
			{32, "e"}
		};
		GatorBST bst = buildTree(data);
		REQUIRE(Traversal({6,8,15,24,32}, bst) == true);

	};


}

TEST_CASE("Pre Order Traversals") {

	SECTION("PreOrder traversal for an empty list should return nothing."){
		GatorBST bst;
		REQUIRE(Traversal({},bst,1) == true);
	};
	SECTION("PreOrder traversal works for a complete list") {
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
		REQUIRE(Traversal({15,8,6,4,10,24,20,32},bst,1) == true);

	};

	SECTION("PreOrder traversal works for a Perfect List") {
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
		REQUIRE(Traversal( {15,8,6,4,7,10,9,12,24,20,19,21,32,35},bst, 1) == true);

	};

	SECTION("PreOrder Traversal works for a Full List") {

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
			 {3,"o"},
			 {5,"p"}

		};
		GatorBST bst = buildTree(data);
		REQUIRE(Traversal({15,8,6,4,3,5,7,10,9,12,24,20,19,21,32,35},bst,1) == true);






	};

	SECTION("PreOrder Traversal works for a Degenerate List") {
		vector<pair<int, string>> data = {
			{15, "a"},
			{8,  "b"},
			{24, "c"},
			{6,  "d"},
			{32, "e"}
		};
		GatorBST bst = buildTree(data);
		REQUIRE(Traversal({15,8,6,24,32}, bst, 1) == true);

	};
}

TEST_CASE("Post Order Traversals") {

	SECTION("PostOrder traversal for an empty list should return nothing."){
		GatorBST bst;
		REQUIRE(Traversal({},bst,2) == true);
	};
	SECTION("PostOrder traversal works for a complete list") {
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
		REQUIRE(Traversal({4,6,10,8,20,32,24,15},bst,2) == true);

	};

	SECTION("PostOrder traversal works for a Perfect List") {
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
		REQUIRE(Traversal( {4,7,6,9,12,10,8,19,21,20,35,32,24,15},bst, 2) == true);

	};

	SECTION("PostOrder Traversal works for a Full List") {

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
			 {3,"o"},
			 {5,"p"}

		};
		GatorBST bst = buildTree(data);
		REQUIRE(Traversal({3, 5, 4, 7, 6, 9, 12, 10, 8, 19, 21, 20, 35, 32, 24, 15},bst,2) == true);




	};

	SECTION("PostOrder Traversal works for a Degenerate List") {
		vector<pair<int, string>> data = {
			{15, "a"},
			{8,  "b"},
			{24, "c"},
			{6,  "d"},
			{32, "e"}
		};
		GatorBST bst = buildTree(data);
		REQUIRE(Traversal({6,8,32,24,15}, bst, 2) == true);

	};
}



// You are free to write as many tests as you want. Your credit for this
// assignment will be based on the proportion of passing tests as well as the
// number of mutants caught, so it might be a good idea to write many small,
// focused tests over a few large, potentially buggy tests...
