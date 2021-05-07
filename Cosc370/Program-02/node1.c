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

int connectcosts1[4] = { 1,  0,  1, 999 };

struct distance_table 
{
  int costs[4][4];
} dt1;


/* students to write the following two routines, and maybe some others */

struct rtpkt pkt;
rtinit1() 
{
int i, j;

    extern float clocktime;

	printf("Running rtinit1\n");
    printf("Clocktime in rtinit1: %f\n", clocktime);

	for (i = 0; i < 4; i++)
	{
		// Set all costs to MAX cost
		pkt.mincost[i] = 999;
		for (j = 0; j < 4; j++)
		{
			dt1.costs[i][j] = 999;
		}
	}

	// Distance to each node from node 1
	dt1.costs[1][1] = 0;
	dt1.costs[0][0] = 1;
	dt1.costs[2][2] = 1;

	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			// Check for a smaller cost
			if (dt1.costs[i][j] < pkt.mincost[i])
			{
				pkt.mincost[i] = dt1.costs[i][j];
			}
		}
	}

	pkt.sourceid = 1; // Node 1
	pkt.destid = 0;
	tolayer2(pkt); // Send to layer 2

	pkt.sourceid = 1;
	pkt.destid = 2;
	tolayer2(pkt);

	pkt.sourceid = 1;
	printdt1(&dt1);
	printf("Exiting rtini1\n");
}


rtupdate1(rcvdpkt)
  struct rtpkt *rcvdpkt;
  
{
	printf("Running rtupdate1\n");
	int i, j;

	for(i = 0; i < 4; i++) {
		pkt.mincost[i] = 999;
	}

	extern float clocktime;
	printf("Clocktime of rtupdate1: %f send: %d\n", clocktime, rcvdpkt->sourceid);
	printdt1(&dt1);

    // Check if update or not
    int status = 0;

    for(i = 0; i < 4; ++i) {
        if(rcvdpkt->mincost[i] + dt1.costs[rcvdpkt->sourceid][rcvdpkt->sourceid] < dt1.costs[i][rcvdpkt->sourceid]) {
            dt1.costs[i][rcvdpkt->sourceid] = rcvdpkt->mincost[i] + dt1.costs[rcvdpkt->sourceid][rcvdpkt->sourceid];
            status = 1;
        }
    }

    if(status) {
        for(i = 0; i < 4; i++) {
            for(j = 0; j < 4; j++) {
                if (dt1.costs[i][j] < pkt.mincost[i]) {
                    pkt.mincost[i]  = dt1.costs[i][j];
                }
            }
        }

        printf("Updating distance table inside rtdupdate1\n");

        pkt.sourceid = 1; // Node 1
	    pkt.destid = 0;
	    tolayer2(pkt); // Send to layer 2

	    pkt.sourceid = 1;
	    pkt.destid = 2;
	    tolayer2(pkt);
 
    }

   printdt1(&dt1);
}


printdt1(dtptr)
  struct distance_table *dtptr;
  
{
  printf("             via   \n");
  printf("   D1 |    0     2 \n");
  printf("  ----|-----------\n");
  printf("     0|  %3d   %3d\n",dtptr->costs[0][0], dtptr->costs[0][2]);
  printf("dest 2|  %3d   %3d\n",dtptr->costs[2][0], dtptr->costs[2][2]);
  printf("     3|  %3d   %3d\n",dtptr->costs[3][0], dtptr->costs[3][2]);

}



linkhandler1(linkid, newcost)   
int linkid, newcost;   
/* called when cost from 1 to linkid changes from current value to newcost*/
/* You can leave this routine empty if you're an undergrad. If you want */
/* to use this routine, you'll need to change the value of the LINKCHANGE */
/* constant definition in prog3.c from 0 to 1 */
	
{

}


