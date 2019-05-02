#include "Entity/GameController.h"

#include "glm.hpp"

#include "AssetDatabase.h"
#include "Config.h"
#include "EntityManager.h"
#include "Player.h"

GameController::GameController() : Entity(glm::vec2(), 0)
{

}

void GameController::Update()
{
	this->scorePlayer1->SetText(std::to_string(this->player1->GetScore()));
	this->scorePlayer2->SetText(std::to_string(this->player2->GetScore()));

	if (this->activePlayer == this->player1)
	{
		this->textPlayer1->SetColor(COLOR_HIGHLIGHT);
		this->textPlayer2->SetColor(COLOR_BASE);
	}
	else if (this->activePlayer == this->player2)
	{
		this->textPlayer1->SetColor(COLOR_BASE);
		this->textPlayer2->SetColor(COLOR_HIGHLIGHT);
	}
}

void GameController::Render()
{

}

void GameController::Initialize()
{
	int boardMiddle = (Environment::GetWindowWidth() / 2) - 130;

	this->player1 = new Player(this, glm::vec2(boardMiddle - 320, 10));
	this->player2 = new Player(this, glm::vec2(boardMiddle - 320, 490));

	this->pile1 = EntityManager::CreateEntity<PlayingCardPile>();
	this->pile1->SetPosition(boardMiddle + 550, 100);
	this->pile1->SetOnClickCallback([=](Entity* _cardPile) {
		PlayingCardPile* pile = static_cast<PlayingCardPile*>(_cardPile);
		this->DrawCard(pile->DrawCard(), pile);
	});

	this->pile2 = EntityManager::CreateEntity<PlayingCardPile>();
	this->pile2->SetPosition(boardMiddle + 550, 400);
	this->pile2->SetOnClickCallback([=](Entity* _cardPile) {
		PlayingCardPile* pile = static_cast<PlayingCardPile*>(_cardPile);
		this->DrawCard(pile->DrawCard(), pile);
	});

	this->spotPlayer1 = EntityManager::CreateEntity<PlayingCardSpot>();
	this->spotPlayer1->SetPosition(boardMiddle - 280, 250);
	this->spotPlayer1->SetDoHighlight(false);
	this->spotPlayer2 = EntityManager::CreateEntity<PlayingCardSpot>();
	this->spotPlayer2->SetPosition(boardMiddle + 120, 250);
	this->spotPlayer2->SetDoHighlight(false);

	this->textPlayer1 = EntityManager::CreateEntity<TextButton>();
	this->textPlayer1->SetPosition(boardMiddle - 460, 290);
	this->textPlayer1->SetText("Player 1");
	this->textPlayer1->SetSize(36);
	this->textPlayer1->SetInteractable(false);
	this->scorePlayer1 = EntityManager::CreateEntity<TextButton>();
	this->scorePlayer1->SetPosition(boardMiddle - 341, 340);
	this->scorePlayer1->SetSize(48);
	this->scorePlayer1->SetInteractable(false);

	this->textPlayer2 = EntityManager::CreateEntity<TextButton>();
	this->textPlayer2->SetPosition(boardMiddle + 315, 290);
	this->textPlayer2->SetText("Player 2");
	this->textPlayer2->SetSize(36);
	this->textPlayer2->SetInteractable(false);
	this->scorePlayer2 = EntityManager::CreateEntity<TextButton>();
	this->scorePlayer2->SetPosition(boardMiddle + 312, 340);
	this->scorePlayer2->SetSize(48);
	this->scorePlayer2->SetInteractable(false);

	this->textMsgVs = EntityManager::CreateEntity<TextButton>();
	this->textMsgVs->SetPosition(boardMiddle - 45, 310);
	this->textMsgVs->SetText("VS");
	this->textMsgVs->SetSize(62);
	this->textMsgVs->SetInteractable(false);
	this->textMsgVs->SetActive(true);

	this->textMsgWinner = EntityManager::CreateEntity<TextButton>();
	this->textMsgWinner->SetPosition(boardMiddle - 80, 260);
	this->textMsgWinner->SetText("Player 2");
	this->textMsgWinner->SetSize(36);
	this->textMsgWinner->SetInteractable(false);
	this->textMsgWinner->SetActive(false);

	this->textMsgScores = EntityManager::CreateEntity<TextButton>();
	this->textMsgScores->SetPosition(boardMiddle - 80, 305);
	this->textMsgScores->SetText("SCORES");
	this->textMsgScores->SetSize(36);
	this->textMsgScores->SetInteractable(false);
	this->textMsgScores->SetActive(false);

	this->textMsgWins = EntityManager::CreateEntity<TextButton>();
	this->textMsgWins->SetPosition(boardMiddle - 62, 305);
	this->textMsgWins->SetText("WINS");
	this->textMsgWins->SetSize(48);
	this->textMsgWins->SetInteractable(false);
	this->textMsgWins->SetActive(false);

	this->textMsgDraw = EntityManager::CreateEntity<TextButton>();
	this->textMsgDraw->SetPosition(boardMiddle - 97, 280);
	this->textMsgDraw->SetText("DRAW");
	this->textMsgDraw->SetSize(62);
	this->textMsgDraw->SetInteractable(false);
	this->textMsgDraw->SetActive(false);

	this->buttonContinue = EntityManager::CreateEntity<TextButton>();
	this->buttonContinue->SetPosition(boardMiddle - 85, 400);
	this->buttonContinue->SetText("Continue");
	this->buttonContinue->SetSize(36);
	this->buttonContinue->SetInteractable(true);
	this->buttonContinue->SetActive(false);
	this->buttonContinue->SetOnClickCallback([=](Entity* _textButton) {
		this->BeginTurn(this->lastWinner);
	});

	this->buttonEnd = EntityManager::CreateEntity<TextButton>();
	this->buttonEnd->SetPosition(boardMiddle - 95, 400);
	this->buttonEnd->SetText("End Game");
	this->buttonEnd->SetSize(36);
	this->buttonEnd->SetInteractable(true);
	this->buttonEnd->SetActive(false);

	this->deck = new PlayingCardDeck();
	this->deck->Shuffle();

	for (int i = 0; i < 4; i++)
	{
		player1->GiveCard(deck->DrawCard());
		player2->GiveCard(deck->DrawCard());
	}

	while (this->deck->Count() > 0)
	{
		this->pile1->AddToTop(this->deck->DrawCard());
		this->pile2->AddToTop(this->deck->DrawCard());
	}

	this->BeginTurn(this->player1);
}

