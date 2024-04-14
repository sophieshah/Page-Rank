//#include <catch2/catch_test_macros.hpp>
//#include <iostream>
//
//// change if you choose to use a different header name
//#include "C:\DSAProject2Catch\Page-Rank-Project\src\main.cpp"
//
//using namespace std;
//
////catch template from project 2 catch github
//
//TEST_CASE("Four Power Iterations", "[flag]"){
//    string input = R"(7 4
//google.com gmail.com
//google.com maps.com
//facebook.com ufl.edu
//ufl.edu google.com
//ufl.edu gmail.com
//maps.com facebook.com
//gmail.com maps.com)";
//
//    string expectedOutput = R"(facebook 0.20
//gmail 0.20
//google 0.10
//maps 0.30
//ufl 0.20
//)";
//
//    string actualOutput;
//
//    adjacencyList a;
//    a.addToVect("google", "gmail");
//    a.addToVect("google", "maps");
//    a.addToVect("facebook", "ufl");
//    a.addToVect("ufl", "google");
//    a.addToVect("ufl", "gmail");
//    a.addToVect("ufl", "gmail");
//    a.addToVect("gmail", "maps");
//
//    a.findRT();
//    a.firstRValues();
//    a.pageRank(4);
//    actualOutput = a.returnValues();
//
//    REQUIRE(actualOutput == expectedOutput);
//}
//
//TEST_CASE("One line", "[flag]"){
//string input = R"(1 2
//google facebook)";
//
//string expectedOutput = R"(facebook 0.50
//google 0.00
//)";
//
//string actualOutput;
//
//adjacencyList a;
//a.addToVect("google", "facebook");
//
//a.findRT();
//a.firstRValues();
//a.pageRank(2);
//actualOutput = a.returnValues();
//
//REQUIRE(actualOutput == expectedOutput);
//}
//
//TEST_CASE("Ten Lines, One Power Iteration", "[flag]"){
//    string input = R"(10 1
//google gmail
//gmail ufl
//ufl maps
//maps facebook
//facebook google
//google ufl
//ufl google
//google facebook
//gmail facebook
//ufl facebook
//)";
//
//    string expectedOutput = R"(facebook 0.20
//gmail 0.20
//google 0.20
//maps 0.20
//ufl 0.20
//)";
//
//    string actualOutput;
//
//    adjacencyList a;
//    a.addToVect("google", "gmail");
//    a.addToVect("gmail", "ufl");
//    a.addToVect("ufl", "maps");
//    a.addToVect("maps", "facebook");
//    a.addToVect("facebook", "google");
//    a.addToVect("google", "ufl");
//    a.addToVect("ufl", "google");
//    a.addToVect("google", "facebook");
//    a.addToVect("gmail", "facebook");
//    a.addToVect("ufl", "facebook");
//
//    a.findRT();
//    a.firstRValues();
//    a.pageRank(1);
//    actualOutput = a.returnValues();
//
//    REQUIRE(actualOutput == expectedOutput);
//}
//
//TEST_CASE("Ten Lines, One Power Iteration", "[flag]"){
//    string input = R"(10 1
//google gmail
//gmail ufl
//ufl maps
//maps facebook
//facebook google
//google ufl
//ufl google
//google facebook
//gmail facebook
//ufl facebook
//)";
//
//    string expectedOutput = R"(facebook 0.20
//gmail 0.20
//google 0.20
//maps 0.20
//ufl 0.20
//)";
//
//    string actualOutput;
//
//    adjacencyList a;
//    a.addToVect("google", "gmail");
//    a.addToVect("gmail", "ufl");
//    a.addToVect("ufl", "maps");
//    a.addToVect("maps", "facebook");
//    a.addToVect("facebook", "google");
//    a.addToVect("google", "ufl");
//    a.addToVect("ufl", "google");
//    a.addToVect("google", "facebook");
//    a.addToVect("gmail", "facebook");
//    a.addToVect("ufl", "facebook");
//
//    a.findRT();
//    a.firstRValues();
//    a.pageRank(1);
//    actualOutput = a.returnValues();
//
//    REQUIRE(actualOutput == expectedOutput);
//}
//
//TEST_CASE("Nodes pointing to each other", "[flag]"){
//    string input = R"(4 2
//google gmail
//gmail google
//facebook ufl
//ufl facebook
//)";
//
//    string expectedOutput = R"(facebook 0.25
//gmail 0.25
//google 0.25
//ufl 0.25
//)";
//
//    string actualOutput;
//
//    adjacencyList a;
//    a.addToVect("google", "gmail");
//    a.addToVect("gmail", "google");
//    a.addToVect("facebook", "ufl");
//    a.addToVect("ufl", "facebook");
//
//    a.findRT();
//    a.firstRValues();
//    a.pageRank(2);
//    actualOutput = a.returnValues();
//
//    REQUIRE(actualOutput == expectedOutput);
//}
//
//TEST_CASE("High power iteration", "[flag]"){
//    string input = R"(7 10
//google gmail
//gmail facebook
//maps ufl
//ufl gmail
//google maps
//ufl maps
//maps facebook
//)";
//
//    string expectedOutput = R"(facebook 0.00
//gmail 0.00
//google 0.00
//maps 0.00
//ufl 0.00
//)";
//
//    string actualOutput;
//
//    adjacencyList a;
//    a.addToVect("google", "gmail");
//    a.addToVect("gmail", "facebook");
//    a.addToVect("maps", "ufl");
//    a.addToVect("ufl", "gmail");
//    a.addToVect("google", "maps");
//    a.addToVect("ufl", "maps");
//    a.addToVect("maps", "facebook");
//
//    a.findRT();
//    a.firstRValues();
//    a.pageRank(50);
//    actualOutput = a.returnValues();
//
//    REQUIRE(actualOutput == expectedOutput);
//}
//
