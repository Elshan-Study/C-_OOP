#include <iostream>
#include <sstream>
#include <fstream>
#include <memory>
#include "SuperVector.h"
#include "SuperVectorT.h"
#include "Expedition.h"
#include "Directory.h"
#include "LinkedList.h"
#include "HashTable.h"
#include "Stack.h"
#include "Queue.h"
#include "PriorityQueue.h"

//homework 28

//void readExpeditions(const std::string& filename, SuperVectorT<Expedition*>& expeditions) {
//    std::ifstream inFile(filename);
//    std::string line;
//
//    if (!inFile)
//    {
//        return;
//    }
//
//    while (getline(inFile, line)) {
//        std::stringstream buffer(line);
//        std::string type, name;
//        int year;
//        float temperature;
//
//        std::getline(buffer, type, ';');
//        std::getline(buffer, name, ';');
//        buffer >> year;
//        buffer.ignore();
//        buffer >> temperature;
//
//        if (type == "North") {
//            expeditions.PushBack(new NorthPoleExpedition(name, year, temperature));
//        }
//        else if (type == "South") {
//            expeditions.PushBack(new SouthPoleExpedition(name, year, temperature));
//        }
//    }
//
//    inFile.close();
//}
//
//void saveExpeditions(const std::string& filename, const SuperVectorT<Expedition*>& expeditions) {
//    std::ofstream outFile(filename);
//
//    for (int i = 0; i < expeditions.Size(); ++i) {
//        auto expedition = expeditions[i];
//        if (dynamic_cast<NorthPoleExpedition*>(expedition)) {
//            static_cast<NorthPoleExpedition*>(expedition)->saveToFile(outFile);
//        }
//        else if (dynamic_cast<SouthPoleExpedition*>(expedition)) {
//            static_cast<SouthPoleExpedition*>(expedition)->saveToFile(outFile);
//        }
//    }
//}
//
//int main()
//{
//    SuperVectorT<Expedition*> expeditions;
//
//    readExpeditions("expeditions.txt", expeditions);
//
//    for (int i = 0; i < expeditions.Size(); ++i) {
//        expeditions[i]->printInfo();
//    }
//
//
//    saveExpeditions("expeditions_out.txt", expeditions);
//
//    for (int i = 0; i < expeditions.Size(); ++i) {
//        delete expeditions[i];
//    }
//
//	return 0;
//}


//homework 29

