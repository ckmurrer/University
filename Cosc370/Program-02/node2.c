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
} dt2;


/* students to write the following two routines, and maybe some others */
struct rtpkt pkt;
void rtinit2() 
{
  	int i, j;

    extern float clocktime;

	printf("Running rtinit2\n");
    printf("Clocktime in rtinit2: %f\n", clocktime);

	for (i = 0; i < 4; i++)
	{
		// Set all costs to MAX cost
		pkt.mincost[i] = 999;
		for (j = 0; j < 4; j++)
		{
			dt2.costs[i][j] = 999;
		}
	}

	// Distance to each node from node 2

	dt2.costs[0][0] = 3;
    dt2.costs[1][1] = 1;
	dt2.costs[2][2] = 0;
	dt2.costs[3][3] = 2;

	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			// Check for a smaller cost
			if (dt2.costs[i][j] < pkt.mincost[i])
			{
				pkt.mincost[i] = dt2.costs[i][j];
			}
		}
	}

	pkt.sourceid = 2; // Node 2
	pkt.destid = 0;
	tolayer2(pkt); // Send to layer 2

	pkt.sourceid = 2;
	pkt.destid = 1;
	tolayer2(pkt);

	pkt.sourceid = 2;
	pkt.destid = 3;
	tolayer2(pkt);

	printdt2(&dt2);
	printf("Exiting rtini2\n");
}


void rtupdate2(rcvdpkt)
  struct rtpkt *rcvdpkt;
  
{
printf("Running rtupdate2\n");
	int i, j;

	for(i = 0; i < 4; i++) {
		pkt.mincost[i] = 999;
	}

	extern float clocktime;
	printf("Clocktime of rtupdate2: %f send: %d\n", clocktime, rcvdpkt->sourceid);
	printdt2(&dt2);

    // Check if update or not
    int status = 0;

    for(i = 0; i < 4; ++i) {
        if(rcvdpkt->mincost[i] + dt2.costs[rcvdpkt->sourceid][rcvdpkt->sourceid] < dt2.costs[i][rcvdpkt->sourceid]) {
            dt2.costs[i][rcvdpkt->sourceid] = rcvdpkt->mincost[i] + dt2.costs[rcvdpkt->sourceid][rcvdpkt->sourceid];
            status = 1;
        }
    }

    if(status) {
        for(i = 0; i < 4; i++) {
            for(j = 0; j < 4; j++) {
                if (dt2.costs[i][j] < pkt.mincost[i]) {
                    pkt.mincost[i]  = dt2.costs[i][j];
                }
            }
        }

        printf("Updating distance table inside rtdupdate2\n");

        pkt.sourceid = 2; // Node 2
	    pkt.destid = 0;
	    tolayer2(pkt); // Send to layer 2

	    pkt.sourceid = 2;
	    pkt.destid = 1;
	    tolayer2(pkt);

        pkt.sourceid = 2;
        pkt.destid = 3;
        tolayer2(pkt);

    }

    printdt2(&dt2);
}


printdt2(dtptr)
  struct distance_table *dtptr;
  
{
  printf("                via     \n");
  printf("   D2 |    0     1    3 \n");
  printf("  ----|-----------------\n");
  printf("     0|  %3d   %3d   %3d\n",dtptr->costs[0][0],
	 dtptr->costs[0][1],dtptr->costs[0][3]);
  printf("dest 1|  %3d   %3d   %3d\n",dtptr->costs[1][0],
	 dtptr->costs[1][1],dtptr->costs[1][3]);
  printf("     3|  %3d   %3d   %3d\n",dtptr->costs[3][0],
	 dtptr->costs[3][1],dtptr->costs[3][3]);
}







