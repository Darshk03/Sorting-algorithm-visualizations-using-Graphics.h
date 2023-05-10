//DS Visualization

#include<iostream>
#include<graphics.h>
#include<cstdlib>
#include<vector>
#include<stdlib.h>
using namespace std;

//GLOBAL VARIABLES
int val[9];
int no_elements;
int xStart[9];
int yStart[9];
int xEnd[9];
int yEnd[9];
int color[9]={0,1,2,3,4,5,6,9,10};
char value[2];
int height_of_block=50;
int width_of_block=60;
int yInitial=450;

class Visual
{
	public:
		void get_data();
		void display_blocks(int val[]);
		void balance_blocks(int);
		void swap_blocks(int,int,int,int);
};

void Visual::get_data()
{
	cout<<"\nEnter the number of elements to sort (You can enter maximum 9 numbers) : ";
	cin>>no_elements;
	cout<<"\nEnter the elements to sort : ";
	for(int i=0;i<no_elements;i++)
	{
		cin>>val[i];
	}
}

void Visual::display_blocks(int val[])
{
	cleardevice();
	xStart[0]=400;
	for(int m=0;m<no_elements;m++)
	{
		yEnd[m]=yInitial;
	    int k=m;
        yStart[m]=yInitial-(50*val[m]);
        xEnd[m]=xStart[m]+60;
        rectangle(xStart[m],yStart[m],xEnd[m],yEnd[m]);
        setfillstyle(1,color[m]);
        floodfill(xStart[m]+10,yEnd[m]-10,15); //GIVING SPACE BETWEEN TWO BLOCKS AS 10
        sprintf(value,"%d",val[m]);
        outtextxy(((xStart[m]+xEnd[m])/2)-5,yEnd[m]-30,value);
        xStart[k+1]=xEnd[m]+10;
	}
}

void Visual::balance_blocks(int x)
{
	 //HALF BALANCER FOR FIRST BLOCK WHILE COMPARING 
    line(xStart[x],yInitial+5,xStart[x],yInitial+20);
    line(xEnd[x],yInitial+5,xEnd[x],yInitial+20);
    line(((xStart[x]+xEnd[x])/2),yInitial+20,((xStart[x]+xEnd[x])/2),yInitial+35 );
    line(xEnd[x],yInitial+20,xStart[x],yInitial+20);

    //HALF BALANCER FOR SECOND BLOCK WHILE COMPARING 
    line(xStart[x+1],yInitial+5,xStart[x+1],yInitial+20);
    line(xEnd[x+1],yInitial+5,xEnd[x+1],yInitial+20);
    line(((xStart[x+1]+xEnd[x+1])/2),yInitial+20,((xStart[x+1]+xEnd[x+1])/2),yInitial+35 );
    line(xEnd[x+1],yInitial+20,xStart[x+1],yInitial+20);

    line(((xStart[x+1]+xEnd[x+1])/2),yInitial+35,((xStart[x]+xEnd[x])/2),yInitial+35);
}

//INTEGER Z IS FOR BALANCER AND DIRECTION UP AND DOWN
void Visual::swap_blocks(int x,int y,int z,int direction)
{
	int move_block[9];
    cleardevice();
    for(int inc=0;inc<9;inc++)
    {
        int temp=inc;
        if (temp==x || temp==y)
        {
            move_block[inc]=1;
        }

        else
		{
            move_block[inc]=0;
        }
    }
    
    //LOOP TO SHOW SWAPPING
    for(int k=0; k<=15; k++)
    {
      cleardevice();
       for(int i=0;i<no_elements;i++)
        {
	        yEnd[i]=yInitial-direction*move_block[i]*3*k;
	        int j=i;
	        yStart[i]=yEnd[i]-(height_of_block*val[i]);
	        xEnd[i]=xStart[i]+width_of_block;
	        rectangle(xStart[i],yStart[i],xEnd[i],yEnd[i]);
	        setfillstyle(1,color[i]);
	        floodfill(xStart[i]+10,yEnd[i]-10,15);
	            
	        sprintf(value,"%d",val[i]);
	        outtextxy(((xStart[i]+xEnd[i])/2)-5,yEnd[i]-30,value);
	        xStart[j+1]=xEnd[i]+10;
	    }
   //IF Z IS 1 THEN SHOW BALANCER ELSE DON'T
    if(z==1)
    {
        balance_blocks(x);
    }

    delay(150);
  }
}

