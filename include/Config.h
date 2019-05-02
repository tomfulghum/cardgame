#pragma once

#include "Utility/Color.h"

constexpr auto SPRITE_CARD_ROCK           = "assets/sprites/card_rock.png";
constexpr auto SPRITE_CARD_PAPER          = "assets/sprites/card_paper.png";
constexpr auto SPRITE_CARD_SCISSORS       = "assets/sprites/card_scissors.png";
constexpr auto SPRITE_CARD_LIZARD         = "assets/sprites/card_lizard.png";
constexpr auto SPRITE_CARD_SPOCK          = "assets/sprites/card_spock.png";
constexpr auto SPRITE_CARD_HIGHLIGHT      = "assets/sprites/card_highlight.png";
constexpr auto SPRITE_CARD_DECK           = "assets/sprites/card_deck.png";
constexpr auto SPRITE_CARD_DECK_HIGHLIGHT = "assets/sprites/card_deck_highlight.png";

constexpr auto SPRITE_CARD_ROCK_NAME           = "sprite_card_rock";
constexpr auto SPRITE_CARD_PAPER_NAME          = "sprite_card_paper";
constexpr auto SPRITE_CARD_SCISSORS_NAME       = "sprite_card_scissors";
constexpr auto SPRITE_CARD_LIZARD_NAME         = "sprite_card_lizard";
constexpr auto SPRITE_CARD_SPOCK_NAME          = "sprite_card_spock";
constexpr auto SPRITE_CARD_HIGHLIGHT_NAME      = "sprite_card_highlight";
constexpr auto SPRITE_CARD_DECK_NAME           = "sprite_card_deck";
constexpr auto SPRITE_CARD_DECK_HIGHLIGHT_NAME = "sprite_card_deck_highlight";

constexpr auto FONT_PATH = "assets/fonts/uni0553-webfont.ttf";

constexpr auto CARD_ROCK_COUNT = 10;
constexpr auto CARD_PAPER_COUNT = 10;
constexpr auto CARD_SCISSORS_COUNT = 10;
constexpr auto CARD_LIZARD_COUNT = 10;
constexpr auto CARD_SPOCK_COUNT = 10;
constexpr auto CARD_DECK_SIZE = CARD_ROCK_COUNT + CARD_PAPER_COUNT + CARD_SCISSORS_COUNT + CARD_LIZARD_COUNT + CARD_SPOCK_COUNT;

constexpr Color COLOR_BASE = { 255, 255, 255, 255 };
constexpr Color COLOR_HIGHLIGHT = { 64, 168, 64, 255 };