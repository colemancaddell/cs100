#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "functions.h"


int getColumnNumber (char *str){
	if (strcmp(str,"street")==0)
		return 0;
	if (strcmp(str,"city")==0)
		return 1;
	if (strcmp(str,"zip")==0)
		return 2;
	if (strcmp(str,"state")==0)
		return 3;
	if (strcmp(str,"beds")==0)
		return 4;
	if (strcmp(str,"baths")==0)
		return 5;
	if (strcmp(str,"sq_ft")==0)
		return 6;
	if (strcmp(str,"type")==0)
		return 7;
	if (strcmp(str,"sale_date")==0)
		return 8;
	if (strcmp(str,"price")==0)
		return 9;
	if (strcmp(str,"latitude")==0)
		return 10;
	if (strcmp(str,"longitude")==0)
		return 11;
	return -1;
}

int isPerformOperatorNeeded (char * columnName){
	if(strcmp(columnName, "beds")==0) return 1;
	else if(strcmp(columnName, "baths")==0) return 1;
	else if(strcmp(columnName, "price")==0) return 1;
	else return 0;
}

int performOperatorInteger (char * csvValue, char * operator, char * testValue){
	int csvValueInt = atoi(csvValue);
	int testValueInt = atoi(testValue);
	if (strcmp(operator, "==")==0){
		if (csvValueInt == testValueInt) return 1;
		else return 0;
	}
	if (strcmp(operator, ">=")==0){
		if (csvValueInt >= testValueInt) return 1;
		else return 0;
	}
	if (strcmp(operator, "<=")==0){
		if (csvValueInt <= testValueInt) return 1;
		else return 0;
	}
	if (strcmp(operator, "<")==0){
		if (csvValueInt < testValueInt) return 1;
		else return 0;
	}
	if (strcmp(operator, ">")==0){
		if (csvValueInt > testValueInt) return 1;
		else return 0;
	}
	if (strcmp(operator, "!=")==0){
		if (csvValueInt != testValueInt) return 1;
		else return 0;
	}
	return -1;
}


int performOperator(char * csvValue, char * operator, char * testValue, char * columnName){		//FINISH isOperatorNeeded
	
	if (strcmp(operator,"==")==0){
		//isoperatorNeeded(columnName) return performOperatorInteger;
		if (strcmp(csvValue,testValue) == 0) return 1;
			else return 0;
	}
	else if (strcmp(operator,">=")==0){
		//isoperatorNeeded(columnName) return performOperatorInteger;
		if (strcmp(csvValue,testValue) >= 0) return 1;
			else return 0;
		}
	else if (strcmp(operator,"<=")==0){
		//isoperatorNeeded(columnName) return performOperatorInteger;
		if (strcmp(csvValue,testValue) <= 0) return 1;
			else return 0;
		}
	else if (strcmp(operator,"<")==0){
		//isoperatorNeeded(columnName) return performOperatorInteger;
		if (strcmp(csvValue,testValue) < 0) return 1;
			else return 0;
		}
	else if (strcmp(operator,">")==0){
		//isoperatorNeeded(columnName) return performOperatorInteger;
		if (strcmp(csvValue,testValue) > 0) return 1;
			else return 0;
		}
	else if (strcmp(operator,"!=")==0){
		//isoperatorNeeded(columnName) return performOperatorInteger;
		if (strcmp(csvValue,testValue) != 0) return 1;
			else return 0;
		}
	return -1;
}


int testFunction (char **cells, int testc, char **testv){	//FINSIH
	int result = 0;
	int column = 0;
	for(int i = 0; i < testc; i++){
		column = getColumnNumber(testv[3*i]);		
		result = performOperator(cells[column],testv[(3*i)+1],testv[(3*i)+2],testv[3*i]);
		if (result == 0) return 0;
	}
	return 1;	
}



void printAddr(char csvfile[], int testc, char *testv[]){
	
	FILE *fp;
    fp = fopen(csvfile, "r");
    int size = 300;
	char contents[size];
	char * words;
	char * row;
	char ** cells;
	int i = 1;
	fgets(contents, size, fp);
	while (!feof(fp)){
		cells = malloc (sizeof(char *) * 12);
		for (int i  = 0; i < 12; i++){
			cells[i] = malloc(sizeof(char)*100);
		}
		row = fgets(contents, size, fp);
		if (row != NULL){
			//printf("%s\n", row);	
			int i = 0;
			while( (words = strsep(&row,",")) != NULL ){
				strcpy(cells[i],words);
				i++;
			}
		}
			
			/* Do stuff */
			int result = testFunction(cells, testc, testv);	//FINISH
			if (result == 1){
				printf("%d: %s, %s, %s %s \n",i, cells[0], cells[1], cells[3], cells[2]);
				i++;
			}
			
		}
	
	
	printf("DONE");
	
return;
}


