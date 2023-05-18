#define CATCH_CONFIG_MAIN
#include <stdexcept>
#include <iostream>
#include <string>
#include <vector>
#include "catch.hpp"
#include "CircularOueue.h"



TEST_CASE("CircularQueue with unsigned") {
	CircularQueue<unsigned> queue(4);

	SECTION("Add 2 elements, check size") {
		queue.push(1);
		queue.push(2);
		REQUIRE(queue.size() == 2);
	}

	SECTION("Add 1 element, pop 1 element, check if queue empty") {
		queue.push(1);
		queue.pop();
		REQUIRE(queue.empty() == 1);
	}

	SECTION("check 1st and last element without adding anything(should throw)") {
		REQUIRE_THROWS(queue.front());
		REQUIRE_THROWS(queue.back());
	}

	SECTION("Add 5 elements, check 5th element is first element") {
		queue.push(1);
		queue.push(2);
		queue.push(3);
		queue.push(4);
		queue.push(5);
		REQUIRE(queue.front() == 2);
	}

	SECTION("Add 1000 elements, pop all of them and check correctness") {
		for (unsigned i = 1; i <= 1000; ++i) {
			queue.push(i);
		}

		int poz = 997;
		for (unsigned i = 1; i <= 4; ++i) {
			REQUIRE(queue.front() == poz);
			poz++;
			queue.pop();
		}
	}

	SECTION("Add 4 elements, pop 2 elements, check size, first and last element") {
		queue.push(1);
		queue.push(2);
		queue.push(3);
		queue.push(4);
		queue.pop();
		queue.pop();
		REQUIRE(queue.size() == 2);
		REQUIRE(queue.front() == 3);
		REQUIRE(queue.back() == 4);
	}

	SECTION("Add 4 elements, check last element") {
		queue.push(1);
		queue.push(2);
		queue.push(3);
		queue.push(4);
		REQUIRE(queue.back() == 4);
	}

}

TEST_CASE("CircularQueue with std::string") {
	CircularQueue<std::string> queue(4);

	SECTION("Add 2 elements, check size") {
		queue.push("message1");
		queue.push("message2");
		REQUIRE(queue.size() == 2);
	}

	SECTION("Add 1 element, pop 1 element, check if queue empty") {
		queue.push("message1");
		queue.pop();
		REQUIRE(queue.empty());
	}

	SECTION("check 1st and last element without adding anything(should throw)") {
		REQUIRE_THROWS(queue.front());
		REQUIRE_THROWS(queue.back());
	}

	SECTION("Add 5 elements, check 5th element is first element") {
		queue.push("message1");
		queue.push("message2");
		queue.push("message3");
		queue.push("message4");
		queue.push("message5");
		REQUIRE(queue.front() == "message2");
	}

	SECTION("Add 1000 elements, pop all of them and check correctness") {
		for (unsigned i = 1; i <= 1000; ++i) {
			std::string element = "Element " + std::to_string(i);
			queue.push(element);
		}
		int poz = 997;
		for (unsigned i = 1; i <= 4; ++i) {
			std::string expectedElement = "Element " + std::to_string(poz);
			poz++;
			REQUIRE(queue.front() == expectedElement);
			queue.pop();
		}
	}

	SECTION("Add 4 elements, pop 2 elements, check size, first and last element") {
		queue.push("message1");
		queue.push("message2");
		queue.push("message3");
		queue.push("message4");
		queue.pop();
		queue.pop();
		REQUIRE(queue.size() == 2);
		REQUIRE(queue.front() == "message3");
		REQUIRE(queue.back() == "message4");
	}

	SECTION("Add 4 elements, check last element") {
		queue.push("message1");
		queue.push("message2");
		queue.push("message3");
		queue.push("message4");
		REQUIRE(queue.back() == "message4");
	}
}