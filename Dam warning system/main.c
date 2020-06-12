#define density 2400
#define acceleration 10
//Creating a structure variable to store several dam details.
typedef struct dam_records
{
    char dam_name[30];
    double dam_height;
    double dam_width;
    double dam_length;
    double water_level;
    double river_length;
    double rainfall;
}d;

void breaking_force(d);
void warning_system(d);
void file_print_struct(d);
void file_print(char *a, char *b);
void evacuation_instructions(int);

//This function is used to convey the suggested instructions to be followed according to the given parameters.
void evacuation_instructions(int num)
{
    //This message is when the flag is green (i.e.)when there is no danger.
    char dam1[100]={"\n\n\t The dam may remain closed as there is no threat at all."};
    char resc1[100]={"\n\t Evacuation is NOT necessary and NO volunteers will be required for the time being."};
    //This message is when the flag is yellow (i.e.)when there is slight danger.
    char dam2[100]={"\n\n\t Suggested measures are to EVACUATE people in a 1 KM radius surrounding the dam."};
    char resc2[200]={"\n\t Once people have been evacuated, the dam is to be opened to prevent sturctural damage to the dam.\n\t "
                     "Around 10-20 volunteers will be required to aid in cleanup and for help in evacuation."};
    //This message is when the flag is orange (i.e.)when the is significant danger.
    char dam3[100]={"\n\n\t It is HIGHLY advised that people in a 5 to 6 KM radius be EVACUATED IMMEDIATELY"};
    char resc3[300]={"\n\t The dam is to be opened immediately after the evacuation process has been completed as an alarming amount of stress is being put on the dam.\n\t "
                     "Disaster Management teams to be alerted and kept on standby incase of emergencies.\n\t"
                     "Around 40 to 50 volunteers are to be requested to aid in the evacuation."};
    //This message is when the flag is red (i.e.)when there is high threat of disaster.
    char dam4[400]={"\n\n\t IMMINENT DANGER! EXCESS AMOUNTS OF STRESS IS BEING PUT ON THE DAM.\n\t"
                    " PEOPLE IN A 10 KM TO BE EVACUATED IMMEDIATELY."};
    char resc4[300]={"\n\t HIGHLY ADVISED THAT THE DAM BE OPENED ASAP TO PREVENT BREAKING OF THE DAM.\n\t "
                     "DISASTER MANAGEMENTS TEAMS TO BE KEPT ON CALL READY TO RESPOND.\n\t"
                     "Several hundred, more than 200 volunteers are to be resqusted and kept on standby to aid in the rescue and evacuation."};
    char inst1[100]={"\nINSTRUCTIONS\n"};
    char inst2[100]={"\t\t\tEVACUATION AND OPENING OF DAM:"};
    file_print(inst1,inst2);
    //Printing the appropriate details from the above based on the input given.
    if(num == 1)
    {
        file_print(dam1,resc1);
    }
    else if(num == 2)
    {
        file_print(dam2,resc2);
    }
    else if(num == 3)
    {
        file_print(dam3,resc3);
    }
    else if(num == 4)
    {
        file_print(dam4,resc4);
    }
    else
    {
	printf("\n");
    }
}
//Storing the warning message and signal in the file for future reference
void file_print(char *a, char *b)
{
      FILE *ftr;
      ftr=fopen("records.txt","a");
      printf("\n%s",a);
      printf("\n%s",b);
      fprintf(ftr,"\n%s",a);
      fprintf(ftr,"\n%s",b);
      fclose(ftr);
}
//Calculating the breaking force of the dam and storing it in the file for future reference.
void breaking_force(d dam)
{
    FILE *ftr;
    ftr=fopen("records.txt","a");
    char des[30]={"The breaking force is: "};
    double dam_force= dam.dam_width * dam.dam_height * dam.dam_length * density * acceleration;
    printf("\n\n\n The breaking force is: %lf\n\n\n",dam_force);
    fprintf(ftr,"\n\n%s",des);
    fprintf(ftr," %lf\n\n",dam_force);
    fclose(ftr);
}

//Storing the entered details of the dam in a file for future reference.
void file_print_struct(d dam)
{
    FILE *ftr;
    ftr=fopen("records.txt","a");
    char description[40]={"\t\t\t\t\t\tRecords of dam maintenance\n\n"};
    fprintf(ftr,"%s",description);
    fprintf(ftr,"\n\n%s%s","Name: ",dam.dam_name);
    fprintf(ftr,"\n\n%s%lf","Height: ",dam.dam_height);
    fprintf(ftr,"\n\n%s%lf","Width: ",dam.dam_width);
    fprintf(ftr,"\n\n%s%lf","Length: ",dam.dam_length);
    fprintf(ftr,"\n\n%s%lf","Water level: ",dam.water_level);
    fprintf(ftr,"\n\n%s%lf","River length: ",dam.river_length);
    fprintf(ftr,"\n\n%s%lf\n\n","Rainfall: ",dam.rainfall);
    fclose(ftr);
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
    if(dam.water_level <= (0.7 * dam.dam_height))
    {
	file_print(signal_1, msg_1);
	num = 1;
	evacuation_instructions(num);
	breaking_force(dam);
    }
    else if((dam.water_level > (0.7 * dam.dam_height)) && (dam.water_level <= (0.85 * dam.dam_height)))
    {
	file_print(signal_2, msg_2);
	num = 2;
	evacuation_instructions(num);
	breaking_force(dam);
    }
    else if((dam.water_level > (0.85 * dam.dam_height)) && (dam.water_level <= (0.9 * dam.dam_height)))
    {
	file_print(signal_3, msg_3);
	num = 3;
	evacuation_instructions(num);
	breaking_force(dam);
    }   
    else if((dam.water_level > (0.9 * dam.dam_height)) && (dam.water_level <= dam.dam_height))
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