void printCoor(char csvfile[], int testc, char *testv[]){	//FIX () ERROR

	FILE *fp;
    fp = fopen(csvfile, "r");
    int size = 300;
	char contents[size];
	char * words;
	char * row;
	char ** cells;
	int i = 1;
	fgets(contents, size, fp);
	while (!feof(fp)){
		cells = malloc (sizeof(char *) * 12);
		for (int i  = 0; i < 12; i++){
			cells[i] = malloc(sizeof(char)*100);
		}
		row = fgets(contents, size, fp);
		if (row != NULL){
			//printf("%s\n", row);	
			int i = 0;
			while( (words = strsep(&row,",")) != NULL ){
				strcpy(cells[i],words);
				i++;
			}
		}
			
			/* Do stuff */
			int result = testFunction(cells, testc, testv);	//FINISH
				if (result == 1){
					cells[11][(int)strlen(cells[11])-2]='\0';
					if (strcmp(cells[10], "")!=0){
						printf("%d: (%s, %s)\n",i, cells[10], cells[11]);
						i++;
					}
				}
			
		}
	
	
	printf("DONE");
	
return;
}

int getCount(char csvfile[], int testc, char *testv[]){		//FIX first count ERROR
	FILE *fp;
    fp = fopen(csvfile, "r");
    int size = 300;
	char contents[size];
	char * words;
	char * row;
	char ** cells;
	int i = 1;
	int count = 0;
	fgets(contents, size, fp);
	while (!feof(fp)){
		cells = malloc (sizeof(char *) * 12);
		for (int i  = 0; i < 12; i++){
			cells[i] = malloc(sizeof(char)*100);
		}
		row = fgets(contents, size, fp);
		if (row != NULL){
			//printf("%s\n", row);	
			int i = 0;
			while( (words = strsep(&row,",")) != NULL ){
				strcpy(cells[i],words);
				i++;
			}
		}
			
			/* Do stuff */
			int result = testFunction(cells, testc, testv);	//FINISH
			if (result == 1){
				count ++;
				//printf("There are %d records", count);
				i++;
			}
			
		}
	
	
	printf("DONE");
	
return count;
}

void getMin(char csvfile[], char column[], int testc, char *testv[], double *pMin, int *pCount){
	FILE *fp;
    fp = fopen(csvfile, "r");
    int size = 300;
	char contents[size];
	char * words;
	char * row;
	char ** cells;
	int i = 1;
	int count = 0;
	int min;
	fgets(contents, size, fp);
	while (!feof(fp)){
		cells = malloc (sizeof(char *) * 12);
		for (int i  = 0; i < 12; i++){
			cells[i] = malloc(sizeof(char)*100);
		}
		row = fgets(contents, size, fp);
		if (row != NULL){
			//printf("%s\n", row);	
			int i = 0;
			while( (words = strsep(&row,",")) != NULL ){
				strcpy(cells[i],words);
				i++;
			}
		}
			
			/* Do stuff */
			int result = testFunction(cells, testc, testv);	
			if (result == 1){
				count ++;
				i++;
			int min=cells[i];
			for (int i=0; i < size; i++){
				if (cells[i] < min) min = cells[i];
			}
			
		}
	}
		*pMin = min;
		*pCount = count;
		printf("DONE");
return;
}

void getMax(char csvfile[], char column[], int testc, char *testv[], double *pMin, int *pCount){
return;
}

void getAvg(char csvfile[], char column[], int testc, char *testv[], double *pAvg, int *pCount){

return;
}




char _commands[6][20]={
"addr",
"coor",
"count",
"min",
"max",
"avg"
};

char _col_names[12][20]={
"street",
"city",
"zip",
"state",
"beds",
"baths",
"sq_ft",
"type",
"sale_date",
"price",
"latitude",
"longitude"
};

// 0: string; 1: number
int  _col_types[12]={0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1};

char _ops[6][20]={
"==",
"!=",
">=",
"<=",
">",
"<"
};

