// SingletonDemo.cpp: 定义应用程序的入口点。
//

#include <iostream>
#include <vector>
#include <mutex>
#include "singleton.h"

using namespace std;

#include <thread>
#include <iostream>

class MySingleton : public CppCommon::Singleton<MySingleton>
{
    friend CppCommon::Singleton<MySingleton>;

public:
    void Test() {
        std::lock_guard<mutex> mylockguard(mtx);
        if(ticketNums > 0)
        {
            std::cout << "当前还有余票:" << ticketNums << std::endl;
            ticketNums--;
            std::cout << "售出一张票, 当前还有余票:" << ticketNums << std::endl;
        }
        else std::cout << "卖完了" << std::endl;
    }

private:
    MySingleton() { std::cout << "MySingleton::MySingleton()" << std::endl; }
    ~MySingleton() { std::cout << "MySingleton::~MySingleton()" << std::endl; }

    int ticketNums = 1000;
    std::mutex mtx;
};
void ThreadSafeTest()
{
    for (int i = 0; i < 230 ; ++i)
    {
        MySingleton::GetInstance().Test();
    }
}
int main(int argc, char** argv)
{
    // 测试构造函数
    //MySingleton::GetInstance().Test();
    //MySingleton single;

    // 测试拷贝构造
    //MySingleton copy = MySingleton::GetInstance(); // This should fail

    // 测试赋值
    //MySingleton& ref = MySingleton::GetInstance(); // This is allowed
    //MySingleton assign;
    //assign = MySingleton::GetInstance(); // This should fail

    //线程安全测试
    std::vector<std::thread> threads;
    for (int i = 0; i < 5; ++i)
        threads.emplace_back(ThreadSafeTest);

    for (auto& t : threads)
        t.join();

    //MySingleton::GetInstance().Test();
    getchar();
    return 0;
}
