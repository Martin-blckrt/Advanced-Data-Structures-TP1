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

    int pTimeOut, aTimeOut, jTimeOut, tTimeOut;
    auto startTime = chrono::high_resolution_clock::now();
    auto pResumeAt = (chrono::high_resolution_clock::now() + chrono::seconds(0));
    auto aResumeAt = (chrono::high_resolution_clock::now() + chrono::seconds(0));
    auto jResumeAt = (chrono::high_resolution_clock::now() + chrono::seconds(0));
    auto tResumeAt = (chrono::high_resolution_clock::now() + chrono::seconds(0));
    bool aManufactured = false, jManufactured = false, tManufactured = false;
    Piece m;

    string axe("axe"), jupe("jupe"), tete("tete"), piston("piston");

    vector<Piece*> pieces;
    File<Piece> dock(300);

    Machine *MA, *MJ, *MT, *MP;
    MA = new Machine(150, 0);
    MJ = new Machine(180, 1);
    MT = new Machine(120, 2);
    MP = new Machine(60, 3);

    //Machine MA(150, axe), MJ(180, jupe), MT(120, tete), MP(60, piston);

    int compteurPieces = 0;
    int indexVector = 0;

    // Set random seed for order for pieces
    unsigned seed = chrono::system_clock::now()
            .time_since_epoch()
            .count();

    MA->addElemToQueue(0);
    MA->addElemToQueue(0);
    MJ->addElemToQueue(1);
    MJ->addElemToQueue(1);


    // Initialize list of pieces to manufacture
    for (int i = 0; i < 100; i++)
    {
        pieces.push_back();
        pieces.push_back(p2);
        pieces.push_back(p4);
    }

    //MA.testMethod(*p3);

    // Shuffle boxes to randomize pieces' order
    shuffle(pieces.begin(), pieces.end(), default_random_engine(seed));

    // Fill machines' queues
    for (Piece* elem : pieces)
    {
        cout << elem->getType() << endl;
        auto type = elem->getType();
        if (type == axe)
        {
            cout << "in" << endl;
            MA->addElemToQueue(*elem);
        } else if (type == jupe)
        {
            cout << "in" << endl;
            MJ->addElemToQueue(*elem);
        } else {
            cout << "in" << endl;
            MT->addElemToQueue(*elem);
        }
    }
    cout << "test" << endl;
    cout << MA->getQueueSize() << endl;
    cout << "test2" << endl;
    cout << MJ->getQueueSize() << endl;
    cout << MT->getQueueSize() << endl;



    while(compteurPieces < 100)
    {
        //dock.enfiler(pieces.at(indexVector));
        indexVector++;


        if (chrono::high_resolution_clock::now() > aResumeAt ) {
            if (aManufactured) {
                m = MA->removePiece();
                MP->addElemToQueue(m);
                aManufactured = false;
            }
            aTimeOut = MA->work();
            if (aTimeOut == 150) // a piece has started manufacturing but is going to be manufactured in aTimeOut
                aManufactured = true;
            aResumeAt = (chrono::high_resolution_clock::now() + chrono::seconds(aTimeOut));
        }

        if (chrono::high_resolution_clock::now() > jResumeAt ) {
            if (jManufactured) {
                m = MJ->removePiece();
                MP->addElemToQueue(m);
                jManufactured = false;
            }
            jTimeOut = MJ->work();
            if (jTimeOut == 180) // a piece has started manufacturing but is going to be manufactured in aTimeOut
                jManufactured = true;
            jResumeAt = (chrono::high_resolution_clock::now() + chrono::seconds(jTimeOut));
        }

        if (chrono::high_resolution_clock::now() > tResumeAt ) {
            if (tManufactured) {
                    m = MT->removePiece();
                    MP->addElemToQueue(m);
                    tManufactured = false;
                }
            tTimeOut = MT->work();
            if (tTimeOut == 120) // a piece has started manufacturing but is going to be manufactured in aTimeOut
                tManufactured = true;
            tResumeAt = (chrono::high_resolution_clock::now() + chrono::seconds(tTimeOut));
        }

        if (chrono::high_resolution_clock::now() > pResumeAt ) {
            pTimeOut = MP->work();
            if (pTimeOut == 60) // a piece has started manufacturing but is going to be manufactured in aTimeOut
                compteurPieces++;
            pResumeAt = (chrono::high_resolution_clock::now() + chrono::seconds(pTimeOut));
        }

    }*/

    return 0;
}
