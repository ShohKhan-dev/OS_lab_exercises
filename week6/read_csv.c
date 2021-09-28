#include <conio.h>
#include <stdio.h>
#include <string.h>
  
// Driver Code
int main()
{

    FILE* fp = fopen("input.csv", "r");
  
    if (!fp)
        printf("Can't open file\n");
  
    else {
        char buffer[1024];
  
        int row = 0;
        int column = 0;
  
        while (fgets(buffer, 1024, fp)) {
            column = 0;
            row++;
            
            char* value = strtok(buffer, ", ");
  
            while (value) {
                // Column 1
                if (column == 0) {
                	
                    printf("Name :");
                }
  
                if (column == 1) {
                    printf("\tAccount No. :");
                }
                
                int x = atoi(value);
  
                printf("-> %s", value);
                value = strtok(NULL, ", ");
                column++;
            }
  
            printf("\n");
        }

        fclose(fp);
    }
    return 0;
}
