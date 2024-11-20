# Linux IPC mechanism

# pipe

# named pipe

# message queues
### advantages
  - To overcome the disadvantages of pipe we can use message queues
  - While writing into the queue not necessary reading process should be alive, anytime it can read based on message keys.
  - writer process can write to specific reading process
    
```#include <sys/types.h>
   #include <sys/ipc.h>
   #include <sys/msg.h>

  msgget()
    int msgget(key_t key, int msgflags)
  msgrecv()
  msgsend()
  msgctl()

  - ipcs -q  // Commnd to check existing message queues
  - ipcrm -q <key num>  // to remove the message queue
```
### disadvantages
  - Message queus is one of the slowest IPC
  - Burdening more to the kernel because it has to maintain structures, linked list, searching etc.

# shared memory
  One of the fastest IPC
```
  shmget()
    - int shmget(key_t key, size_t size, int shmflg)
  shmat()
  shmdt()
  shmctl()
```
  - ipcs -m // command to check how many shared memories are available. 