//void write_to_file(const std::string file_name, Directory*& array, size_t& size)
//{
//    std::ofstream out(file_name, std::ios::binary);
//
//    if (!out.is_open())
//    {
//        throw std::runtime_error("Cannot open file");
//    }
//
//    out.write(reinterpret_cast<const char*>(&size), sizeof(size_t));
//
//    for (size_t i = 0; i < size; i++)
//    {
//        size_t string_size = array[i].getFirmName().size();
//        out.write(reinterpret_cast<char*>(&string_size), sizeof(size_t));
//        out.write(array[i].getFirmName().data(), string_size);
//
//        string_size = array[i].getOwner().size();
//        out.write(reinterpret_cast<char*>(&string_size), sizeof(size_t));
//        out.write(array[i].getOwner().data(), string_size);
//
//        string_size = array[i].getPhone().size();
//        out.write(reinterpret_cast<char*>(&string_size), sizeof(size_t));
//        out.write(array[i].getPhone().data(), string_size);
//
//        string_size = array[i].getAddress().size();
//        out.write(reinterpret_cast<char*>(&string_size), sizeof(size_t));
//        out.write(array[i].getAddress().data(), string_size);
//
//        string_size = array[i].getOccupation().size();
//        out.write(reinterpret_cast<char*>(&string_size), sizeof(size_t));
//        out.write(array[i].getOccupation().data(), string_size);
//    }
//   
//    out.close();
//}
//
//void read_from_file(std::string file_name, Directory*& array, size_t& size)
//{
//    std::ifstream in(file_name, std::ios::binary);
//
//    if (!in.is_open())
//    {
//        throw std::runtime_error("Cannot open file");
//    }
//
//    in.read(reinterpret_cast<char*>(&size), sizeof(size_t));
//
//    for (size_t i = 0; i < size; i++)
//    {
//        size_t string_size;
//
//        in.read(reinterpret_cast<char*>(&string_size), sizeof(size_t));
//        array[i].getFirmName().resize(string_size);
//        in.read(&array[i].getFirmName()[0], string_size);
//
//        in.read(reinterpret_cast<char*>(&string_size), sizeof(size_t));
//        array[i].getOwner().resize(string_size);
//        in.read(&array[i].getOwner()[0], string_size);
//
//        in.read(reinterpret_cast<char*>(&string_size), sizeof(size_t));
//        array[i].getPhone().resize(string_size);
//        in.read(&array[i].getPhone()[0], string_size);
//
//        in.read(reinterpret_cast<char*>(&string_size), sizeof(size_t));
//        array[i].getAddress().resize(string_size);
//        in.read(&array[i].getAddress()[0], string_size);
//
//        in.read(reinterpret_cast<char*>(&string_size), sizeof(size_t));
//        array[i].getOccupation().resize(string_size);
//        in.read(&array[i].getOccupation()[0], string_size);
//    }
//
//    in.close();
//
//}
//
//void print_directory(Directory& d)
//{
//    std::cout << "Firm Name: " << d.getFirmName() << "\n";
//    std::cout << "Owner: " << d.getOwner() << "\n";
//    std::cout << "Phone: " << d.getPhone() << "\n";
//    std::cout << "Address: " << d.getAddress() << "\n";
//    std::cout << "Occupation: " << d.getOccupation() << "\n";
//    std::cout << "-----------------------------\n";
//}
//
//void search_by_field(Directory* data, size_t size, const std::string& query, const std::string& field)
//{
//    bool found = false;
//    for (size_t i = 0; i < size; ++i)
//    {
//        std::string value;
//        if (field == "firm") value = data[i].getFirmName();
//        else if (field == "owner") value = data[i].getOwner();
//        else if (field == "phone") value = data[i].getPhone();
//        else if (field == "occupation") value = data[i].getOccupation();
//        else continue;
//
//        if (value.find(query) != std::string::npos)
//        {
//            print_directory(data[i]);
//            found = true;
//        }
//    }
//    if (!found) std::cout << "No matches found.\n";
//}
//
//void add_entry(Directory*& data, size_t& size)
//{
//    std::string firm, owner, phone, address, occupation;
//    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//
//    std::cout << "Enter firm name: "; std::getline(std::cin, firm);
//    std::cout << "Enter owner name: "; std::getline(std::cin, owner);
//    std::cout << "Enter phone number: "; std::getline(std::cin, phone);
//    std::cout << "Enter address: "; std::getline(std::cin, address);
//    std::cout << "Enter occupation: "; std::getline(std::cin, occupation);
//
//    Directory* new_data = new Directory[size + 1];
//    for (size_t i = 0; i < size; ++i)
//        new_data[i] = data[i];
//
//    new_data[size] = Directory(firm, owner, phone, address, occupation);
//
//    delete[] data;
//    data = new_data;
//    ++size;
//}
//
//void show_all(Directory* data, size_t size)
//{
//    if (size == 0)
//    {
//        std::cout << "Directory is empty.\n";
//        return;
//    }
//
//    for (size_t i = 0; i < size; ++i)
//        print_directory(data[i]);
//}
//
//void show_menu()
//{
//    std::cout << "\n=== Directory Menu ===\n";
//    std::cout << "1. Search by Firm Name\n";
//    std::cout << "2. Search by Owner\n";
//    std::cout << "3. Search by Phone\n";
//    std::cout << "4. Search by Occupation\n";
//    std::cout << "5. Show All Records\n";
//    std::cout << "6. Add New Record\n";
//    std::cout << "0. Exit\n";
//    std::cout << "Choose an option: ";
//}
//
//int main()
//{
//    Directory* directory = new Directory[10];
//    size_t size = 0;
//    read_from_file("hw29.txt", directory, size);
//
//    char choice;
//    while (true)
//    {
//        show_menu();
//        std::cin >> choice;
//
//        switch (choice-48)
//        {
//        case 1:
//        {
//            std::string query;
//            std::cout << "Enter firm name to search: ";
//            std::cin.ignore(); std::getline(std::cin, query);
//            search_by_field(directory, size, query, "firm");
//            break;
//        }
//        case 2:
//        {
//            std::string query;
//            std::cout << "Enter owner name to search: ";
//            std::cin.ignore(); std::getline(std::cin, query);
//            search_by_field(directory, size, query, "owner");
//            break;
//        }
//        case 3:
//        {
//            std::string query;
//            std::cout << "Enter phone number to search: ";
//            std::cin.ignore(); std::getline(std::cin, query);
//            search_by_field(directory, size, query, "phone");
//            break;
//        }
//        case 4:
//        {
//            std::string query;
//            std::cout << "Enter occupation to search: ";
//            std::cin.ignore(); std::getline(std::cin, query);
//            search_by_field(directory, size, query, "occupation");
//            break;
//        }
//        case 5:
//            show_all(directory, size);
//            break;
//        case 6:
//            add_entry(directory, size);
//            write_to_file("hw29.txt", directory, size);
//            break;
//        case 0:
//            std::cout << "Exiting...\n";
//            delete[] directory;
//            return 0;
//        default:
//            std::cout << "Invalid choice. Try again.\n";
//            break;
//        }
//    }
//}

