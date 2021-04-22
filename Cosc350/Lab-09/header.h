#define NOT_READY -1
#define FILLED 0 
#define TAKEN 1 
#define GO 2
#define STOP 3

struct userInput {
    int numberOne;
    int numberTwo;
    int finish;
};

struct Memory {
    int status;
    int gostop;
    struct userInput data;
};
