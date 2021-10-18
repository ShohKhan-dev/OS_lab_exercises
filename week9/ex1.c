#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

typedef struct Page{
	char ctr;
	int numb;
	int ref;
} Page;

int leastOne(Page *table){
	unsigned int min = 4294967296/2 - 1;
	int n = 0;
	for(int i = 0; i<MAX; i++){
		if (table[i].ctr < min){
			min = table[i].ctr;
			n = i;
		}
	}
	return n;
}
int is_hit(Page *table, int p_n){
	for(int i = 0; i<MAX; i++){
		if (table[i].numb == p_n){
			return p_n;
		}
	}
	return 0;
}
void shiftAll(Page *table){
	for(int i = 0; i<MAX; i++){
		table[i].ctr = table[i].ctr >> 1;
		table[i].ref = 0;
	}
}

int main(){
	int page_number = 0, m = 0, first_available = 0;
	int page_index = 0, i = 0;
	Page *table;
	table = malloc(sizeof(Page)*MAX);
	for (int i = 0; i<MAX; i++){
		table[i].ctr = 0;
		table[i].ref = 0;
		table[i].numb = 0;
	}
	int hit = 0;
	int miss = 0;
	FILE* file = fopen("input.txt", "r");
	while (!feof(file)){
		fscanf(file,"%d", &page_number);
		i++;
		if  (i >= 1001) break;
		printf("index: %d page number: %d\n", i, page_number);
		shiftAll(table);
		if (page_index = is_hit(table,page_number)){
			hit++;
			table[page_index].ref = 1;
			table[page_index].ctr = table[page_index].ctr | (1<<7);
		} else {
			if (first_available < MAX ){
			table[first_available].ctr = 1 << 7;
			table[first_available].ref = 1;
			table[first_available].numb = page_number;
			miss++;
			first_available++;
			} else {
				m = leastOne(table);
				table[m].ctr = (1 << 7);
				table[m].ref = 1;
				table[m].numb = page_number;
				miss++;
			}
		}
	
	}

	printf("Hit rate %d\n", hit);
	printf("Miss rate %d\n", miss);
	fclose(file);
}
