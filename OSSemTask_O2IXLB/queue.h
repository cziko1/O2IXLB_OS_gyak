#define ProjectId 123
#define PathName  "queue.h"
#define MsgLen    50
#define MsgCount  10

typedef struct { 
  int id;                
  int value;  
} queuedMessage;