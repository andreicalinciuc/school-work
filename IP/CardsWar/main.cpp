#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

const unsigned short int max_number_of_cards = 52, max_number_of_players = 52;
const char *numbers="23456789ZJQKA";
const char *symbols="TRCP";
unsigned short int number_of_cards = 52, winner, val[max_number_of_players], draw = 0, n;
unsigned int moves;
bool participant[max_number_of_players];

struct play_card {
    char number, symbol;
};

play_card card [max_number_of_cards];

struct players {
    short int cards, current_card, last_card;
    play_card card [max_number_of_cards];
};

players player[max_number_of_players], table;

void GenerateDeck() {
    unsigned short int i, j;
    for (i=0; i<13; ++i)
    {
        for (j=0; j<4; ++j)
        {
            card[4*i+j].number = numbers[i];
            card[4*i+j].symbol = symbols[j];
        }
    }
}

void PrintDeck() {
    printf ("The deck is:\n");
    unsigned short int i;
    for (i=0; i<max_number_of_cards; ++i) printf ("{%c,%c}\t", card[i].number, card[i].symbol);
    printf ("\n\n");
}

void Swap (play_card &x, play_card &y) {
    play_card aux;
    aux = x;
    x = y;
    y = aux;
}

void ShuffleDeck() {
    printf ("Shuffling the cards...\n\n");
    srand(time(NULL));
    unsigned short int shuffles = 100;
    while (--shuffles) {
        Swap (card[rand()%number_of_cards], card[rand()%number_of_cards]);
    }
}

void DistributeDeck() {
    unsigned short int i, j;
    number_of_cards = (max_number_of_cards/n) * n;
    moves = 0; draw = 0; table.cards = 0; table.current_card = 0; table.last_card = -1;
    for (i=0; i<n; ++i){
        player[i].cards = number_of_cards/n;
        player[i].current_card = 0;
        player[i].last_card = (number_of_cards/n) - 1;
    }
    for (i=0; i<number_of_cards; i+=n) {
        for (j=0; j<n; ++j) {
            player[j].card[i/n] = card[i+j];
        }
    }
}

void Push (players &x, players &y) {
    x.last_card = (x.last_card+1) % number_of_cards;
    x.card[x.last_card] = y.card[y.current_card];
    y.current_card = (y.current_card+1) % number_of_cards;
    ++x.cards;
    --y.cards;
}

void Dump (players &x, players &y) {
    while (y.cards)
    {
        x.last_card = (x.last_card+1) % number_of_cards;
        x.card[x.last_card] = y.card[y.current_card];
        y.current_card = (y.current_card+1) % number_of_cards;
        ++x.cards;
        --y.cards;
    }
}

unsigned short int SignToNumber(play_card x) {
    unsigned short int i;
    for (i=0; i<13; ++i) {
        if (x.number==numbers[i]) return i+2;
    }
}

char NumberToSign (short int x)
{
    return numbers[x-2];
}

void PrintWinner() {
    unsigned short int i;
    for (i=0; i<n && !winner; ++i){
        if (player[i].cards==number_of_cards) winner = i+1;
    }
    if (winner) printf ("Player %d wins the game!\n\n", winner);
    else if (!winner){
        if (draw) printf ("\nIt's a draw! The %d players with the biggest cards ran out of cards to fight with in a war.\n\n", draw);
        else printf ("%d moves were made. There is no winner!\n\n", moves);
    }
}

void War() {
    printf ("\nIt's war!\n");
    unsigned short int i, j, nr[max_number_of_players], war_val[max_number_of_players], max_value = 0, war_participants = 0, incapable_to_call = 0;
    for (i=0; i<n; ++i) {
        if (participant[i]) if (max_value<val[i]) max_value = val[i];
    }
    for (i=0; i<n; ++i) {
        if (participant[i]) if (max_value==val[i]) {
            ++war_participants;
            war_val[i] = 0;
            nr[i] = val[i];
            if (nr[i]>player[i].cards) nr[i] = player[i].cards;
            printf ("Player %d: ", i+1);
            for (j=0; j<nr[i]; ++j) {
                printf ("{%c, %c}, ", player[i].card[player[i].current_card].number, player[i].card[player[i].current_card].symbol);
                if (j==nr[i]-1) war_val[i] = SignToNumber (player[i].card[player[i].current_card]);
                Push (table, player[i]);
            }
            printf ("\n");
            if (war_val[i]) val[i] = war_val[i];
            else ++incapable_to_call;
        }
    }
    if (war_participants==incapable_to_call) {
        draw = war_participants;
        PrintWinner();
        exit(EXIT_SUCCESS);
    }
}

void EstablishHandWinner() {
    unsigned short int i, hand_winner, hand_winners = 0, max_value = 0;
    for (i=0; i<n; ++i) {
        if (participant[i]) {
            printf ("%c ", NumberToSign(val[i]));
            if (max_value<val[i]) {
                max_value = val[i];
                hand_winner = i;
                hand_winners = 1;
            }
            else if (max_value == val[i]) ++hand_winners;
        }
    }
    if (hand_winners==1) {
        printf ("\nPlayer %d wins the hand.\n\n", hand_winner+1);
        Dump (player[hand_winner], table);
    }
    else if (hand_winners>1){
        War();
        EstablishHandWinner();
    }
}

void Play() {
    printf ("Starting the game...\n\n");
    unsigned short int max_cards_in_hand = number_of_cards/n;
    while (max_cards_in_hand<number_of_cards && ++moves<10000) {
        unsigned short int i;
        for (i=0; i<n; ++i){
            if (player[i].cards) {
                participant[i] = 1;
                printf ("Player %d: {%c, %c}\n", i+1, player[i].card[player[i].current_card].number, player[i].card[player[i].current_card].symbol);
                val[i] = SignToNumber (player[i].card[player[i].current_card]);
                Push (table, player[i]);
            }
            else participant[i] = 0;
        }
        EstablishHandWinner();
        for (i=0; i<n; ++i) {
            if (max_cards_in_hand<player[i].cards) max_cards_in_hand = player[i].cards;
        }
    }
}

int main()
{
    GenerateDeck();
    PrintDeck();
    ShuffleDeck();
    PrintDeck();
    printf ("Enter the number [2, 52] of players: ");
    scanf ("%d", &n);
    if (n<2 || n>52) {printf ("\nIncorrect number of players.\n"); return -1;}
    DistributeDeck();
    Play();
    PrintWinner();
    return 0;
}
