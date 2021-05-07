/*
	Cody Murrer, Bevan Smith
	Program2
*/
#include <stdio.h>
#include <limits.h>

extern struct rtpkt {
  int sourceid;       /* id of sending router sending this pkt */
  int destid;         /* id of router to which pkt being sent 
                         (must be an immediate neighbor) */
  int mincost[4];    /* min cost to node 0 ... 3 */
  };

extern int TRACE;
extern int YES;
extern int NO;

struct distance_table 
{
  int costs[4][4];
} dt3;

/* students to write the following two routines, and maybe some others */
struct rtpkt pkt;
void rtinit3() 
{
  	int i, j;

    extern float clocktime;

	printf("Running rtinit3\n");
    printf("Clocktime in rtinit3: %f\n", clocktime);

	for (i = 0; i < 4; i++)
	{
		// Set all costs to MAX cost
		pkt.mincost[i] = 999;
		for (j = 0; j < 4; j++)
		{
			dt3.costs[i][j] = 999;
		}
	}

	// Distance to each node from node 3

	dt3.costs[0][0] = 7;
	dt3.costs[2][2] = 2;
	dt3.costs[3][3] = 0;

	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			// Check for a smaller cost
			if (dt3.costs[i][j] < pkt.mincost[i])
			{
				pkt.mincost[i] = dt3.costs[i][j];
			}
		}
	}

	pkt.sourceid = 3; // Node 3
	pkt.destid = 0;
	tolayer2(pkt); // Send to layer 2

	pkt.sourceid = 3;
	pkt.destid = 2;
	tolayer2(pkt);

	pkt.sourceid = 3;
	printdt3(&dt3);
	printf("Exiting rtini3\n");
}


void rtupdate3(rcvdpkt)
  struct rtpkt *rcvdpkt;
  
{
printf("Running rtupdate3\n");
	int i, j;

	for(i = 0; i < 4; i++) {
		pkt.mincost[i] = 999;
	}

	extern float clocktime;
	printf("Clocktime of rtupdate3: %f send: %d\n", clocktime, rcvdpkt->sourceid);
	printdt3(&dt3);

    // Check if update or not
    int status = 0;

    for(i = 0; i < 4; ++i) {
        if(rcvdpkt->mincost[i] + dt3.costs[rcvdpkt->sourceid][rcvdpkt->sourceid] < dt3.costs[i][rcvdpkt->sourceid]) {
            dt3.costs[i][rcvdpkt->sourceid] = rcvdpkt->mincost[i] + dt3.costs[rcvdpkt->sourceid][rcvdpkt->sourceid];
            status = 1;
        }
    }

    if(status) {
        for(i = 0; i < 4; i++) {
            for(j = 0; j < 4; j++) {
                if (dt3.costs[i][j] < pkt.mincost[i]) {
                    pkt.mincost[i]  = dt3.costs[i][j];
                }
            }
        }

        printf("Updating distance table inside rtdupdate3\n");

        pkt.sourceid = 3; // Node 3
	    pkt.destid = 0;
	    tolayer2(pkt); // Send to layer 2

	    pkt.sourceid = 3;
	    pkt.destid = 2;
	    tolayer2(pkt);

    }

    printdt3(&dt3);
}


printdt3(dtptr)
  struct distance_table *dtptr;
  
{
  printf("             via     \n");
  printf("   D3 |    0     2 \n");
  printf("  ----|-----------\n");
  printf("     0|  %3d   %3d\n",dtptr->costs[0][0], dtptr->costs[0][2]);
  printf("dest 1|  %3d   %3d\n",dtptr->costs[1][0], dtptr->costs[1][2]);
  printf("     2|  %3d   %3d\n",dtptr->costs[2][0], dtptr->costs[2][2]);

}







