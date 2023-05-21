#include "Mtmchkin.h"
const int MAX_LEVEL = 10;

//construtor
Mtmchkin::Mtmchkin(const char* playerName, const Card* cardsArray, int numOfCards) : m_player(playerName)
{
    this->m_deck = new Card[numOfCards];
    for (int i = 0; i < numOfCards; i++)
    {
        this->m_deck[i] = cardsArray[i];
    }
    this->m_deckLength = numOfCards;
    this->m_status = GameStatus::MidGame;
    this->m_nextCard = 0;
}

//copy constructor
Mtmchkin::Mtmchkin(const Mtmchkin& game): m_player(game.m_player)
{
    this->m_deck = new Card[game.m_deckLength];
    this->m_nextCard = game.m_nextCard;
    this->m_status = game.m_status;
    this->m_deckLength = game.m_deckLength;
    for(int i = 0; i < this->m_deckLength; i++)
    {
        this->m_deck[i] = game.m_deck[i];
    }
}


//destructor
Mtmchkin::~Mtmchkin()
{
    delete[] this->m_deck;
}

//operator -
Mtmchkin& Mtmchkin::operator=(const Mtmchkin& game)
{
    if(this == &game)
    {
        return *this;
    }
    delete[] this->m_deck;
    this->m_deck = new Card[game.m_deckLength];
    for(int i = 0; i < game.m_deckLength; i++)
    {
        this->m_deck[i] = game.m_deck[i];
    }
    this->m_status = game.m_status;
    this->m_deckLength = game.m_deckLength;
    this->m_player = game.m_player;
    return *this;
}

void Mtmchkin::playNextCard()
{
    this->m_deck[this->m_nextCard].printInfo();
    this->m_deck[this->m_nextCard].applyEncounter(this->m_player);
    this->m_player.printInfo();
    if(this->isOver())
    {
        return;
    }
    if(this->m_player.isKnockedOut())
    {
        this->m_status = GameStatus::Loss;
    }
    else if(this->m_player.getLevel() == MAX_LEVEL)
    {
        this->m_status = GameStatus::Win;
    }
    else
    {
        if(this->m_nextCard == this->m_deckLength -1)
        {
            this->m_nextCard = 0;
        }
        else
        {
            this->m_nextCard++;
        }
    }
}

bool Mtmchkin::isOver() const
{
    return this->m_status != GameStatus::MidGame;
}

GameStatus Mtmchkin::getGameStatus() const
{
    return this->m_status;
}