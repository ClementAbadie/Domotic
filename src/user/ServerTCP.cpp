#include "ServerTCP.h"




void* mySocketHandler(void* m_sock){


	cout << "m_sock : " << (int)m_sock << endl;
	ServerSocket sock;
	sock.setSock((int)m_sock);

	  //User user = User(myDBs);


   // pthread_mutex_lock(myMutex);
	//  sock << user.atConnect1();
	 // sock << user.atConnect2();
	//  sock << user.atConnect3();
   // pthread_mutex_unlock(myMutex);

	  try
	    {
	      while ( true )
		{
	      string rcv, snd;

	      sock >> rcv;
		  if(DEBUG)cout << rcv;

		 // pthread_mutex_lock(myMutex);
		 // snd = user.execute(rcv);
		  sock << snd;
       // pthread_mutex_unlock(myMutex);
		}
	    }
	  catch ( SocketException& ) {}

	  return 0;
}


int myTCPServer (int port, pthread_mutex_t *myMutex, volatile DBs  *myDBs)
{

	pthread_t thread_id=0;

  try
    {
      // Create the socket
      ServerSocket server ( port );
      if(DEBUG)cout << "Server Online !\n";



      while(true){
    	  try
    	    {
    	  	  ServerSocket new_sock;
    	  	  server.accept ( new_sock );
    	  	  int m_sock = new_sock.getSock();
    	  	  cout << "m_sock : " << m_sock << endl;
              pthread_create(&thread_id,0,&mySocketHandler, (void*)m_sock);
              pthread_detach(thread_id);
          }
      catch ( SocketException& e )
        {
          cerr << "Exception was caught:" << e.description() << "\nExiting.\n";
        }
      }

      while ( true )
	{

	  ServerSocket new_sock;
	  server.accept ( new_sock );
	  if(DEBUG)cout << "Client Connected !\n";
	  User user = User(myDBs);


     // pthread_mutex_lock(myMutex);
	  new_sock << user.atConnect1();
	  new_sock << user.atConnect2();
	  new_sock << user.atConnect3();
     // pthread_mutex_unlock(myMutex);

	  try
	    {
	      while ( true )
		{
	      string rcv, snd;

		  new_sock >> rcv;
		  if(DEBUG)cout << rcv;

		 // pthread_mutex_lock(myMutex);
		  snd = user.execute(rcv);
		  new_sock << snd;
         // pthread_mutex_unlock(myMutex);
		}
	    }
	  catch ( SocketException& ) {}

	  if(DEBUG)cout << "Client Disconnected !\n";

	}
    }
  catch ( SocketException& e )
    {
      cerr << "Exception was caught:" << e.description() << "\nExiting.\n";
    }

  return 0;
}
