#pragma once

#include "Entity.h"
#include "Entity/PlayingCardSpot.h"
#include "Entity/PlayingCardPile.h"
#include "Entity/TextButton.h"
#include "PlayingCardDeck.h"

class Player;

class GameController : public Entity
{
	friend class EntityManager;

public:
	void Update() override;
	void Render() override;

	void Initialize();

	bool PlayCard(PlayingCard* _card, Player* _player);
	void DrawCard(PlayingCard* _card, PlayingCardPile* _pile);

private:
	GameController();

	enum class GamePhase
	{
		MENU,
		PLAY,
		DRAW,
		TURN_END,
		GAME_END
	};

	GamePhase phase = GamePhase::PLAY;

	Player* player1;
	Player* player2;
	Player* activePlayer;
	Player* lastWinner;
	PlayingCardSpot* spotPlayer1;
	PlayingCardSpot* spotPlayer2;
	PlayingCardDeck* deck;
	PlayingCardPile* pile1;
	PlayingCardPile* pile2;

	TextButton* textPlayer1;
	TextButton* textPlayer2;
	TextButton* scorePlayer1;
	TextButton* scorePlayer2;
	TextButton* textMsgVs;
	TextButton* textMsgWinner;
	TextButton* textMsgScores;
	TextButton* textMsgWins;
	TextButton* textMsgDraw;
	TextButton* buttonContinue;
	TextButton* buttonEnd;

	int playerTurnCounter = 0;

	void BeginTurn(Player* _winner);
	void SwitchPlayers();
	void EndTurn();
	void SetPlayerActive(Player* _player);
};