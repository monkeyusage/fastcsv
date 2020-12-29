#ifndef BUFFER_SIZE

#define BUFFER_SIZE 200
#define MAX_ROWS 100
#define FORMAT "%d,%d"

typedef struct row_t {
    int x;
    int y;
} row_t;

// wrapper around rows, adds num rows attr to type
typedef struct rows_info_t {
    int nrows;
    row_t* rows;
} rows_info_t;

rows_info_t* read_csv(const char* format, const char* file_name);
void print_rows(rows_info_t* rows_info);
void delete_rows(rows_info_t* rows_info);

#endif