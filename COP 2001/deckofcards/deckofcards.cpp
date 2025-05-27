/**********************************************************
* file: deckofcards.cpp
* author: Darren Fulton
* class: COP 2001 Summer 2022
* purpose: create a deck of cards and identify the faces
**********************************************************/

#include <iostream>

enum faces {
    Ace = 1,
    Two,
    Three,
    Four,
    Five,
    Six,
    Seven,
    Eight,
    Nine,
    Ten,
    Jack,
    Queen,
    King

};
struct playingCard {
    char suit;
    faces face;

};

faces cFaces(int face);
void standardDeck(playingCard *pDeck);

int main() {

    //create an array for a full deck
    playingCard fullDeck[52];

    //create a pointer variable to point towards
    playingCard *pDeck = &fullDeck[0];
    standardDeck(pDeck);

    int cards = 0;
    while (cards < 52) {

        std::cout << fullDeck[cards].suit << "   ";

        switch (fullDeck[cards].face) {

            //checks if the face is a non-integer face
            case Jack:
                std::cout << 'J' << "   ";
                break;
            case Queen:
                std::cout << 'Q' << "   ";
                break;
            case King:
                std::cout << 'K' << "   ";
                break;
            case Ace:
                std::cout << 'A' << "   ";
                break;
            default:
                std::cout << fullDeck[cards].face << "   ";

        }//end of face switch statement

        cards++;

    }//end of the 52 cards loop

    return 0;
}// end of main

faces cFaces(int face) {

    faces currentCard;

    switch (face) {

        case 0:
            currentCard = Ace;
            break;
        case 1:
            currentCard = Two;
            break;
        case 2:
            currentCard = Three;
            break;
        case 3:
            currentCard = Four;
            break;
        case 4:
            currentCard = Five;
            break;
        case 5:
            currentCard = Six;
            break;
        case 6:
            currentCard = Seven;
            break;
        case 7:
            currentCard = Eight;
            break;
        case 8:
            currentCard = Nine;
            break;
        case 9:
            currentCard = Ten;
            break;
        case 10:
            currentCard = Jack;
            break;
        case 11:
            currentCard = Queen;
            break;
        case 12:
            currentCard = King;
            break;

    }//stops checking face

    return currentCard;
}// end of cFace
void standardDeck(playingCard *pDeck) {

    //for the four different kind of faces
    int count = 0;

    //for the 13 possible cards for each type of face
    int otherCount = 0;

    while (count < 4) {

        while (otherCount < 13) {

            if (count == 0) {
                pDeck->suit = 'D';
                pDeck->face = cFaces(otherCount);
            }
            else if (count == 1) {
                pDeck->suit = 'H';
                pDeck->face = cFaces(otherCount);
            }
            else if (count == 2) {
                pDeck->suit = 'C';
                pDeck->face = cFaces(otherCount);
            }
            else if (count == 3) {
                pDeck->suit = 'S';
                pDeck->face = cFaces(otherCount);
            }

            pDeck++;//updates to move up the array
            otherCount++;//updates to get the next card

        }//end of the 13 cards loop

        count++;//updates to reach the other kinds of faces
        otherCount = 0;//assign 0 in order to go back and do the loop for the 13 cards again

    }//end of four different faces loop

}//end of standardDeck
