#include "Networking/NetworkServer.h"

#include <enet/enet.h>
#include <iostream>
#include <thread>
#include <chrono>

int main()
{
    NetworkServer server;

    if (!server.Start(25555))
    {
        std::cout << "Server failed!\n";
        return 1;
    }

    std::cout << "Server started!\n";

    while (true)
    {
        server.Update();
    }

    return 0;
}