// Definition of the ServerSocket class

#ifndef ServerSocket_class
#define ServerSocket_class

#include <iostream>
#include "Socket.h"

#include "ServerSocket.h"
#include "SocketException.h"
#include <cstdlib>
#include <pthread.h>
#include <unistd.h>


#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>
#include <netinet/in.h>
#include <resolv.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#include "../Domotic.h"
#include "User.h"

using namespace std;

class ServerSocket : private Socket
{
 public:

  ServerSocket ( int port );

  ServerSocket (){};
  virtual ~ServerSocket();
  int start(int port, pthread_mutex_t *myMutex, volatile DBs  *myDBs);

  const ServerSocket& operator << ( const std::string& ) const;
  const ServerSocket& operator >> ( std::string& ) const;

  void accept ( ServerSocket& );
  int getSock ();
  void setSock (int sock);

 private:

  int m_sock;



};


#endif