int main()
{
	Visual V;
	int choice,choice_of_sorting,press;
    initwindow(1600,900,"DATA STRUCTURE VISUALIZATION");
    settextstyle(8,0,3);
    
    do
    {
	    system("CLS");
	    cout<<"******************************WELCOME TO THE WORLD OF VISUALIZING SORTING ALGORITHM**********************************"<<endl<<endl;
	    cout<<"-------------------------------------------------------**MENU**---------------------------------------------------------"<<endl<<endl;
	    cout<<"------------------------------------PRESS 1 FOR BUBBLE SORT----------------------------------------------"<<endl<<endl;
	    cout<<"------------------------------------PRESS 2 FOR SELECTION SORT------------------------------------------------"<<endl<<endl;
	    cout<<"------------------------------------PRESS 3 FOR INSERTION SORT------------------------------------------------"<<endl<<endl;
	    cout<<"----------------------------------------------ENTER YOUR CHOICE--------------------------------------------------------"<<endl<<endl;
	    cin>>choice;
        //WE HAVE TO RESET THE COLORS AFTER SORTNG IS DONE
	    color[0]=0; color[1]=1; color[2]=2; color[3]=3; color[4]=4; color[5]=5; color[6]=6; color[7]=9; color[8]=10;
	    switch(choice)
        {
            //FOR BUBBLE SORT
            system("CLS");
	        case 1:
		        V.get_data();
		        V.display_blocks(val);
		        
		        
		        int temp;
		
		            for(int i=0;i<no_elements;i++)
		                {
		                    for(int j=0;j<no_elements-1-i;j++)
		                        {
		                            if(val[j]>val[j+1])
		                                {
		                               		//ANIMATION OF SWAPPING WILL START
		                                    V.swap_blocks(j,j+1,1,1);
		                                    //VALUES OF ENTERED ARRAY WILL SWAP
		                                    temp=val[j];
		                                    val[j]=val[j+1];
		                                    val[j+1]=temp;
		                                    //SWAPPING THE VALUES OF COLOR TO MAINTAIN COLOR CONSISTERNCY
		                                    int temp_color;
		                                    temp_color=color[j];
		                                    color[j]=color[j+1];
		                                    color[j+1]=temp_color;
		                                    V.display_blocks(val);
		                                }
		
		
		                            //IF WE CAN'T SWAP THEN DISPLAY "CAN'T SWAP!"
		                            else{
		                                V.display_blocks(val);
		                                // DISPLAY BALANCER
		                                V.balance_blocks(j);
		                                outtextxy((xStart[j+1]+xEnd[j+1])/2,yInitial+40,"Can't swap");
		                                delay(200);
		
		                                }
		
		
		                            }
		
		                        //ADD GREY COLOR TO SORTED BLOCKS TO SHOW THAT THE SORTING IS COMPLETED
		                        color[no_elements-i-1]=8;
		                        V.display_blocks(val);
		                        }
		                        outtextxy(xStart[0]+10,yInitial+40,"SORTING COMPLETED");
		    break;
	
	        
	        //FOR SELECTION SORT
	        system("CLS");
	        case 2:
	            int minimum_number;
	            int minimum_location;
	            V.get_data();
	            V.display_blocks(val);
	            
		        for(int i=0;i<no_elements-1;i++ )
		        {
		        	minimum_number=val[i];
			        minimum_location=i;
			        
			        for(int j=i;j<no_elements;j++)
			        {
			            V.swap_blocks(j,no_elements,0,-1);
			        }
			
			        //CHECK THE MINIMUM
			        for(int inner=i;inner<no_elements;inner++)
			        {
			            if(val[inner]<minimum_number)
			            {
			                minimum_number=val[inner];
			                minimum_location=inner;
			            }
			        }
			
			        //DISPLAY THE MINIMUM
			        V.display_blocks(val);
			        outtextxy(xStart[minimum_location],yEnd[minimum_location]+5,"MIN");
			        delay(150);
			
			        if(minimum_location!=i)
			        {
			            V.swap_blocks(i,minimum_location,0,1);
			        }
			        V.display_blocks(val);
			
			        int temp=val[i];
			        val[i]=val[minimum_location];
			        val[minimum_location]=temp;
			
			        V.display_blocks(val);
			
			        //ADD GREY COLOR TO THE SORTED BLOCKS
			        color[i]=8;
			        V.display_blocks(val);
		
		    	}
		        //COLOR THE LAST ELEMENT WITH GREY COLOR
		        color[no_elements-1]=8;
		        V.display_blocks(val);
		        outtextxy(xStart[0]+10,yInitial+40,"SORTING COMPLETED!");
		    break;
		    
		    case 3:
		    	V.get_data();
		    	V.display_blocks(val);
		    	int j;
		    	int i;
		    	int temp_in;
		    	//color[0]=8;
		    	
		    	for(i=1;i<=no_elements;i++)
		    	{
		    		
		    		for(j=i;j>=0 && val[j-1]>val[j];j--)
		    		{
		    			temp_in=val[j];
		    			val[j]=val[j-1];
		    			val[j-1]=temp_in;
		    			V.swap_blocks(j,j+1,1,1);
		    			
					}
				
				}
				
				for(int i=0;i<=no_elements;i++)
				{
					 V.display_blocks(val);
			        //ADD GREY COLOR TO THE SORTED BLOCKS
			        color[i]=8;
			        V.display_blocks(val);
				}
				//COLOR THE LAST ELEMENT WITH GREY COLOR
				color[no_elements-1]=8;
		        V.display_blocks(val);
		        outtextxy(xStart[0]+10,yInitial+40,"SORTING COMPLETED!");
		    break;
	
	    }
	    cout<<"\nIf you want to continue then press 1: ";
	    cin>>press;
    }
	while(press==1);    
    return 0;
    closegraph();

}



