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
	SECTION("Small Tree with 1 layer") {
		GatorBST bst;
		bst.Insert(9,"lefty");
		REQUIRE(bst.Height() == 1);
	};
	SECTION("Small Tree with 2 Nodes") {
		GatorBST bst;
		bst.Insert(9,"lefty");
		bst.Insert(2,"righty");
		REQUIRE(bst.Height() == 2);
	};
	SECTION("Small Tree with 3 Nodes") {
		GatorBST bst;
		bst.Insert(5,"lefty");
		bst.Insert(8,"righty");
		REQUIRE(bst.Height() == 2);
	}
	SECTION("Small Tree with 3 NOdes") {
		GatorBST bst;
		bst.Insert(9,"lefty");
		bst.Insert(10, "righty");
		bst.Insert(20, "empty");
		REQUIRE(bst.Height() == 3);
	};
	SECTION("Small Tree with 3 NOdes") {
		GatorBST bst;
		bst.Insert(3,"lefty");
		bst.Insert(5, "righty");
		bst.Insert(2, "lefty");
		REQUIRE(bst.Height() == 2);
	};
	SECTION("Small Tree with 3 NOdes") {
		GatorBST bst;
		bst.Insert(7,"lefty");
		bst.Insert(5, "righty");
		bst.Insert(2, "empty");
		REQUIRE(bst.Height() == 3);
	};
	SECTION("Small Tree with 4 NOdes") {
		GatorBST bst;
		bst.Insert(4,"d");
		bst.Insert(3,"e");
		bst.Insert(2,"f");
		bst.Insert(1,"u");
		REQUIRE(bst.Height() == 4);
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

	SECTION("Irregular Trees") {
		vector<pair<int,string>> data = {
			{5, "a"},
			{200,  "b"},
			{24, "c"},
			{3,  "d"},
			{2, "e"},
			{1, "f"},
			{45, "g"},
			{50,  "h"},
			{70,  "i"},
			{9,  "j"},
			{11, "k"},
			{10, "l"},
			{93, "m"},
			{35, "n"},
			{3,"o"},
		};
		GatorBST bst = buildTree(data);
		REQUIRE(bst.Height() == 7);
	};
}

TEST_CASE("Insertion funtion") {

	SECTION("Duplicate Check for Degenerate Trees") {

		vector<pair<int,string>> data = {
				{15, "a"},
                {8,  "b"},
				{24, "c"},
				{6,  "d"},
				{32, "e"}
		};
		GatorBST bst = buildTree(data);
		for (const auto& [elm, val]: data) {
			REQUIRE(bst.Insert(elm,"YOOOO!") == false);
		}
		REQUIRE(Traversal({6,8,15,24,32},bst));

	};

	SECTION("Duplicate Check for Perfect Trees") {
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
		for (const auto& [elm, val]: data) {
			REQUIRE(bst.Insert(elm,"YOOOO!") == false);
		}
		REQUIRE(Traversal({4,6,7,8,9,10,12,15,19,20,21,24,32,35},bst) == true);

	};

	SECTION("Duplicate Check  for Full Trees") {
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

		};
		GatorBST bst = buildTree(data);
		for (const auto& [elm, val]: data) {
			REQUIRE(bst.Insert(elm,"YOOOO!") == false);
		}
		REQUIRE(Traversal({3,4,6,7,8,9,10,12,15,19,20,21,24,32,35},bst) == true);


	};

	SECTION("Duplicate Check for Complete Trees") {
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
		for (const auto& [elm, val]: data) {
			REQUIRE(bst.Insert(elm,"YOOOO!") == false);
		}
		REQUIRE(Traversal({4,6,8,10,15,20,24,32},bst) == true);
	};



	SECTION("Insertion works for Empty Tree Bst") {
		GatorBST bst;
		REQUIRE(bst.Insert(89, "That guy!") == true);
		REQUIRE(Traversal({89}, bst) == true);
	};

	SECTION("If Insertion is valid, it inserts data into the correct place for degenerate trees") {
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
		REQUIRE(Traversal({4,6,8,10,15,20,24,32,67},bst) == true);

	};

	SECTION("If Insetion is valid, it inserts data into correct place for Perfect Trees") {
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
		REQUIRE(bst.Insert(67, "BrainRot") == true);
		REQUIRE(Traversal({4,6,7,8,9,10,12,15,19,20,21,24,32,35,67},bst) == true);

	};


	SECTION("Insertions actually Produce the Intended List") {
		GatorBST bst;
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

		for (const auto& [elm, chara]: data ) {
			REQUIRE(bst.Insert(elm,"Whoop!") == true);
		}
		REQUIRE(Traversal({4,6,7,8,9,10,12,15,19,20,21,24,32,35},bst) == true);


	};

	SECTION("Insertion Works for Full Trees") {
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

		};
		GatorBST bst = buildTree(data);
		REQUIRE(bst.Insert(67, "BrainRot") == true);
		REQUIRE(Traversal({3,4,6,7,8,9,10,12,15,19,20,21,24,32,35,67},bst) == true);

	};

	SECTION("Insertion Works for Complete Trees") {
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
		REQUIRE(Traversal({4,6,8,10,15,20,24,32,67},bst) == true);

	};




}

