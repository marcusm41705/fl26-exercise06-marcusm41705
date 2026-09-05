////////////////////////////////////////////////////////
// ECE 3574 Exercise: Unit Tests with Catch - starter code
//
#define CATCH_CONFIG_MAIN  // This line tells Catch to provide a main() function
                           // - do this in one cpp file only
#include "catch.hpp"       // This line provides access to all Catch macros
                           // - do not modify catch.hpp
#include <cassert>    
#include <cstdlib>
#include <map>
#include <string>

TEST_CASE("multimap unit test1", "[multimap]") {
	std::multimap<std::string, std::string> m;
	REQUIRE(m.empty());	
	REQUIRE(m.size() == 0);
	
	m.insert(std::pair<std::string, std::string>("Ross", "Betsy"));
	REQUIRE_FALSE(m.empty());
	REQUIRE(m.size() == 1);
	m.insert(std::pair<std::string, std::string>("Mason","Marcus"));
	m.insert(std::pair<std::string, std::string>("Doe","John"));
	REQUIRE(m.size() == 3);
	REQUIRE(m.count("Mason") == 2);
	REQUIRE(m.count("Doe") ==1);
}
TEST_CASE("Assignment Testing ", "[multimap]"){
	std::multimap<int, std::string> m1;
	m1.insert(std::pair<int, std::string>(3,"three"));
	m1.insert(std::pair<int, std::string>(2,"two"));
	m1.insert(std::pair<int, std::string>(2,"additional two"));
	std::multimap<int, std::string> m2;
	m2 = m1;
	REQUIRE(m2.size() == m1.size());
	REQUIRE(m2.count(1) == 1);
	REQUIRE(m1.count(2) == 2);
	m2.insert(std::pair<int, std::string>(1, "one"));
	REQUIRE(m1.size() == 3);
	REQUIRE(m2.size() ==4);
	
}
TEST_CASE("Empty/Clear/Size Testing", "[multimap]"){
	std::multimap<char, int> m;
		REQUIRE(m.empty());
		REQUIRE(m.size() == 0);
		m.insert(std::pair<int, int>(1,2));
		m.insert(std::pair<int,int>(3,4));
		REQUIRE_FALSE(m.empty());
		REQUIRE(m.size() == 2);
		m.clear();
		REQUIRE(m.empty());
		REQUIRE(m.size() ==0);

}
TEST_CASE("Insert/count testing", "[multimap]"){
	std::multimap<char, int>m;
	m.insert(std::pair<char, int>('A',1));
		m.insert(std::pair<char, int>('A',2));
	m.insert(std::pair<char, int>('B',3));
	m.insert(std::pair<char, int>('A',4));
	REQUIRE(m.size() == 4);
	REQUIRE(m.count('A') == 3);
		REQUIRE(m.count('B') ==1);
	REQUIRE(m.count('C') == 3);


}
TEST_CASE("Erase testing", "[multimap]"){
	std::multimap<std::string, int>m;
	m.insert(std::pair<std::string, int>("car", 1));
	m.insert(std::pair<std::string, int>("car", 2));
	m.insert(std::pair<std::string, int>("Dodge", 3));
	m.insert(std::pair<std::string, int>("BMW", 4));
	REQUIRE(m.size() == 4);
	REQUIRE(m.count("car") == 2);
	m.erase("car");
	REQUIRE(m.size() == 2);
	REQUIRE(m.count("Dodge") == 1);
	REQUIRE(m.count("car") ==0);
	REQUIRE(m.count( "BMW") == 1);
	m.erase("Ford");
	REQUIRE(m.size() == 2);
}
TEST_CASE("Find testing", "[multimap]"){
	std::multimap<int, std::string>m;
	m.insert(std::pair<int,std::string>(1, "ece"));
	m.insert(std::pair<int,std::string>(2, "science"));
	m.insert(std::pair<int,std::string>(3, "english"));
	std::multimap<int, std::string>::iterator it = m.find(2);
	REQUIRE(it != m.end());
	REQUIRE(it->first == 2);
	REQUIRE(it->second == "science");
it = m.find(25);
REQUIRE(it == m.end());
}

