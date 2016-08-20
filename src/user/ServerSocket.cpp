// Implementation of the ServerSocket class

#include "ServerSocket.h"
#include "SocketException.h"



ServerSocket::ServerSocket ( int port )
{
  if ( ! Socket::create() )
    {
      throw SocketException ( "Could not create server socket." );
    }

  if ( ! Socket::bind ( port ) )
    {
      throw SocketException ( "Could not bind to port." );
    }

  if ( ! Socket::listen() )
    {
      throw SocketException ( "Could not listen to socket." );
    }

}


ServerSocket::~ServerSocket()
{
}


const ServerSocket& ServerSocket::operator << ( const std::string& s ) const
{
  if ( ! Socket::send ( s ) )
    {
      throw SocketException ( "Could not write to socket." );
    }

  return *this;

}


const ServerSocket& ServerSocket::operator >> ( std::string& s ) const
{
  if ( ! Socket::recv ( s ) )
    {
      throw SocketException ( "Could not read from socket." );
    }

  return *this;
}

void ServerSocket::accept ( ServerSocket& sock )
{
  if ( ! Socket::accept ( sock ) )
    {
      throw SocketException ( "Could not accept socket." );
    }
}

int ServerSocket::start (int port, pthread_mutex_t *myMutex, volatile DBs  *myDBs)
{

	DB myDB = DB(myDBs);
	cout << "Running...\n";

//	sleep(2);
//	cout << "SERVER UNIT :" << endl;
//	cout << myDB.getUnit(val_humidity) << endl;

  try
    {
      // Create the socket
      ServerSocket server ( port );

      while ( true )
	{

	  ServerSocket new_sock;
	  server.accept ( new_sock );
	  if(DEBUG)cout << "Connected !\n";

	  User user = User(myDBs);
	  string rcv, snd;

      pthread_mutex_lock(myMutex);
	  new_sock << user.atConnect1();
	  new_sock << user.atConnect2();
	  new_sock << user.atConnect3();
      pthread_mutex_unlock(myMutex);

	  try
	    {
	      while ( true )
		{
		  new_sock >> rcv;
		  if(DEBUG)cout << "Data received !\n";

		  pthread_mutex_lock(myMutex);
		  snd = user.execute(rcv);
		  new_sock << snd;
          pthread_mutex_unlock(myMutex);
		}
	    }
	  catch ( SocketException& ) {}
	  if(DEBUG)cout << "Disconnected !\n";
	}
    }
  catch ( SocketException& e )
    {
      cout << "Exception was caught:" << e.description() << "\nExiting.\n";
    }


  return 0;
}




