#include <iostream>
#include "SuperVector.h"
#include "SuperVectorT.h"
#include "Animal.h"
#include "Zoo.h"
#include "UniquePtr.h"
#include "SharedPtr.h"
#include "Figure.h"
#include "FileViewer.h"

void DisplayVector(const SuperVector& vector)
{
	for (size_t i = 0; i < vector.Size(); i++)
	{
		std::cout << vector.Get(i) << " ";
	}
};

void DrawBoard(Figure* figure)
{
	std::cout << "  a b c d e f g h\n";
	for (int r = 8; r >= 1; --r) {
		std::cout << r << " ";
		for (char c = 'a'; c <= 'h'; ++c) {
			if (figure && figure->GetCol() == c && figure->GetRow() == r)
				std::cout << figure->GetSkin() << " ";
			else
				std::cout << ". ";
		}
		std::cout << "\n";
	}
};

bool IsValidCoord(char col, int row) {
	return col >= 'a' && col <= 'h' && row >= 1 && row <= 8;
};
//
//int main() {
//	/*homework 19*/
//
//	/*SuperVector v(3);
//	SuperVector v2(3);
//	v[0] = 1;
//	v[1] = 3;
//	v[2] = 5;
//	v2[0] = 2;
//	v2[1] = 4;
//	v2[2] = 0;
//	SuperVector v3(v/v2);
//
//	DisplayVector(v3);
//	std::cout << std::endl;*/
//
//	/*homework 20*/
//	//SuperVector v1(3);
//	//SuperVector v2(4);
//
//	//std::cout << "Vector 1: \n";
//	//std::cin >> v1; 
//	//std::cout << v1;
//	///*std::cout << "Vector 2: \n";
//	//std::cin >> v2;
//	//std::cout << v2;*/
//	//std::cout << v1--;
//	//std::cout << v1;
//
//	/*homework 21*/
//	//ZooWorker caretaker("John Doe", 5);
//	//Enclosure enclosure("Savannah", 3, caretaker);
//	//Mammal* animal_1 = new Mammal("Lion", 5, 150.0, 1);
//	//Mammal* animal_2 = new Mammal("Elephant", 10, 500.0, 0);
//	//Reptile* animal_3 = new Reptile("Crocodile", 10, 100.0, 0);
//	//enclosure.addAnimal(animal_1);
//	//enclosure.addAnimal(animal_2);
//	//enclosure.addAnimal(animal_3);
//
//	////std::cout << enclosure;
//	///*enclosure.printEnclosureInfo();
//
//	//enclosure.removeAnimal(0);
//	//enclosure.printEnclosureInfo();*/
//
//	//Zoo zoo;
//	//zoo.addEnclosure(enclosure);
//	//std::cout << zoo;
//
//	/*homework 22*/
//
//	/*SuperVectorT <double> vectorT({ 11, 66, 55 });
//	SuperVectorT <double> vectorT2({ 5, 6.8, 45 });
//
//	SuperVectorT <double> vectorT3 = vectorT + vectorT2;
//	std::cout << vectorT3[5] << "\n";
//
//	vectorT += vectorT3;
//
//	std::cout << vectorT.Size();*/
//
//	/*homework 23*/
//
//	/*UniquePtr<int> ptr(new int(5));
//
//	std::cout << ptr.get() << "\n";
//	std::cout << *ptr << "\n";
//
//	ptr.reset(new int(354));
//	std::cout << *ptr.get() << "\n";
//
//
//	size_t n{ 5 };
//	UniquePtr<int>pnumbers(new int[5] {1, 2, 3, 4, 5}, true);
//
//	pnumbers[2] = 23;
//	std::cout << pnumbers[2]; 
//
//	SharedPtr<int> arrayPtr(new int[5] {1, 2, 3, 4, 5}, true);
//	std::cout << "arrayPtr[2]: " << arrayPtr[2] << ", use_count: " << arrayPtr.use_count() << std::endl;*/
//

/*lesson 24*/
//int main() {
//    Figure* figure = nullptr; 
//
//    while (true) {
//        std::cout << "\nChoose figure: \n";
//        std::cout << "1. White Pawn\n";
//        std::cout << "2. Black Pawn\n";
//        std::cout << "3. White Knight\n";
//        std::cout << "4. Black Knight\n";
//        std::cout << "5. White Bishop\n";
//        std::cout << "6. Black Bishop\n";
//        std::cout << "7. White Rook\n";
//        std::cout << "8. Black Rook\n";
//        std::cout << "9. White Queen\n";
//        std::cout << "10. Black Queen\n";
//        std::cout << "11. White King\n";
//        std::cout << "12. Black King\n";
//        std::cout << "0. Exit\n";
//
//        int choice;
//        std::cin >> choice;
//
//        if (choice == 0)
//            break;
//
//        if (figure != nullptr)
//            delete figure;
//
//        switch (choice)
//        {
//        case 1: figure = new Pawn('e', 2, false); break;
//        case 2: figure = new Pawn('e', 7, true); break;
//        case 3: figure = new Knight('b', 1, false); break;
//        case 4: figure = new Knight('b', 8, true); break;
//        case 5: figure = new Bishop('c', 1, false); break;
//        case 6: figure = new Bishop('c', 8, true); break;
//        case 7: figure = new Rook('a', 1, false); break;
//        case 8: figure = new Rook('a', 8, true); break;
//        case 9: figure = new Queen('d', 1, false); break;
//        case 10: figure = new Queen('d', 8, true); break;
//        case 11: figure = new King('e', 1, false); break;
//        case 12: figure = new King('e', 8, true); break;
//        default: continue;
//        }
//
//        while (true) {
//            DrawBoard(figure);
//            std::cout << "\nEnter coordinate (e.g. e4), 0 - exit: ";
//            char input[3];
//            std::cin >> input;
//
//            if (input[0] == '0')
//                break;
//
//            char col = input[0];
//            int row = input[1] - '0';
//
//            if (!IsValidCoord(col, row)) {
//                std::cout << "Incorrect coordinates\n";
//                continue;
//            }
//
//            figure->move(col, row);
//        }
//    }
//
//    if (figure != nullptr)
//        delete figure;
//
//    return 0;
//}

/*homework 25*/
//int main() {
//    const char* path = "example.txt";
//
//    try {
//        std::unique_ptr<FileViewer> viewer;
//
//        viewer = std::make_unique<TextViewer>();
//        std::cout << "[TextViewer]\n";
//        viewer->Display(path);
//
//        viewer = std::make_unique<AsciiViewer>();
//        std::cout << "\n[AsciiViewer]\n";
//        viewer->Display(path);
//
//        viewer = std::make_unique<BinaryViewer>();
//        std::cout << "\n[BinaryViewer]\n";
//        viewer->Display(path);
//
//    }
//    catch (const FileException& ex) {
//        std::cerr << ex.what() << '\n';
//        return 1;
//    }
//
//    return 0;
//}