void printHelp()
{
    printf("\nThe valid commands:\n\n");
    printf("\taddr\n");
    printf("\t*** print all addresses\n");
    printf("\taddrN\n");
    printf("\t*** print all addresses that satisfy all N conditions specified below\n");
    printf("\t*** for example: addr2\n");
    printf("\tcoor\n");
    printf("\t*** print all coordinates (latitude and longitude)\n");
    printf("\tcoorN\n");
    printf("\t*** print all coordinates that satisfy all N conditions specified below\n");
    printf("\t*** for example: coor1\n");
    printf("\tcount\n");
    printf("\t*** print the number of all records\n");
    printf("\tcountN\n");
    printf("\t*** print the number of all records that satisfy all N conditions specified below\n");
    printf("\t*** for example: count3\n");
    printf("\tmin column\n");
    printf("\t*** find the minimum of the specified column, excluding blanks\n");
    printf("\t*** for example: min beds\n");
    printf("\tminN column\n");
    printf("\t*** find the minimum of the specified column from the records that satisfy all N conditions specified below\n");
    printf("\t*** for example: min2 price\n");
    printf("\tmax column\n");
    printf("\t*** find the maximum of the specified column, excluding blanks\n");
    printf("\t*** for example: max baths\n");
    printf("\tmaxN column\n");
    printf("\t*** find the maximum of the specified column from the records that satisfy all N conditions specified below\n");
    printf("\t*** for example: max3 price\n");
    printf("\tavg column\n");
    printf("\t*** find the average of the specified column, excluding blanks\n");
    printf("\t*** for example: avg price\n");
    printf("\tavgN column\n");
    printf("\t*** find the average of the specified column from the records that satisfy all N conditions specified below\n");
    printf("\t*** for example: avg2 price\n");
    printf("\tquit\n");
    printf("\t*** quit this program\n");
    printf("\thelp\n");
    printf("\t*** print this list\n");

    printf("\nEach condition shall be entered in one line and of the following format:\n");
    printf("\n\tcolumn op value\n\n");
    printf("\t*** for example: price >= 100000\n");
    printf("\n\tThe valid columns:\n");
	for (int i=0; i<12; i++) printf("\t\t%s\n", _col_names[i]);
    printf("\n\tThe valid operators:\n");
	for (int i=0; i<6; i++) printf("\t\t%s\n", _ops[i]);
    printf("\n");
}

void removeWhiteSpacesAtEnds(char str[])
{
	int len;
	len=strlen(str);
	for (int i=len-1; i>=0; i--) {
		if (!isspace(str[i])) break;
		str[i]='\0';
	}

	len=strlen(str);
	int numLeading=0;
	for (int i=0; i<len; i++) {
		if (!isspace(str[i])) break;
		numLeading++;
	}

	if (numLeading>0) {
		for (int i=0; i<len; i++) {
			if (i<len-numLeading)
				str[i]=str[i+numLeading];
			else
				str[i]='\0';
		}
	}
}

// return -1 if invalid
int isValidCommand(char cmd[])
{
    for (int i=0; i<6; i++) {
        if (strcmp(_commands[i], cmd)==0) return i;
    }
    return -1;
}

// return -1 if invalid
int isValidColumn(char column[])
{
	for (int i=0; i<12; i++) {
		if (strcmp(_col_names[i], column)==0) return i;
	}
	return -1;
}


// return 1 if it is a valid numeric column
int isNumericColumn(char column[])
{
	int index=isValidColumn(column);
	if (index<0)
		return 0;
	else
		return _col_types[index];
}

int isValidOp(char op[])
{
	for (int i=0; i<6; i++) {
		if (strcmp(_ops[i], op)==0) return i;
	}
	return -1;
}

char **getTestConditions(int testc)
{
    char line[300];
	char **testv=malloc(3*testc*sizeof(int *));
	int i=0;
	while (i<testc) {
		printf("Enter test condition #%d: ", i+1);
		char col_name[100];
		scanf("%s", col_name);
		if (isValidColumn(col_name)<0) {
            printf("%s: invalid column.\n", col_name);
            fgets(line, 300, stdin); // skip the rest of line
			continue;
		}	
		char op[100];
		scanf("%s", op);
		if (isValidOp(op)<0) {
            printf("%s: invalid operator.\n", op);
            fgets(line, 300, stdin); // skip the rest of line
			continue;
		}	
		testv[3*i]=malloc(strlen(col_name)+1);
		strcpy(testv[3*i], col_name);
		testv[3*i+1]=malloc(strlen(op)+1);
		strcpy(testv[3*i+1], op);
    	char ref_str_val[300];
		fgets(ref_str_val, 300, stdin);
		removeWhiteSpacesAtEnds(ref_str_val);
		testv[3*i+2]=malloc(strlen(ref_str_val)+1);
		strcpy(testv[3*i+2], ref_str_val);
		i++;
	}
	return testv;
}