bool GameController::PlayCard(PlayingCard* _card, Player* _player)
{
	if (_player == this->activePlayer && this->phase == GamePhase::PLAY)
	{
		if (_player == this->player1)
		{
			this->spotPlayer1->SetCard(_card);
		}
		else if (_player == this->player2)
		{
			this->spotPlayer2->SetCard(_card);
		}

		this->SwitchPlayers();
		return true;
	}

	return false;
}

void GameController::DrawCard(PlayingCard* _card, PlayingCardPile* _pile)
{
	if (this->phase == GamePhase::DRAW)
	{
		if (this->activePlayer->GiveCard(_card))
		{
			this->SwitchPlayers();
			return;
		}
	}

	_pile->AddToTop(_card);
}

void GameController::BeginTurn(Player* _winner)
{
	this->phase = GamePhase::DRAW;
	this->SetPlayerActive(_winner);
	this->textMsgVs->SetActive(true);
	this->textMsgWinner->SetActive(false);
	this->textMsgScores->SetActive(false);
	this->textMsgWins->SetActive(false);
	this->textMsgDraw->SetActive(false);
	this->buttonContinue->SetActive(false);
	this->buttonEnd->SetActive(false);
}

void GameController::SwitchPlayers()
{
	this->playerTurnCounter++;

	if (this->playerTurnCounter >= 2)
	{
		this->playerTurnCounter = 0;

		if (this->phase == GamePhase::PLAY)
		{
			EndTurn();
			return;
		}
		else if (this->phase == GamePhase::DRAW)
		{
			this->phase = GamePhase::PLAY;
		}
	}

	if (this->activePlayer == this->player1)
	{
		this->SetPlayerActive(player2);
	}
	else
	{
		this->SetPlayerActive(player1);
	}
}

void GameController::EndTurn()
{
	this->textMsgVs->SetActive(false);
	this->textMsgWins->SetActive(false);
	this->buttonEnd->SetActive(false);
	this->player1->SetDoHighlight(false);
	this->player2->SetDoHighlight(false);

	PlayingCard* cardPlayer1 = this->spotPlayer1->TakeCard();
	PlayingCard* cardPlayer2 = this->spotPlayer2->TakeCard();

	if (cardPlayer1->GetType() != cardPlayer2->GetType())
	{
		bool player1Won = cardPlayer1->Beats(cardPlayer2);

		this->lastWinner = player1Won ? this->player1 : this->player2;
		this->lastWinner->Score();
		std::string winnerString = player1Won ? "1" : "2";
		this->textMsgWinner->SetText("Player " + winnerString);
		this->textMsgWinner->SetActive(true);

		if (this->lastWinner->GetScore() >= 20)
		{
			this->phase = GamePhase::GAME_END;
			this->textMsgWins->SetActive(true);
			this->buttonEnd->SetActive(true);
		}
		else
		{
			this->textMsgScores->SetActive(true);
			this->buttonContinue->SetActive(true);
		}
	}
	else
	{
		if (this->lastWinner == nullptr)
		{
			this->lastWinner = this->player1;
		}

		this->textMsgWinner->SetActive(false);
		this->textMsgScores->SetActive(false);
		this->textMsgDraw->SetActive(true);
		this->buttonContinue->SetActive(true);
	}

	this->phase = GamePhase::TURN_END;
}

void GameController::SetPlayerActive(Player* _player)
{
	if (_player == this->player1)
	{
		this->activePlayer = this->player1;
		if (this->phase == GamePhase::PLAY)
		{
			this->player1->SetDoHighlight(true);
		}
		this->player2->SetDoHighlight(false);
	}
	else if (_player == this->player2)
	{
		this->activePlayer = this->player2;
		if (this->phase == GamePhase::PLAY)
		{
			this->player2->SetDoHighlight(true);
		}
		this->player1->SetDoHighlight(false);
	}
}