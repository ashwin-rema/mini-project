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