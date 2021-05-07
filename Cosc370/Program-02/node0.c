/*
	Cody Murrer, Bevan Smith
	Program2
*/

#include <stdio.h>
#include <limits.h>

extern struct rtpkt
{
	int sourceid;   /* id of sending router sending this pkt */
	int destid;     /* id of router to which pkt being sent 
												 (must be an immediate neighbor) */
	int mincost[4]; /* min cost to node 0 ... 3 */
};

extern int TRACE;
extern int YES;
extern int NO;

struct distance_table
{
	int costs[4][4];
} dt0;

/* students to write the following two routines, and maybe some others */
struct rtpkt pkt;
void rtinit0()
{
	int i, j;

    extern float clocktime;

	printf("Running rtinit0\n");
    printf("Clocktime in rtinit0: %f\n", clocktime);

	for (i = 0; i < 4; i++)
	{
		// Set all costs to MAX cost
		pkt.mincost[i] = 999;
		for (j = 0; j < 4; j++)
		{
			dt0.costs[i][j] = 999;
		}
	}

	// Distance to each node from node 0
	dt0.costs[0][0] = 0;
	dt0.costs[1][1] = 1;
	dt0.costs[2][2] = 3;
	dt0.costs[3][3] = 7;

	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			// Check for a smaller cost
			if (dt0.costs[i][j] < pkt.mincost[i])
			{
				pkt.mincost[i] = dt0.costs[i][j];
			}
		}
	}

	pkt.sourceid = 0; // Node 0
	pkt.destid = 1;
	tolayer2(pkt); // Send to layer 2

	//pkt.sourceid = 0;
	pkt.destid = 2;
	tolayer2(pkt);

	//pkt.sourceid = 0;
	pkt.destid = 3;
	tolayer2(pkt);

	printdt0(&dt0);
	printf("Exiting rtini0\n");
}

void rtupdate0(rcvdpkt) struct rtpkt *rcvdpkt;
{
	printf("Running rtupdate0\n");
	int i, j;

	for(i = 0; i < 4; i++) {
		pkt.mincost[i] = 999;
	}

	extern float clocktime;
	printf("Clocktime of rtupdate0: %f send: %d\n", clocktime, rcvdpkt->sourceid);
	printdt0(&dt0);

    // Check if update or not
    int status = 0;

    for(i = 0; i < 4; ++i) {
        if(rcvdpkt->mincost[i] + dt0.costs[rcvdpkt->sourceid][rcvdpkt->sourceid] < dt0.costs[i][rcvdpkt->sourceid]) {
            dt0.costs[i][rcvdpkt->sourceid] = rcvdpkt->mincost[i] + dt0.costs[rcvdpkt->sourceid][rcvdpkt->sourceid];
            status = 1;
        }
    }

    if(status) {
        for(i = 0; i < 4; i++) {
            for(j = 0; j < 4; j++) {
                if (dt0.costs[i][j] < pkt.mincost[i]) {
                    pkt.mincost[i]  = dt0.costs[i][j];
                }
            }
        }

        printf("Updating distance table inside rtdupdate0\n");

        pkt.sourceid = 0; // Node 0
	    pkt.destid = 1;
	    tolayer2(pkt); // Send to layer 2

	    pkt.sourceid = 0;
	    pkt.destid = 2;
	    tolayer2(pkt);

        pkt.sourceid = 0;
        pkt.destid = 3;
        tolayer2(pkt);

        
    }

    printdt0(&dt0);

}

printdt0(dtptr) struct distance_table *dtptr;

{
	printf("                via     \n");
	printf("   D0 |    1     2    3 \n");
	printf("  ----|-----------------\n");
	printf("     1|  %3d   %3d   %3d\n", dtptr->costs[1][1],
				 dtptr->costs[1][2], dtptr->costs[1][3]);
	printf("dest 2|  %3d   %3d   %3d\n", dtptr->costs[2][1],
				 dtptr->costs[2][2], dtptr->costs[2][3]);
	printf("     3|  %3d   %3d   %3d\n", dtptr->costs[3][1],
				 dtptr->costs[3][2], dtptr->costs[3][3]);
}

linkhandler0(linkid, newcost) int linkid, newcost;

/* called when cost from 0 to linkid changes from current value to newcost*/
/* You can leave this routine empty if you're an undergrad. If you want */
/* to use this routine, you'll need to change the value of the LINKCHANGE */
/* constant definition in prog3.c from 0 to 1 */

{
}
