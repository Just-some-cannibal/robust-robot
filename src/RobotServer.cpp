#include "RobotServer.h"

RobotServer::~RobotServer()
{
    close(ServerSock);
}

void RobotServer::HandleRequest(int socket)
{
    Robust::SocketClient client(socket);
    std::string received;

    do
    {
        try
        {
            received = client.ReceiveData();

            float throttle1;
            float throttle2;
            if (sscanf(received.c_str(), "%f %f", &throttle1, &throttle2) == 2)
            {
                Throttle1 = throttle1;
                Throttle2 = throttle2;
            }
            else
            {
                Robust::err("Invalid input");
            }
        }
        catch (...)
        {
            Robust::err("An error has occured: Closing socket");
            break;
        }
    } while (received.size() > 0);
    close(socket);
}