#include <atomic>

#include <core/ISocketServer.h>
#include <core/SocketClient.h>

class RobotServer : public Robust::ISocketServer
{
  public:
    std::atomic<float> Throttle1;
    std::atomic<float> Throttle2;
    ~RobotServer();
  private:
    void HandleRequest(int);
};