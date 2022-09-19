#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include "File.h"
#include "Piece.h"
#include "Machine.h"

using namespace std;

int main() {

    // Declare variables
    srand(time(nullptr));

    double pTimeOut = 0, aTimeOut = 0, jTimeOut = 0, tTimeOut = 0;
    auto startTime = chrono::high_resolution_clock::now();
    auto pResumeAt = (chrono::high_resolution_clock::now() + chrono::seconds(0));
    auto aResumeAt = (chrono::high_resolution_clock::now() + chrono::seconds(0));
    auto jResumeAt = (chrono::high_resolution_clock::now() + chrono::seconds(0));
    auto tResumeAt = (chrono::high_resolution_clock::now() + chrono::seconds(0));
    bool aManufactured = false, jManufactured = false, tManufactured = false;
    Piece m;

    string axe("axe"), jupe("jupe"), tete("tete"), piston("piston");

    vector<Piece> pieces;
    File<Piece> dock(300);

    Machine *MA, *MJ, *MT, *MP;
    MA = new Machine(2.5, 0);
    MJ = new Machine(3, 1);
    MT = new Machine(2, 2);
    MP = new Machine(1, 3);

    int compteurPieces = 0;
    int indexVector = 0;

    // Set random seed for order for pieces
    unsigned seed = chrono::system_clock::now()
            .time_since_epoch()
            .count();


    // Initialize list of pieces to manufacture
    for (int i = 0; i < 100; i++)
    {
        pieces.emplace_back(Piece(0));
        pieces.emplace_back(Piece(1));
        pieces.emplace_back(Piece(2));
    }

    // Shuffle boxes to randomize pieces' order
    shuffle(pieces.begin(), pieces.end(), default_random_engine(seed));
    // Fill machines' queues
    for (auto elem : pieces)
    {
        if (elem.getType() == 0) {
            MA->addElemToQueue(elem);
        } else if (elem.getType() == 1)
        {
            MJ->addElemToQueue(elem);
        } else if (elem.getType() == 2)
        {
            MT->addElemToQueue(elem);
        } else
        {
            MP->addElemToQueue(elem);
        }
    }

    while(compteurPieces < 100) {

        // if the time is bigger (later) than the timeout time
        if (chrono::high_resolution_clock::now() > aResumeAt) {
            if (aManufactured) { // if a piece was manufactured
                m = MA->removePiece(); // remove it from the machine
                MP->addElemToQueue(m); // add it to the piston machine
                aManufactured = false; // set back to false
            }
            aTimeOut = MA->work(); // try to work on machine, returns exec time or breakdown time
            if (aTimeOut == 2.5) // a piece has started manufacturing but is going to be manufactured in aTimeOut
                aManufactured = true;
            aResumeAt = (chrono::high_resolution_clock::now() + chrono::milliseconds(2500)); // set the machine to resume later
        }

        if (chrono::high_resolution_clock::now() > jResumeAt) {
            if (jManufactured) {
                m = MJ->removePiece();
                MP->addElemToQueue(m);
                jManufactured = false;
            }
            jTimeOut = MJ->work();
            if (jTimeOut == 3) // a piece has started manufacturing but is going to be manufactured in aTimeOut
                jManufactured = true;
            jResumeAt = (chrono::high_resolution_clock::now() + chrono::milliseconds(3000));
        }

        if (chrono::high_resolution_clock::now() > tResumeAt) {
            if (tManufactured) {
                m = MT->removePiece();
                MP->addElemToQueue(m);
                tManufactured = false;
            }
            tTimeOut = MT->work();
            if (tTimeOut == 2)
                tManufactured = true;
            tResumeAt = (chrono::high_resolution_clock::now() + chrono::milliseconds(2000));
        }

        if (chrono::high_resolution_clock::now() > pResumeAt) {
            pTimeOut = MP->work();
            if (pTimeOut == 1)
                compteurPieces++;
            pResumeAt = (chrono::high_resolution_clock::now() + chrono::milliseconds(1000));
        }

    }

    auto endTime = chrono::high_resolution_clock::now();

    std::chrono::duration<double> diff = endTime - startTime;
    double time_ms = diff.count();

    cout << "Time to produce 100 pistons : " << int(time_ms / 60) << "min and " << int(time_ms) % 60 << "s" << endl;

    return 0;
}
