#include <catch2/catch.hpp>
#include <game_engine.h>

/**
 * This file contains tests for the leader board.
 * It tests for score keeping, adding new players, getting winners and operation overloading
 * for reading and writing from file.
 */
//######################################################

// Testing Methodology:

// 1. Testing the Leader Board and >> overloading (13 tests).
// 2. Testing << overloading and error handling (7 tests).

//######################################################

namespace game {

    TEST_CASE("1. Testing the Leader Board and >> overloading") {

        SECTION("1.1 Testing the size of the player map") {
            LeaderBoard lb = LeaderBoard();
            std::ifstream input_file("/Users/ved/Documents/Classes/Spring-2021/CS-126/cinder_0.9.2_mac/my-projects/final-project-dev-ved30/data/test/lb1.txt");
            if (input_file.is_open()) {
                input_file >> lb;
                input_file.close();
            }
            REQUIRE(lb.GetPlayerMap().size() == 2);
        }
        SECTION("1.2 Testing the names in the player map") {
            LeaderBoard lb = LeaderBoard();
            std::ifstream input_file("/Users/ved/Documents/Classes/Spring-2021/CS-126/cinder_0.9.2_mac/my-projects/final-project-dev-ved30/data/test/lb1.txt");
            if (input_file.is_open()) {
                input_file >> lb;
                input_file.close();
            }
            REQUIRE(lb.GetPlayerMap().find("ved") != lb.GetPlayerMap().end());
            REQUIRE(lb.GetPlayerMap().find("dev") != lb.GetPlayerMap().end());
        }
        SECTION("1.3 Testing the scores in the player map") {
            LeaderBoard lb = LeaderBoard();
            std::ifstream input_file("/Users/ved/Documents/Classes/Spring-2021/CS-126/cinder_0.9.2_mac/my-projects/final-project-dev-ved30/data/test/lb1.txt");
            if (input_file.is_open()) {
                input_file >> lb;
                input_file.close();
            }
            std::unordered_map<std::string, size_t> map = lb.GetPlayerMap();
            REQUIRE(map["ved"] == 2040);
            REQUIRE(map["dev"] == 420);
        }
        SECTION("1.4 Testing the current leader on the leader board.") {
            LeaderBoard lb = LeaderBoard();
            std::ifstream input_file("/Users/ved/Documents/Classes/Spring-2021/CS-126/cinder_0.9.2_mac/my-projects/final-project-dev-ved30/data/test/lb1.txt");
            if (input_file.is_open()) {
                input_file >> lb;
                input_file.close();
            }
            REQUIRE(lb.FindCurrentLeader() == "ved");
        }
        SECTION("1.5 Testing the scores in the player map after updating player 1 score") {
            LeaderBoard lb = LeaderBoard();
            std::ifstream input_file("/Users/ved/Documents/Classes/Spring-2021/CS-126/cinder_0.9.2_mac/my-projects/final-project-dev-ved30/data/test/lb1.txt");
            if (input_file.is_open()) {
                input_file >> lb;
                input_file.close();
            }
            lb.UpdatePlayerScore("ved", 10);
            std::unordered_map<std::string, size_t> map = lb.GetPlayerMap();
            REQUIRE(map["ved"] == 2050);
            REQUIRE(map["dev"] == 420);
        }
        SECTION("1.6 Testing the scores in the player map after updating player 2 score") {
            LeaderBoard lb = LeaderBoard();
            std::ifstream input_file("/Users/ved/Documents/Classes/Spring-2021/CS-126/cinder_0.9.2_mac/my-projects/final-project-dev-ved30/data/test/lb1.txt");
            if (input_file.is_open()) {
                input_file >> lb;
                input_file.close();
            }
            lb.UpdatePlayerScore("dev", 80);
            std::unordered_map<std::string, size_t> map = lb.GetPlayerMap();
            REQUIRE(map["ved"] == 2040);
            REQUIRE(map["dev"] == 500);
        }
        SECTION("1.7 Testing the scores in the player map after updating both player scores") {
            LeaderBoard lb = LeaderBoard();
            std::ifstream input_file("/Users/ved/Documents/Classes/Spring-2021/CS-126/cinder_0.9.2_mac/my-projects/final-project-dev-ved30/data/test/lb1.txt");
            if (input_file.is_open()) {
                input_file >> lb;
                input_file.close();
            }
            lb.UpdatePlayerScore("dev", 80);
            lb.UpdatePlayerScore("ved", 460);
            std::unordered_map<std::string, size_t> map = lb.GetPlayerMap();
            REQUIRE(map["ved"] == 2500);
            REQUIRE(map["dev"] == 500);
        }
        SECTION("1.8 Testing addition of a new player - player names") {
            LeaderBoard lb = LeaderBoard();
            std::ifstream input_file("/Users/ved/Documents/Classes/Spring-2021/CS-126/cinder_0.9.2_mac/my-projects/final-project-dev-ved30/data/test/lb1.txt");
            if (input_file.is_open()) {
                input_file >> lb;
                input_file.close();
            }
            lb.UpdatePlayerScore("aaa", 80);
            std::unordered_map<std::string, size_t> map = lb.GetPlayerMap();
            REQUIRE(lb.GetPlayerMap().size() == 3);
            REQUIRE(lb.GetPlayerMap().find("ved") != lb.GetPlayerMap().end());
            REQUIRE(lb.GetPlayerMap().find("dev") != lb.GetPlayerMap().end());
            REQUIRE(lb.GetPlayerMap().find("aaa") != lb.GetPlayerMap().end());
        }
        SECTION("1.9 Testing addition of a new player - player score") {
            LeaderBoard lb = LeaderBoard();
            std::ifstream input_file("/Users/ved/Documents/Classes/Spring-2021/CS-126/cinder_0.9.2_mac/my-projects/final-project-dev-ved30/data/test/lb1.txt");
            if (input_file.is_open()) {
                input_file >> lb;
                input_file.close();
            }
            lb.UpdatePlayerScore("aaa", 80);
            std::unordered_map<std::string, size_t> map = lb.GetPlayerMap();
            REQUIRE(lb.GetPlayerMap().size() == 3);
            REQUIRE(map["ved"] == 2040);
            REQUIRE(map["dev"] == 420);
            REQUIRE(map["aaa"] == 80);
        }
        SECTION("1.10 Testing addition of a new player - winner") {
            LeaderBoard lb = LeaderBoard();
            std::ifstream input_file("/Users/ved/Documents/Classes/Spring-2021/CS-126/cinder_0.9.2_mac/my-projects/final-project-dev-ved30/data/test/lb1.txt");
            if (input_file.is_open()) {
                input_file >> lb;
                input_file.close();
            }
            lb.UpdatePlayerScore("aaa", 8000);
            std::unordered_map<std::string, size_t> map = lb.GetPlayerMap();
            REQUIRE(lb.FindCurrentLeader() == "aaa");
        }
        SECTION("1.11 Testing the size of the player map and player names - different sized leader board") {
            LeaderBoard lb = LeaderBoard();
            std::ifstream input_file("/Users/ved/Documents/Classes/Spring-2021/CS-126/cinder_0.9.2_mac/my-projects/final-project-dev-ved30/data/test/lb2.txt");
            if (input_file.is_open()) {
                input_file >> lb;
                input_file.close();
            }
            REQUIRE(lb.GetPlayerMap().size() == 4);
            REQUIRE(lb.GetPlayerMap().find("aaa") != lb.GetPlayerMap().end());
            REQUIRE(lb.GetPlayerMap().find("ddd") != lb.GetPlayerMap().end());
            REQUIRE(lb.GetPlayerMap().find("bbb") != lb.GetPlayerMap().end());
            REQUIRE(lb.GetPlayerMap().find("ccc") != lb.GetPlayerMap().end());
        }
        SECTION("1.12 Testing the player scores and winner - different sized leader board") {
            LeaderBoard lb = LeaderBoard();
            std::ifstream input_file("/Users/ved/Documents/Classes/Spring-2021/CS-126/cinder_0.9.2_mac/my-projects/final-project-dev-ved30/data/test/lb2.txt");
            if (input_file.is_open()) {
                input_file >> lb;
                input_file.close();
            }
            std::unordered_map<std::string, size_t> map = lb.GetPlayerMap();
            REQUIRE(lb.GetPlayerMap().size() == 4);
            REQUIRE(map["aaa"] == 420);
            REQUIRE(map["bbb"] == 200);
            REQUIRE(map["ccc"] == 500);
            REQUIRE(map["ddd"] == 900);
            REQUIRE(lb.FindCurrentLeader() == "ddd");
        }
        SECTION("1.13 Testing adding new player and incrementing score - different sized leader board") {
            LeaderBoard lb = LeaderBoard();
            std::ifstream input_file("/Users/ved/Documents/Classes/Spring-2021/CS-126/cinder_0.9.2_mac/my-projects/final-project-dev-ved30/data/test/lb2.txt");
            if (input_file.is_open()) {
                input_file >> lb;
                input_file.close();
            }
            lb.UpdatePlayerScore("aaa", 480);
            lb.UpdatePlayerScore("eee", 1000);
            std::unordered_map<std::string, size_t> map = lb.GetPlayerMap();
            REQUIRE(lb.GetPlayerMap().size() == 5);
            REQUIRE(map["aaa"] == 900);
            REQUIRE(map["bbb"] == 200);
            REQUIRE(map["ccc"] == 500);
            REQUIRE(map["ddd"] == 900);
            REQUIRE(map["eee"] == 1000);
            REQUIRE(lb.FindCurrentLeader() == "eee");
        }
    }
    TEST_CASE("2. Testing << overloading and error handling.") {

        SECTION("2.1 Testing the size of the player map when it's created") {
            LeaderBoard lb = LeaderBoard();
            lb.UpdatePlayerScore("aaa", 480);
            lb.UpdatePlayerScore("bbb", 480);
            lb.UpdatePlayerScore("ccc", 490);
            std::unordered_map<std::string, size_t> map = lb.GetPlayerMap();

            REQUIRE(lb.GetPlayerMap().size() == 3);
            REQUIRE(map["aaa"] == 480);
            REQUIRE(map["bbb"] == 480);
            REQUIRE(map["ccc"] == 490);
            REQUIRE(lb.GetPlayerMap().find("aaa") != lb.GetPlayerMap().end());
            REQUIRE(lb.GetPlayerMap().find("ccc") != lb.GetPlayerMap().end());
            REQUIRE(lb.GetPlayerMap().find("bbb") != lb.GetPlayerMap().end());
            REQUIRE(lb.FindCurrentLeader() == "ccc");
        }
        SECTION("2.2 Testing the size of the player map and player name after loading from file") {

            // Creating Leader Board object
            std::string path = "/Users/ved/Documents/Classes/Spring-2021/CS-126/cinder_0.9.2_mac/my-projects/final-project-dev-ved30/data/test/lb3.txt";
            LeaderBoard lb1 = LeaderBoard();
            lb1.UpdatePlayerScore("aaa", 480);
            lb1.UpdatePlayerScore("bbb", 480);
            lb1.UpdatePlayerScore("ccc", 490);

            // Saving the file
            std::ofstream output_file(path);
            if (output_file.is_open()) {
                output_file << lb1;
                output_file.close();
            }

            // Loading new board from saved file.
            LeaderBoard lb2 = LeaderBoard();
            std::ifstream input_file(path);
            if (input_file.is_open()) {
                input_file >> lb2;
                input_file.close();
            }

            std::unordered_map<std::string, size_t> map = lb2.GetPlayerMap();
            REQUIRE(lb2.GetPlayerMap().size() == 3);
            REQUIRE(lb2.GetPlayerMap().find("aaa") != lb2.GetPlayerMap().end());
            REQUIRE(lb2.GetPlayerMap().find("ccc") != lb2.GetPlayerMap().end());
            REQUIRE(lb2.GetPlayerMap().find("bbb") != lb2.GetPlayerMap().end());

        }

        SECTION("2.3 Testing the player scores and leader name after loading from file") {

            // Creating Leader Board object
            std::string path = "/Users/ved/Documents/Classes/Spring-2021/CS-126/cinder_0.9.2_mac/my-projects/final-project-dev-ved30/data/test/lb3.txt";
            LeaderBoard lb1 = LeaderBoard();
            lb1.UpdatePlayerScore("aaa", 400);
            lb1.UpdatePlayerScore("bbb", 400);
            lb1.UpdatePlayerScore("ccc", 490);

            // Saving the file
            std::ofstream output_file(path);
            if (output_file.is_open()) {
                output_file << lb1;
                output_file.close();
            }

            // Loading new board from saved file.
            LeaderBoard lb2 = LeaderBoard();
            std::ifstream input_file(path);
            if (input_file.is_open()) {
                input_file >> lb2;
                input_file.close();
            }

            std::unordered_map<std::string, size_t> map = lb2.GetPlayerMap();
            REQUIRE(lb2.GetPlayerMap().size() == 3);
            REQUIRE(map["aaa"] == 400);
            REQUIRE(map["bbb"] == 400);
            REQUIRE(map["ccc"] == 490);
            REQUIRE(lb2.FindCurrentLeader() == "ccc");

        }
        SECTION("2.4 Testing the size of the player map and player name after loading from file - different size") {

            // Creating Leader Board object
            std::string path = "/Users/ved/Documents/Classes/Spring-2021/CS-126/cinder_0.9.2_mac/my-projects/final-project-dev-ved30/data/test/lb3.txt";
            LeaderBoard lb1 = LeaderBoard();
            lb1.UpdatePlayerScore("aaa", 480);
            lb1.UpdatePlayerScore("ccc", 490);

            // Saving the file
            std::ofstream output_file(path);
            if (output_file.is_open()) {
                output_file << lb1;
                output_file.close();
            }

            // Loading new board from saved file.
            LeaderBoard lb2 = LeaderBoard();
            std::ifstream input_file(path);
            if (input_file.is_open()) {
                input_file >> lb2;
                input_file.close();
            }

            std::unordered_map<std::string, size_t> map = lb2.GetPlayerMap();
            REQUIRE(lb2.GetPlayerMap().size() == 2);
            REQUIRE(lb2.GetPlayerMap().find("aaa") != lb2.GetPlayerMap().end());
            REQUIRE(lb2.GetPlayerMap().find("ccc") != lb2.GetPlayerMap().end());

        }

        SECTION("2.5 Testing Reading from a bad file - 1 (empty score line)") {

            // Creating Leader Board object
            std::string path = "/Users/ved/Documents/Classes/Spring-2021/CS-126/cinder_0.9.2_mac/my-projects/final-project-dev-ved30/data/test/lb3-b1.txt";

            // Loading new board from saved file.
            LeaderBoard lb2 = LeaderBoard();
            std::ifstream input_file(path);
            REQUIRE_THROWS_AS(input_file >> lb2, std::invalid_argument);
        }
        SECTION("2.6 Testing Reading from a bad file - 2 (empty odd number of lines)") {

            // Creating Leader Board object
            std::string path = "/Users/ved/Documents/Classes/Spring-2021/CS-126/cinder_0.9.2_mac/my-projects/final-project-dev-ved30/data/test/lb3-b2.txt";

            // Loading new board from saved file.
            LeaderBoard lb2 = LeaderBoard();
            std::ifstream input_file(path);
            REQUIRE_THROWS_AS(input_file >> lb2, std::invalid_argument);
        }
        SECTION("2.7 Testing Reading from a bad file - 2 (invalid score)") {

            // Creating Leader Board object
            std::string path = "/Users/ved/Documents/Classes/Spring-2021/CS-126/cinder_0.9.2_mac/my-projects/final-project-dev-ved30/data/test/lb3-b3.txt";

            // Loading new board from saved file.
            LeaderBoard lb2 = LeaderBoard();
            std::ifstream input_file(path);
            REQUIRE_THROWS_AS(input_file >> lb2, std::invalid_argument);
        }
    }
}


