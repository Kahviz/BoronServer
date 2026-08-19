#include "NetworkServer.h"
#include <iostream>

bool NetworkServer::Start(int port)
{
    if (enet_initialize() != 0)
    {
        std::cout << "ENet initialization failed!\n";
        return false;
    }

    ENetAddress address{};
    address.host = ENET_HOST_ANY;
    address.port = 25565;

    m_server = enet_host_create(
        &address,
        32,
        2,
        0,
        0
    );

    if (m_server == nullptr)
    {
        std::cout << "Failed to create ENet server!\n";
        enet_deinitialize();
        return false;
    }

    std::cout << "ENet server started on port 25565!\n";

    enet_host_destroy(m_server);
    enet_deinitialize();

    return true;
}
void NetworkServer::Update()
{
    ENetEvent event;

    while (enet_host_service(m_server, &event, 0) > 0)
    {
        switch (event.type)
        {
        case ENET_EVENT_TYPE_CONNECT:
            std::cout << "Client connected!\n";
            break;

        case ENET_EVENT_TYPE_DISCONNECT:
            std::cout << "Client disconnected!\n";
            break;

        case ENET_EVENT_TYPE_RECEIVE:
            std::cout << "Received packet!\n";
            enet_packet_destroy(event.packet);
            break;
        }
    }
}