//homework 30
//int main()
//{
//    LinkedList<int> list;
//
//    std::cout << "InsertAtEnd: ";
//    list.InsertAtEnd(10);
//    list.InsertAtEnd(20);
//    list.InsertAtEnd(30);
//    list.PrintForward(); 
//
//    std::cout << "InsertAfter (25 after 20): ";
//    LinkedListNode<int>* node20 = list.GetHead()->My_Next;
//    list.InsertAfter(25, node20);
//    list.PrintForward(); 
//
//    std::cout << "Remove (25): ";
//    list.Remove(node20->My_Next);
//    list.PrintForward(); 
//
//    std::cout << "PopFront: ";
//    list.PopFront();
//    list.PrintForward(); 
//
//    std::cout << "PopBack: ";
//    list.PopBack();
//    list.PrintForward();
//
//    std::cout << "Empty: " << std::boolalpha << list.Empty() << "\n"; 
//
//    std::cout << "Clear: ";
//    list.Clear();
//    std::cout << "After Clear, Empty: " << list.Empty() << "\n";
//
//    std::cout << "InsertAtEnd x3 (1 2 3): ";
//    list.InsertAtEnd(1);
//    list.InsertAtEnd(2);
//    list.InsertAtEnd(3);
//    list.PrintForward(); 
//
//    std::cout << "Reverse: ";
//    list.Reverse();
//    list.PrintForward(); 
//
//    std::cout << "Testing copy constructor:\n";
//    LinkedList<int> copyList(list);
//    copyList.PrintForward(); 
//
//    std::cout << "Testing move constructor:\n";
//    LinkedList<int> movedList(std::move(copyList));
//    movedList.PrintForward(); 
//
//    std::cout << "Testing copy assignment:\n";
//    LinkedList<int> assignList;
//    assignList = list;
//    assignList.PrintForward(); 
//
//    std::cout << "Testing move assignment:\n";
//    LinkedList<int> moveAssignList;
//    moveAssignList = std::move(assignList);
//    moveAssignList.PrintForward(); 
//
//    return 0;
//}

