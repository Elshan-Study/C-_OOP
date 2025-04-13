#include <iostream>
#include <sstream>
#include <fstream>
#include "SuperVector.h"
#include "SuperVectorT.h"
#include "Expedition.h"

//homework 28

void readExpeditions(const std::string& filename, SuperVectorT<Expedition*>& expeditions) {
    std::ifstream inFile(filename);
    std::string line;

    if (!inFile)
    {
        return;
    }

    while (getline(inFile, line)) {
        std::stringstream buffer(line);
        std::string type, name;
        int year;
        float temperature;

        std::getline(buffer, type, ';');
        std::getline(buffer, name, ';');
        buffer >> year;
        buffer.ignore();
        buffer >> temperature;

        if (type == "North") {
            expeditions.PushBack(new NorthPoleExpedition(name, year, temperature));
        }
        else if (type == "South") {
            expeditions.PushBack(new SouthPoleExpedition(name, year, temperature));
        }
    }

    inFile.close();
}

void saveExpeditions(const std::string& filename, const SuperVectorT<Expedition*>& expeditions) {
    std::ofstream outFile(filename);

    for (int i = 0; i < expeditions.Size(); ++i) {
        auto expedition = expeditions[i];
        if (dynamic_cast<NorthPoleExpedition*>(expedition)) {
            static_cast<NorthPoleExpedition*>(expedition)->saveToFile(outFile);
        }
        else if (dynamic_cast<SouthPoleExpedition*>(expedition)) {
            static_cast<SouthPoleExpedition*>(expedition)->saveToFile(outFile);
        }
    }
}

int main()
{
    SuperVectorT<Expedition*> expeditions;

    readExpeditions("expeditions.txt", expeditions);

    for (int i = 0; i < expeditions.Size(); ++i) {
        expeditions[i]->printInfo();
    }


    saveExpeditions("expeditions_out.txt", expeditions);

    for (int i = 0; i < expeditions.Size(); ++i) {
        delete expeditions[i];
    }

	return 0;
}