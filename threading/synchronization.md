# Semaphore
  fcntl is only used for files, we can;t use for shared memory because in shared memory there will be no file descriptors. 

  So to synchronize the shared memory we have to go to **semaphore**

  - semaphore is a small positive integer which present in a kernel space, which is useful for synchronization between multiple processes when they are trying to access shared resource.
  - 
