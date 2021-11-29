# Socket_Programming
Socket_Programming 

UDP Client :


    Create UDP socket.
    Send message to server.
    Wait until response from server is recieved.
    Process reply and go back to step 2, if necessary.
    Close socket descriptor and exit.
    
    
use
usend_sys1.c   will send message to sys2 which receive by urecv_sys2.c
usend_sys2.c   will send message to sys1 which receive by urecv_sys1.c


if you want to exit from messaging,you need to send exit message to receiver .

use 4 different terminals
command :
'''1 .  gcc -o usend_sys1.c syssend1
   2 .  gcc -o usend_sys2.c syssend2

   3 .  gcc -o urecv_sys1.c sysrcv1 
   4 .  gcc -o urecv_sys2.c sysrcv2
'''


use to send and recieve data
./syssend1

./syssrcv1
