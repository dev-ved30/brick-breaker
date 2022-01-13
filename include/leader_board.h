#pragma once

#include "cinder/gl/gl.h"

using glm::vec2;
using std::vector;

namespace game {
    /**
     * A class to store a Leaderboard and its attributes including the operator.
     */
    class LeaderBoard {
    public:

        LeaderBoard();

        LeaderBoard(size_t length, size_t margin);

        /**
         * Draws the grid of blocks.
         */
        void Draw();

        /**
         * Updates the score of the player in the Hash Map.
         * @param name The name of the player.
         * @param increment The score increment.
         */
        void UpdatePlayerScore(std::string name, size_t increment);

        /**
         * Returns the name of the player with the highest score.
         * @return The name of the current leader.
         */
        const std::string FindCurrentLeader() const;

        /**
         * Reads the leaderboard from the text file.
         * @param is Input stream object
         * @param lb LeaderBoard Object that is used.
         * @return The input stream object.
         */
        friend std::istream& operator>>(std::istream& is, LeaderBoard& lb);

        /**
         * writes the leaderboard rankings to the text file
         * @param os Output Stream Object
         * @param lb LeaderBoard Object that is used.
         * @return The output stream object.
         */
        friend std::ostream& operator<<(std::ostream& os, LeaderBoard& lb);

        const std::unordered_map<std::string, size_t>& GetPlayerMap() const;

    private:
        size_t length_;
        size_t margin_;
        std::unordered_map<std::string, size_t> player_map_;

        size_t margin_length_multiplier_ = 6;
        size_t margin_height_multiplier_ = 17;
        size_t text_line_height_ = 20;
        ci::Color primary_color_ = ci::Color("white");
        ci::Color leader_color_ = ci::Color("gold");

    };

}  // namespace game
