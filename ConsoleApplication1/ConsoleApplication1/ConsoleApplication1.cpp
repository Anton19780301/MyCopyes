#include <iostream>
#include <stack>
#include <list>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <string>
#include <numeric>
#include <time.h>
#include <fstream>
#include <iomanip>

#include <chrono>
#include <thread>

class Opel {
public:
    Opel() {};
    Opel(int a = 0, std::string b = "") {
        age = a;
        name = b;
    };
    ~Opel() {};
    int getAge() { return age; }
    std::string getName() { return name; }
    void corrupt(int iter, int& rand)
    {
        std::cout << "Begin corrupt" << std::endl;
        for (int x = 0; x < iter; x++)
        {
            rand = x;
            std::cout << std::internal << std::setfill('_');
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
            std::cout << "|" << std::setw(3) << x << " " << std::setw(3) << iter << " " << std::setw(8) << std::this_thread::get_id() << "|" << std::endl;
        }
    }

private:
    int age = 0;
    std::string name = "";
};


int main()
{
    std::stack<int> st;
    int rand = 0;
    Opel opel (0,"Anton");

    auto lamer = [&rand,&opel]() {
        std::cout << "Begin lamer" << std::endl;
        opel.corrupt(100, rand);
    };

    std::thread tr01(lamer);

    auto lambada = [&rand]() {
        std::cout << "Begin lambada" << std::endl;
        for (int x = 0; x < 100; x++)
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
            std::cout << rand++ << " " << std::this_thread::get_id() << std::endl;
        }
    };

    std::thread tr02(lambada);

    for (int x = 0;x < 150;++x)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(80));
        st.push(rand);
    }

    tr01.join();
    tr02.join();

    std::cout << "\n-----------------------------\n" << std::endl;

    std::ofstream ofs;
    try
    {
        ofs.open("open.txt");
        if (ofs.is_open())
        {
            std::cout << "\nfile open\n" << std::endl;
            while (!st.empty())
            {
                ofs << st.top() << " ";
                st.pop();
            }
        }
        else
        {
            std::cout << "file not open" << std::endl;
        }
        ofs.close();
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    std::queue<std::string> ue = {};

    std::ifstream ifs;
    try 
    {
        ifs.open("open.txt");
        if (ifs.is_open())
        {
            std::string ass;
            while (!ifs.eof())
            {
                ass.clear();
                std::getline(ifs,ass);
                ue.push(ass);
            }
        }
        else
        {
            std::cout << "file not open" << std::endl;
        }
        ifs.close();
    
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    while (!ue.empty())
    {
        std::cout << ue.front();
        ue.pop();
    }

    return 0;
}