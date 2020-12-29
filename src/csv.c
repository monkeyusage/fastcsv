#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "csv.h"

rows_info_t* read_csv(const char* format, const char* file_name) {
    // connect to file
    FILE* file = fopen(file_name, "r");
    if (file == NULL) {
        printf("Error opening %s file\n", file_name);
        exit(EXIT_FAILURE);
    }

    // declare buffer for each line    
    char buffer[BUFFER_SIZE];
    // get first line of file and store it in buffer
    fgets(buffer, BUFFER_SIZE, file);

    // create array of rows on the heap
    row_t* rows = malloc(sizeof(row_t) * MAX_ROWS);
    int counter = 0;

    // use sscanf to parse line into attrs of row, read next line & incr counter
    while (!feof(file)) {
        sscanf(buffer, format, &(rows[counter]).x, &(rows[counter]).y);
        fgets(buffer, BUFFER_SIZE, file);
        counter++;
    }

    // store info on the heap
    rows_info_t* rows_info = malloc(sizeof(rows_info_t) * 1);
    rows_info->nrows = counter;
    rows_info->rows = rows;

    fclose(file);
    return rows_info;
}

void print_rows(rows_info_t* rows_info) {
    printf("num rows in table: %d\n", rows_info->nrows);
    for (int i= 0; i < rows_info->nrows; i++) {
        printf("Row: %d, x: %d, y: %d\n", i, rows_info->rows[i].x, rows_info->rows[i].y);
    }
}

void delete_rows(rows_info_t* rows_info) {
    free(rows_info->rows);
    free(rows_info);
}

int main() {
    rows_info_t* rows_info = read_csv(FORMAT, "data/hello.csv");
    print_rows(rows_info);
    delete_rows(rows_info);
    return EXIT_SUCCESS;
}