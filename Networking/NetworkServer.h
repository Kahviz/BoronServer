#pragma once
#include <enet/enet.h>

class NetworkServer
{
public:
    bool Start(int port);
    void Update();
private:
    ENetHost* m_server = nullptr;
};