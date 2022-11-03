#include <iostream>
#include <string>
#include <vector>
#include <functional>

using namespace std;

class Swarm;

class PiouPiou
{
    int i;
public:
    PiouPiou(int i) : i{i} {}

    friend Swarm;
};

class Swarm
{
    vector<PiouPiou> pioupious;
public:
    Swarm()
    {
        for (int i = 0; i < 100; i++)
        {
            pioupious.push_back(PiouPiou(i));
        }
    }

    void action(function<int(int)> callback)
    {
        for (auto &p : collection.pioupious)
        {
            p.i = callback(p.i);
        }
    }
};

int global_sum = 0;
int count(int v){
    sum += v;
    return v;
}

int main()
{
    Swarm collection;
    //
    collection.action([](int v){
        return v + 1
    });

    collection.action(count);

    int sum = 0;
    collection.action([&sum](int v){
        sum += v;
        return v;
    });
}
