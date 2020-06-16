#define density 2400
#define acceleration 10

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

//Function to calculate the outward flow of water in the dam

double calculate(m dam, double shut_height)
{
    double velocity = sqrt((2*g*shut_height));
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

//Warning System
void warning_system(d dam)
{
    int num;
	
    //Singal messages
	
    char signal_1[10] = {" GREEN"};
    char signal_2[10] = {" ORANGE!"};
    char signal_3[10] = {" YELLOW!!"};
    char signal_4[10] = {" RED!!!!"};
    char signal_5[30] = {" WRONG INFORMATION GIVEN"};
    char msg_1[30] = {" No need to panic"};
    char msg_2[50] = {" Take extreme precaution and steps necessary"};
    char msg_3[50] = {" Prepare for evacuation immediately"};
    char msg_4[70] = {" Alert!! Evacuate immediately"};
    char msg_5[70] = {" KINDLY ENTER CORRECT INFORMATION TO PROCESS THE WARNING\n\n"};
	
    double s_height , md_height , d_height;
    s_height = (0.7 * dam.dam_height);
    md_height = (0.85 * dam.dam_height);
    d_height = (0.9 * dam.dam_height);
	
    if(dam.water_level <= (s_height))
    {
	file_print(signal_1, msg_1);
	num = 1;
	evacuation_instructions(num);
	breaking_force(dam);
    }
	
    else if((dam.water_level > s_height) && (dam.water_level <= md_height))
    {
	file_print(signal_2, msg_2);
	num = 2;
	evacuation_instructions(num);
	breaking_force(dam);
    }
	
    else if((dam.water_level > md_height) && (dam.water_level <= d_height))
    {
	file_print(signal_3, msg_3);
	num = 3;
	evacuation_instructions(num);
	breaking_force(dam);
    }   
	
    else if((dam.water_level > d_height) && (dam.water_level <= dam.dam_height))
    {
	file_print(signal_4, msg_4);
	num = 4;
	evacuation_instructions(num);
	breaking_force(dam);
    }
	
    else 
    {
        file_print(signal_5, msg_5);
    }
}




