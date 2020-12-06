// Skat.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <array>
#include <time.h>

enum COLOR { heart, diamond, spade, club };
enum VALUE { seven, eight, nine, ten, jack, queen, king, ace };
struct card {
    COLOR color;
    VALUE value;
};

void print_deck(std::array<std::shared_ptr<card>, 32> deck) {
    for (auto element : deck) {
        switch (element -> value) {
        case seven: std::cout << "7"; break;
        case eight: std::cout << "8"; break;
        case nine: std::cout << "9"; break;
        case ten: std::cout << "T"; break;
        case jack: std::cout << "J"; break;
        case queen: std::cout << "Q"; break;
        case king: std::cout << "K"; break;
        case ace: std::cout << "A"; break;
        }
        switch (element -> color) {
        case heart: std::cout << "h"; break;
        case diamond: std::cout << "d"; break;
        case spade: std::cout << "s"; break;
        case club: std::cout << "c"; break;
        }
        std::cout << " ";
    }
    std::cout << std::endl;
}

void fisher_yates_shuffle(std::array<std::shared_ptr<card>, 32> &deck) {
    for (int i = deck.size() - 1; i >= 0; i--) {
        int j = rand() % (i+1);
        auto help = deck[j];
        deck[j] = deck[i];
        deck[i] = help;
    }
}

int main()
{
    srand(time(NULL));
    int count = 0;
    std::array<std::shared_ptr<card>, 32> deck;


    for (int i = COLOR::heart; i <= club; i++) {
        for (int j = VALUE::seven; j <= ace; j++) {
            deck[count] = std::shared_ptr<card>(new card);
            deck[count] -> color = (COLOR)i; //Warning is fine, because the 2 used enums never have the same value inside
            deck[count] -> value = (VALUE)j; //Warning is fine, because the 2 used enums never have the same value inside
            count++;
        }
    }
    

    print_deck(deck);
    fisher_yates_shuffle(deck);
    print_deck(deck);

}

