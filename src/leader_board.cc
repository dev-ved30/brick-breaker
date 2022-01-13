//
// Created by Ved Shah on 4/19/21.
//
#include "leader_board.h"

namespace game {

    LeaderBoard::LeaderBoard() {}

    LeaderBoard::LeaderBoard(size_t length, size_t margin) {

        length_ = length;
        margin_ = margin;
    }

    void LeaderBoard::Draw() {

        // Drawing the frame for the leader board.
        ci::gl::color(primary_color_);
        ci::gl::drawStrokedRect(ci::Rectf(
                vec2(length_ , margin_length_multiplier_ * margin_),
                vec2(length_ + (margin_length_multiplier_ + 1) * margin_,
                         margin_height_multiplier_ * margin_)));
        size_t scaler = 1;

        //Writing the current leader.
        ci::gl::drawStringCentered(
                "Current Leader" ,
                glm::vec2(length_ + margin_, margin_length_multiplier_ * margin_ + (scaler * 20)),
                leader_color_);
        ++scaler;
        ci::gl::drawStringCentered(
                FindCurrentLeader() + "\t" + std::to_string(player_map_[FindCurrentLeader()]) ,
                glm::vec2(length_ + margin_, margin_length_multiplier_ * margin_ +
                                (scaler * text_line_height_)),
                leader_color_);

        // Displaying the complete list of players and corresponding scores.
        ++scaler;
        ci::gl::drawStringCentered(
                "Other Players" ,
                glm::vec2(length_ + margin_, margin_length_multiplier_ * margin_ +
                                (scaler * text_line_height_)),
                primary_color_);

        ++scaler;
        for (auto const& instance : player_map_) {
            ci::gl::drawStringCentered(
                    instance.first + "\t" + std::to_string(instance.second) ,
                    glm::vec2(length_+ margin_ , margin_length_multiplier_ * margin_ +
                                    (scaler * text_line_height_)),
                    primary_color_);
            ++scaler;
        }
    }

    void LeaderBoard::UpdatePlayerScore(std::string name, size_t increment) {

        // Checking if the map contains the key. Reference taken from:
        // https://www.techiedelight.com/check-given-key-exists-map-cpp/#:~:text=To%20check%20for%20the%20existence,the%20specified%20key%20is%20not

        if (player_map_.find(name) != player_map_.end()) {
            player_map_[name] =  player_map_[name] + increment;
        }
        else {
            player_map_[name] = increment;
        }

    }

    const std::string LeaderBoard::FindCurrentLeader() const {
        size_t max = 0;
        std::string winner = "";
        for (auto const& instance : player_map_) {
            if (instance.second > max) {
                max = instance.second;
                winner = instance.first;
            }
        }
        return winner;
    }

    std::istream &operator>>(std::istream &is, LeaderBoard &lb) {

        // Checking if the file cannot be opened.
        if (is.bad()) {
            throw std::invalid_argument("File does not exist");
        }
        std::string line = "";
        size_t count = 0;
        while (!is.eof()) {
            // Getting the name of the player.
            std::getline(is, line);
            std::string player_name = line;
            ++count;
            //Getting the score of the player.
            std::getline(is, line);
            size_t score = std::stoi(line);
            // Adding the player score pair to the hashmap.
            lb.player_map_[player_name] = score;
            ++count;
        }
        if (count % 2 != 0) {
            throw std::invalid_argument("Bad file format");
        }
        return is;
    }

    std::ostream& operator<<(std::ostream& os, LeaderBoard& lb) {

        size_t counter = 0;
        for (auto const& instance : lb.player_map_) {
            // if else avoids new line at the begining of the file.
            if (counter != 0) {
                os << '\n' << instance.first << '\n' << instance.second;
            } else {
                os << instance.first << '\n' << instance.second;
            }
            ++counter;
        }
        return os;
    }

    const std::unordered_map<std::string, size_t>& LeaderBoard::GetPlayerMap() const {
        return player_map_;
    }


}  // namespace idealgas