//homework 31
//int main()
//{
//    LinkedList<int> list;
//
//    list.InsertAtEnd(10);
//    list.InsertAtEnd(20);
//    list.InsertAtEnd(30);
//    list.InsertAtEnd(40);
//
//    std::cout << "List with iterator: ";
//    for (auto value : list)
//    {
//        std::cout << value << " ";
//    }
//    std::cout << "\n";
//
//    auto it = list.begin();
//    std::cout << "First element: " << *it << "\n";         
//    std::cout << "Second element (it + 1): " << *(it + 1) << "\n"; 
//    std::cout << "Back (it + 2 - 1): " << *((it + 2) - 1) << "\n"; 
//
//    return 0;
//}

//homework 32
//int main() {
//    HashTable<std::string, int> table(8);
//
//    table.Add("apple", 10);
//    table.Add("banana", 20);
//    table.Add("cherry", 30);
//
//    std::cout << "apple: " << table("apple") << std::endl;
//    std::cout << "banana: " << table("banana") << std::endl;
//
//    table.Add("banana", 25);
//    std::cout << "banana (updated): " << table("banana") << std::endl;
//
//    table.Remove("apple");
//
//    try {
//        std::cout << "apple: " << table("apple") << std::endl;
//    }
//    catch (const std::out_of_range& e) {
//        std::cout << "Exception caught: " << e.what() << std::endl;
//    }
//
//    std::cout << "Load factor: " << table.GetLoadFactor() << std::endl;
//
//    HashTable<std::string, int> table2(4);
//
//    table2.Add("a", 1);
//    table2.Add("b", 2);
//    table2.Add("c", 3);
//    table2.Add("d", 4); // Rehash
//    table2.Add("e", 5);
//
//    std::cout << "Load factor: " << table2.GetLoadFactor() << "\n";
//    std::cout << "d = " << table2("d") << ", e = " << table2("e") << "\n";
//
//    return 0;
//}

//homework 33_1
//bool IsBracketSequenceCorrect(const std::string& str) {
//    Stack<char> stack;
//
//    for (char ch : str) {
//        if (ch == '(' || ch == '{' || ch == '[') {
//            stack.Push(ch);
//        }
//        else if (ch == ')' || ch == '}' || ch == ']') {
//            if (stack.Empty()) return false;
//
//            char top = stack.Pop();
//            if ((ch == ')' && top != '(') ||
//                (ch == '}' && top != '{') ||
//                (ch == ']' && top != '[')) {
//                return false;
//            }
//        }
//    }
//
//    return stack.Empty(); 
//}
//
//int main() {
//    // Stack demo
//    Stack<int> intStack;
//    intStack.Push(10);
//    intStack.Push(20);
//    intStack.Push(30);
//
//    PrintStack(intStack);
//
//    std::cout << "Top element: " << intStack.Top() << '\n';
//    std::cout << "Popped element: " << intStack.Pop() << '\n';
//
//    PrintStack(intStack);
//
//    // Bracket checking
//    std::string expr1 = "(1{2[test]})";
//    std::string expr2 = "(1{2[test}])";
//
//    std::cout << "Expr1 is " << (IsBracketSequenceCorrect(expr1) ? "OK" : "NOT OK") << '\n';
//    std::cout << "Expr2 is " << (IsBracketSequenceCorrect(expr2) ? "OK" : "NOT OK") << '\n';
//
//    return 0;
//}


//homework 33_2
//int main() {
//    Queue<int> q;
//    q.Enqueue(1);
//    q.Enqueue(2);
//    q.Enqueue(3);
//    std::cout << "Queue: " << q << std::endl;
//
//    PriorityQueue<int, Less<int>> minHeap;
//    minHeap.Enqueue(4);
//    minHeap.Enqueue(2);
//    minHeap.Enqueue(9);
//    minHeap.Enqueue(1);
//
//    std::cout << "MinHeap: " << minHeap << std::endl;
//
//    PriorityQueue<int, Greater<int>> maxHeap;
//    maxHeap.Enqueue(4);
//    maxHeap.Enqueue(2);
//    maxHeap.Enqueue(9);
//    maxHeap.Enqueue(1);
//
//    std::cout << "MaxHeap: " << maxHeap << std::endl;
//
//    return 0;
//}
