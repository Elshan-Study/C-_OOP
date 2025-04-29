#include <iostream>
#include <map>
#include <set>
#include <unordered_map>

class Account
{
public:
    friend std::ostream& operator<<(std::ostream& os, const Account& Account)
    {
        os << Account.My_Login << "|" << Account.My_Password;

        return os;
    }

    std::string My_Id;
    std::string My_Login;
    std::string My_Password;

    bool operator<(const Account& Account) const
    {
        return My_Id < Account.My_Id;
    }

    bool operator==(const Account& Account) const
    {
        return My_Id == Account.My_Id;
    }

    bool operator>(const Account& Account) const
    {
        return !operator<(Account);
    }
};

std::tuple<int, Account> GetTuple()
{
    return { 42, Account{} };
}

void GetMany(int& first, int& second)
{
    first = 42;
    second = 13;
}

//int main(int argc, char* argv[])
//{
//    //// Containers
//    // std::vector<T> - dynamic array
//    // std::list<T> - linked list
//    // std::queue<T> - queue
//    // std::stack<T> - stack
//    // std::deqeue<T> - double ended queue
//    // std::priority_queue<T> - priority queue
//    // std::map<K, V> - binary tree
//    // std::multimap<K, V> - binary tree (with dups)
//    // std::unordered_map<K, V> - hash table
//    // std::unordered_multimap<K, V> - hash table (with dups)
//    // std::set<T> - binary tree
//    // std::multiset<T> - binary tree (with dups)
//    // std::unordered_set<T> - hash table
//    // std::unordered_multiset<T> - hash table (with dups)
//
//    // 
//    //// std::map, std::multimap, std::unordered_map 
//    // {
//    //     // std::map<std::string, Account> Accounts;
//    //     std::unordered_multimap<std::string, Account> Accounts;
//    //
//    //     Account Acc1{
//    //         "bc58e3fc-9071-4bb9-9b1b-736e3c77b7b2",
//    //         "XXX__pro100_nagibator__XXX",
//    //         "parol_nagibatora"
//    //     };
//    //             
//    //     Account Acc2{
//    //         "74b1ce01-5da0-4304-b063-5606296cada8",
//    //         "LOX_1337",
//    //         "parol123"
//    //     };
//    //
//    //     Account Acc3{
//    //         "cbc5ebc7-410f-4e34-845a-6a328cb4ad20",
//    //         "aaaaaaaaaaaaaaaaaaaaaa",
//    //         "qwertyuiop-asdfgh"
//    //     };
//    //
//    //     Account Acc3Dup{
//    //         "cbc5ebc7-410f-4e34-845a-6a328cb4ad20",
//    //         "bbbbbbbbbbbbbbbbbbbb",
//    //         "1234567"
//    //     };
//    //
//    //     Account Acc3Dup2{
//    //         "cbc5ebc7-410f-4e34-845a-6a328cb4ad20",
//    //         "cccccccccccc",
//    //         "qwerty"
//    //     };
//    //
//    //
//    //     //// not available in std::multimap and std::unordered_multimap 
//    //     // Accounts[Acc1.My_Id] = Acc1; // std::pair<std::string, Account>
//    //     // Accounts[Acc2.My_Id] = Acc2; // std::pair<std::string, Account>
//    //
//    //     Accounts.insert({Acc1.My_Id, Acc1});
//    //     Accounts.insert({Acc2.My_Id, Acc2});
//    //     
//    //     Accounts.insert({Acc3.My_Id, Acc3});
//    //     Accounts.insert({Acc3Dup.My_Id, Acc3Dup});
//    //     Accounts.insert({Acc3Dup2.My_Id, Acc3Dup2});
//    //
//    //     for (auto& Pair : Accounts)
//    //     {
//    //         std::cout << "key = " << Pair.first << '\n';
//    //         std::cout << "value = " << Pair.second << '\n';
//    //     }
//    //
//    //     std::cout << "Acc3.My_Id count = " << Accounts.count(Acc3.My_Id) << '\n';
//    //
//    //     auto PairIt = Accounts.equal_range(Acc3.My_Id);
//    //     auto& Begin = PairIt.first;
//    //     const auto& End = PairIt.second;
//    //     
//    //     std::cout << "Duplicates: " << '\n';
//    //     
//    //     while (Begin != End)
//    //     {
//    //         auto& Pair = *Begin;
//    //
//    //         std::cout << "[PairDup] key = " << Pair.first << '\n';
//    //         std::cout << "[PairDup] value = " << Pair.second << '\n';
//    //         
//    //         ++Begin;
//    //     }
//    // }
//
//    //// std::set
////    {
////        std::set<Account, std::greater<Account>> Accounts;
////
////        Account Acc1{
////            "bc58e3fc-9071-4bb9-9b1b-736e3c77b7b2",
////            "XXX__pro100_nagibator__XXX",
////            "parol_nagibatora"
////        };
////
////        Account Acc2{
////            "74b1ce01-5da0-4304-b063-5606296cada8",
////            "LOX_1337",
////            "parol123"
////        };
////
////        Account Acc3{
////            "cbc5ebc7-410f-4e34-845a-6a328cb4ad20",
////            "aaaaaaaaaaaaaaaaaaaaaa",
////            "qwertyuiop-asdfgh"
////        };
////
////        Accounts.insert(Acc1);
////        Accounts.insert(Acc2);
////        Accounts.insert(Acc3);
////
////        // auto FoundIt = std::find(Accounts.begin(), Accounts.end(), [](const Account& Account)
////        // {
////        //     return Account.My_Id == "74b1ce01-5da0-4304-b063-5606296cada8";
////        // });
////        //
////        // std::cout << "found Id = " << FoundIt->My_Id << '\n';
////        // std::cout << "found Login = " << FoundIt->My_Login << '\n';
////        // std::cout << "found Password = " << FoundIt->My_Password << '\n';
////
////        // for (auto& account : Accounts)
////        // {
////        //     std::cout << account << '\n';
////        // }
////    }
////
////    //// std::tuple
////    {
////        auto MyTuple = GetTuple();
////        int Value = std::get<0>(MyTuple); // 42
////        Account Acc = std::get<1>(MyTuple); // 42
////
////        int First;
////        int Second;
////
////        GetMany(First, Second);
////
////        std::cout << First << " " << Second << '\n';
////    }
////
////    return 0;
////}