TEST_CASE("SEARCH_ID Function") {
	SECTION("Empty Tree") {
		GatorBST bst;
		REQUIRE(bst.SearchID(9) == std::nullopt);
	};

	SECTION("Small Tree") {
		GatorBST bst;
		bst.Insert(90,"Whoop");
		REQUIRE(bst.SearchID(90) == "Whoop");
		REQUIRE(bst.SearchID(89) == std::nullopt);
	};

	SECTION("Small Tree") {
		GatorBST bst;
		bst.Insert(90,"Whoop");
		bst.Insert(91,"dwe");
		bst.Insert(-150,"stup");
		REQUIRE(bst.SearchID(90) == "Whoop");
		REQUIRE(bst.SearchID(91) == "dwe");
		REQUIRE(bst.SearchID(-150) == "stup");
		REQUIRE(bst.SearchID(89) == std::nullopt);
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

	SECTION("Works for Perfect Trees ") {
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

		for (const auto& [elm, name]: data) {
			REQUIRE(bst.SearchID(elm) == name);
		};


	};

}

TEST_CASE("SEARCH_NAME Function") {

	SECTION("Empty Vector Returned for Empty Tree") {
		GatorBST bst;
		vector<int> vec{};
		REQUIRE(bst.SearchName("Fraud") == vec);
	};
	SECTION("Entire List has duplicate names") {
		vector<pair<int, string>> data = {
			{15, "a"},
			{8,  "a"},
			{24, "a"},
			{6,  "a"},
			{32, "a"}
		};
		GatorBST bst = buildTree(data);
		vector<int> vec = {6,8,15,24,32};
		REQUIRE(bst.SearchName("a") == vec);
	}
	SECTION("Case When List has all unique names") {
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
		for (const auto& [elm, val]: data) {
			std::vector<int> vecs = {elm};
			REQUIRE(bst.SearchName(val) == vecs);
		}

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
		REQUIRE(Traversal({}, bst) == true);


	};

	SECTION("Remove Correctly Removes a node with two sucessors") {

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
		REQUIRE(bst.Remove(8) == true);
		REQUIRE(Traversal({4,6,10,15,20,24,32}, bst) == true);

	};

	SECTION("Remove for Empty Tree Does Nothing") {
		GatorBST bst;
		REQUIRE(bst.Remove(8) == false);

	};
	SECTION("Remove for Node with Only 1 Sucessor Nodes") {
		vector<pair<int, string>> data = {{1,"apple"}, {2,"beta"}};
		GatorBST bst = buildTree(data);
		int i = 0;
		for (const auto& [elm, chara] : data) {
			REQUIRE(bst.Remove(elm) == true);
			if (i == 0) {REQUIRE(Traversal({2},bst) == true);}
			++i;
		}
		REQUIRE(Traversal({},bst) == true);
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
		REQUIRE(Traversal({4,6,7,8,9,10,12,15,19,20,21,24,32,35},bst) == true);


	};
}


TEST_CASE("In Order Traversals") {

	SECTION("InOrder traversal for an empty list should return nothing."){
		GatorBST bst;
		REQUIRE(Traversal({},bst) == true);
	};
	SECTION("InOrder traversal for small sized Trees") {
		GatorBST bst;
		bst.Insert(8,"woo");
		bst.Insert(3,"woo");
		REQUIRE(Traversal({3,8},bst) == true);
	};
	SECTION("InOrder traversal for small sized Trees") {
		GatorBST bst;
		bst.Insert(3,"woo");
		bst.Insert(8,"woo");
		REQUIRE(Traversal({3,8},bst) == true);
	};
	SECTION("Inorder traversal for small sized Trees") {
		GatorBST bst;
		bst.Insert(1,"woo");
		REQUIRE(Traversal({1},bst) == true);
	}
	SECTION("Inorder traversal works for small sized Trees of size 3") {
		GatorBST bst;
		bst.Insert(3,"woop");
		bst.Insert(9, "woop");
		bst.Insert(1,"damn");
		REQUIRE(Traversal({1,3,9},bst) == true);
	}
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


			};
			GatorBST bst = buildTree(data);
		REQUIRE(Traversal({3,4,6,7,8,9,10,12,15,19,20,21,24,32,35},bst) == true);






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
	SECTION("PreOrder traversal for small sized Trees") {
		GatorBST bst;
		bst.Insert(8,"woo");
		bst.Insert(3,"woo");
		REQUIRE(Traversal({8,3},bst,1) == true);
	};
	SECTION("PreOrder traversal for small sized Trees") {
		GatorBST bst;
		bst.Insert(3,"woo");
		bst.Insert(8,"woo");
		REQUIRE(Traversal({3,8},bst,1) == true);
	};
	SECTION("Preorder traversal for small sized Trees") {
		GatorBST bst;
		bst.Insert(1,"woo");
		REQUIRE(Traversal({1},bst,1) == true);
	};
	SECTION("Preorder traversal works for small sized Trees of size 3") {
		GatorBST bst;
		bst.Insert(3,"woop");
		bst.Insert(9, "woop");
		bst.Insert(1,"damn");
		REQUIRE(Traversal({3,1,9},bst,1) == true);
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

		};
		GatorBST bst = buildTree(data);
		REQUIRE(Traversal({15,8,6,4,3,7,10,9,12,24,20,19,21,32,35},bst,1) == true);






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

	SECTION("PostOrder traversal for small sized Trees") {
		GatorBST bst;
		bst.Insert(8,"woo");
		bst.Insert(3,"woo");
		REQUIRE(Traversal({3,8},bst,2) == true);
	};
	SECTION("PostOrder traversal for small sized Trees") {
		GatorBST bst;
		bst.Insert(3,"woo");
		bst.Insert(8,"woo");
		REQUIRE(Traversal({8,3},bst,2) == true);
	};
	SECTION("Postorder traversal for small sized Trees") {
		GatorBST bst;
		bst.Insert(1,"woo");
		REQUIRE(Traversal({1},bst,2) == true);
	};
	SECTION("Postorder traversal works for small sized Trees of size 3") {
		GatorBST bst;
		bst.Insert(3,"woop");
		bst.Insert(9, "woop");
		bst.Insert(1,"damn");
		REQUIRE(Traversal({1,9,3},bst,2) == true);
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


		};
		GatorBST bst = buildTree(data);
		REQUIRE(Traversal({3, 4, 7, 6, 9, 12, 10, 8, 19, 21, 20, 35, 32, 24, 15},bst,2) == true);




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
