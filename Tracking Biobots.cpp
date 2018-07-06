#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;

struct point {
	int x;
	int y;
};

main()
{
	int row	,col ;								//row and col
	int *totalPoint ;							//for creating block dynamically
	
	for(int kase=0 ; kase < 2 ; kase++)
	{
		
		
		cout<<"Enter number of rows and cols: ";
		cin	>>	row	>>	col;
		
		
		
		totalPoint	=	new int;
	
	
		cout<<"Enter number of walls: ";
		cin	>>	*totalPoint;
		
		if(row==0 && col==0 )
		{
			cout<<"Size of room can not be 0.."<<endl;
			continue;
		}
		
	
		point pointStart[*totalPoint]	,pointEnd[*totalPoint]; 			//number of cordinates of stuck blocks
	
		if( *totalPoint == 0  )
		{
			cout<<"0 stuck boock present in this case..";
			exit(0);
		}		
		else 
		if( *totalPoint != 0 ) 
		{
			cout<<"Enter x,y axis of starting and ending ponint of wall: "<<endl;
			for(int i=0 ; i< *totalPoint ; i++)
			{
				cin	>>	pointStart[i].x;
				if(pointStart[i].x < row)
				{
					cin	>>	pointStart[i].y;
					if(pointStart[i].y < col)
					{
						cin	>>	pointEnd[i].x;
						if(pointEnd[i].x <row)
						{
							cin	>>	pointEnd[i].y;
							if(pointEnd[i].y <col)
							{
								if(pointStart[i].y != pointEnd[i].y)
								{
									cout<<"Wall should be horizontal OR Y coordinate of starting and ending point must be same...";
									getch();
									exit(1);
								}
						}
							else
							{
								cout<<"Value of coordinate must be less than " << col <<endl;
								exit(1);
							}
					
						}
						else
						{
							cout<<"Value of coordinate must be less than " << row <<endl;
							exit(1);
						}
					}
					else
					{
						cout<<"Value of coordinate must be less than " << col <<endl;
						exit(1);
					}
				}
		
			}

		} // end FOR loop of taking input of coordinates
	
	
	int a[*totalPoint], sum=0;
	
	for(int i=0 ; i < *totalPoint ; i++)
	{
		if(pointStart[i].y == pointEnd[i].y)
		{
			a[i] = ( pointEnd[i].x  -  pointStart[i].x ) +1 ;
			sum += a[i];
		}
		else exit(2);
	}
	
	
	cout<< sum << " stuck block(s) present in case " << kase+1 <<endl<<endl;

		
	}
	
	delete totalPoint;
	getche();
}