void releaseTestConditions(int testc, char *testv[])
{
	for (int i=0; i<3*testc; i++) free(testv[i]);
}

int split(char command[], char cmd[], int *pNum)
{
	int len=strlen(command);
	int i;
	for (i=0; i<len; i++) {
		if (isdigit(command[i])) break;
	}
	strncpy(cmd, command, i);
	cmd[i]='\0';
	if (isValidCommand(cmd)<0) return 0;

	int j;
	for (j=i; j<len; j++) {
		if (!isdigit(command[j])) break;
	}
	if (j<len) return 0;

	if (i==len)
		*pNum=0;
	else
		sscanf(command+i, "%d", pNum);
	return 1;
}

int main(int argc, char *argv[])
{
    if (argc!=2) {
        printf("Usage: %s csvfile\n", argv[0]);
        return 1;
    }
    FILE *fp=fopen(argv[1], "r");
    if (fp==NULL) {
        printf("Unable to open %s for reading\n", argv[1]);
        return 2;
    }
    fclose(fp);

    while (1) {
        char command[30];
        char cmd[30];
		int testc=0;
        char column[30];
        char line[300];
        printf("\nEnter a command: ");
        scanf("%s", command);
        if (strcmp(command, "quit")==0) break;
        if (strcmp(command, "help")==0) {
            printHelp();
			continue;
        }
		if (split(command, cmd, &testc)==0) {
            printf("%s: invalid commmand.\n", command);
            fgets(line, 300, stdin); // skip the rest of line
			continue;
		}
        if (strcmp(cmd, "addr")==0) {
			char **testv=getTestConditions(testc);
			printAddr(argv[1], testc, testv);
			releaseTestConditions(testc, testv);
        }
        else if (strcmp(cmd, "coor")==0) {
			char **testv=getTestConditions(testc);
			printCoor(argv[1], testc, testv);
			releaseTestConditions(testc, testv);
        }
        else if (strcmp(cmd, "count")==0) {
			char **testv=getTestConditions(testc);
			int count=getCount(argv[1], testc, testv);
            printf("\nThere are %d records\n", count);
			releaseTestConditions(testc, testv);
        }
        else if (strcmp(cmd, "min")==0) {
            scanf("%s", column);
			if (isNumericColumn(column)) {
				char **testv=getTestConditions(testc);
            	double min;
				int count;
				getMin(argv[1], column, testc, testv, &min, &count);
				if (count>0)
            		printf("\nAmong %d eligible properties, min(%s)=%g\n", count, column, min);
				else
            		printf("\nThere are no eligible properties\n");
				releaseTestConditions(testc, testv);
			}
			else {
            	printf("%s: invalid or non-numeric column.\n", column);
            	fgets(line, 300, stdin); // skip the rest of line
			}
        }
        else if (strcmp(cmd, "max")==0) {
            scanf("%s", column);
			if (isNumericColumn(column)) {
            	char **testv=getTestConditions(testc);
            	double max;
            	int count;
            	getMax(argv[1], column, testc, testv, &max, &count);
            	if (count>0)
                	printf("\nAmong %d eligible properties, max(%s)=%g\n", count, column, max);
            	else
                	printf("\nThere are no eligible properties\n");
            	releaseTestConditions(testc, testv);
			}
			else {
            	printf("%s: invalid or non-numeric column.\n", column);
            	fgets(line, 300, stdin); // skip the rest of line
			}
        }
        else if (strcmp(cmd, "avg")==0) {
            scanf("%s", column);
			if (isNumericColumn(column)) {
            	char **testv=getTestConditions(testc);
            	double avg;
            	int count;
            	getAvg(argv[1], column, testc, testv, &avg, &count);
            	if (count>0)
                	printf("\nAmong %d eligible properties, avg(%s)=%g\n", count, column, avg);
            	else
                	printf("\nThere are no eligible properties\n");
            	releaseTestConditions(testc, testv);
			}
			else {
            	printf("%s: invalid or non-numeric column.\n", column);
            	fgets(line, 300, stdin); // skip the rest of line
			}
        }
    }
    return 0;
}
