#ifndef COMMUNICATOR_H
#define COMMUNICATOR_H

#include "mpi.h"
#include "stdio.h"
#include "stdlib.h"
class Communicator
{

    /*--------------------------
        Communicator setups the communicaton in the group
    ------------------------------*/
private:
    long long int *acount; // holds the atom counts from the processes in the group
    void sendrecv(void *temp, long long int &atoms,int dimension, int ts, int rank);
    void rma(void *temp, long long int &atoms,int dimension, int ts, int rank);

    

public:
    static int commtype; // specfies communicaton type
    static int nsim;     // number of simulation process
    static int nana;     // number of analysis process
    static int rcvrank;  // reciver rank will be the last in the GroupComm 
    MPI_Comm ucomm;
    MPI_Comm gcomm;

    Communicator();
    ~Communicator();
    void communicate(void* input, long long int &atoms,int dimension, int ts,int rank); 

};

#endif
