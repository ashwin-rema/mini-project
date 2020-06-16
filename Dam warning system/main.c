//C program to create an early warning system

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define g 9.8

//Creating a structure variable to store several dam details.
typedef struct flood_system
{
    char name[30];
    double threshold;
    double lat_area;
    double flow_in;
    double width;
    double water_level;
    double init_height;
}m;

//Functions are declared

int capacity(m dam);
double calculate(m dam, double shut_height);
double square(double number);
int decision(m dam, double flow_out);
void cond(int check, int flag, int y);
void file_print_struct(m dam, int n);

//Function to check whether the dam and its surrounding area is safe from flooding

void cond(int check, int flag, int y)

{
    int chfl = check + flag; 
    if((chfl)==2)
    {
        FILE *file;
        file = fopen("records.txt", "a");
	    
        printf("\nAt time t= %d hours \nSignal = RED", y);
        printf("\n\nAlert!!The dam and its surrounding areas are on the verge of flooding."
               "\nSo kindly evacuate the people from the surrounding areas and move them them to higher grounds until futher adviced.");
	    
        fprintf(file, "\nAt time t=%d hours signal=RED", y);
        fprintf(file, "\nAlert!!The dam and its surrounding areas are on the verge of flooding."
                "\nSo kindly evacuate the people from the surrounding areas and move them them to higher grounds until futher adviced.");
	    
        fclose(file);
    }
	
    else if((chfl)==1)
    {
        FILE *file;
        file = fopen("records.txt", "a");
	    
        printf("\nAt time t= %d hours \nSignal = ORANGE", y);
        printf("\n\nThe dam and its surrounding areas are at high risk of flooding."
               "\nSo kindly take the necessary steps required");
	    
        fprintf(file, "\nAt time t = %d hours \nSignal = ORANGE", y);
        fprintf(file, "\n\nThe dam and its surrounding areas are at high risk of flooding."
                "\nSo kindly take the necessary steps required");
	    
        fclose(file);
    }
	
    else if((chfl)==0)
    {
        FILE *file;
        file = fopen("records.txt", "a");
	    
        printf("\nAt time t= %d hours \nSignal = GREEN", y);
        printf("\n\nThe dam and its surrounding area is safe from flooding now and no need to evacuate the people from neighbouring areas."
               "\nNo need to panic.");
	    
        fprintf(file, "\nAt time t = %d hours \nSignal = GREEN", y);
        fprintf(file, "\n\nThe dam and its surrounding area is safe from flooding now and no need to evacuate the people from neighbouring areas"
        "\nNo need to panic");
	    
        fclose(file);
	    
        exit(0);
    }
}

//Function to check if the dam capacity is below the threshold capacity

int capacity(m dam)
{
    double cap = dam.lat_area*dam.water_level;
	
    if(cap>dam.threshold)
    {	    
        return 1;
    }
    else
    {
        return 0;
    }
}

double square(double number)
{
    
    double temp, squrt;

    // store the half of the given number e.g from 256 => 128
    sqrt = number / 2;
    temp = 0;


    // Iterate until sqrt is different of temp, that is updated on the loop
    while(squrt != temp){
        // initially 0, is updated with the initial value of 128
        // (on second iteration = 65)
        // and so on
        temp = squrt;
	    
     return squrt;

        // Then, replace values (256 / 128
//Function to calculate the outward flow of water in the dam
}
double calculate(m dam, double shut_height)
{
    double velocity = square((2*g*shut_height));
    double area = dam.width * shut_height;
    return (area * velocity);
}

//Function to check whether the dam is safe from breaking due to the inward flow of water

int decision(m dam, double flow_out)
{
    double dh = (dam.flow_in - flow_out)/dam.lat_area;
	
    if(dh > dam.init_height)
    {	    
        return 1;
    }
	
    else
    {
        return 0;
    }
}

//Function to store the entered details of the dam in a file for future reference

void file_print_struct(m dam, int n)
{
    FILE *fptr;

    //Opening the file called 'records'
    fptr = fopen("records.txt","a");   
	
    //Printing all necessary information in the "records" file

    fprintf(fptr, "\t\t\t\t\t\tReport\n\n");
    fprintf(fptr, "\t\t\t\t\tEarly Warning Flood System\n\n\n");

    fprintf(fptr, "\n\nThe number of dams in the system that are being monitored : %d", n);
    fprintf(fptr, "\n\nThe name of the dam : %s", dam.name);
    fprintf(fptr, "\n\nThe threshold capacity of the dam in SI units : %lf", dam.threshold);
    fprintf(fptr, "\n\nThe lateral area of the contact surface in SI units : %lf", dam.lat_area);
    fprintf(fptr, "\n\nThe inward flow in the dam in SI units : %lf", dam.flow_in);
    fprintf(fptr, "\n\nThe width of the dam_shutter in SI units : %lf", dam.width);
    fprintf(fptr, "\n\nThe critical height of the dam in SI units : %lf", dam.init_height);
    fprintf(fptr, "\n\nThe water level in the dam in SI units : %lf", dam.water_level);

    //Closing the file
    fclose(fptr);                            
}


//Main function

int main()
{
    FILE *ftr;

    //Creating a file called 'records'
    ftr=fopen("records.txt","w");

    //Closing the file
    fclose(ftr);

    printf("\t\t\t\t\tEARLY WARNING FLOOD SYSTEM\n\n");
    int n;
    int num;
    printf("\nEnter the number of dams in the system that are being monitored :");

    scanf("%d", &n);
    m dam[n];
    for(int i=0; i<n; i++)
    {
        printf("\nEnter the name of the dam :");
        scanf("%s", dam[i].name);

        printf("\nEnter the threshold capacity of the dam in SI units :");
        scanf("%lf", &dam[i].threshold);

        printf("\nEnter the lateral area of the contact surface in SI units :");
        scanf("%lf", &dam[i].lat_area);

        printf("\nEnter the inward flow in the dam in SI units :");
        scanf("%lf", &dam[i].flow_in);

        printf("\nEnter the width of the dam shutter in SI units :");
        scanf("%lf", &dam[i].width);

        printf("\nEnter the critical height of the dam in SI units :");
        scanf("%lf", &dam[i].init_height);

        printf("\nEnter the water level in the dam in SI units :");
        scanf("%lf", &dam[i].water_level);

        //Saving the details of the dam into a file
        file_print_struct(dam[i], n);
        double flow_out = 0.00, shut_height = 0.00;
        int check, flag, y = 0;

        //Checking the criticality of the dam

        check = capacity(dam[i]);
        flag = decision(dam[i], flow_out);
        cond(check, flag, y);
        y = y + 1;




