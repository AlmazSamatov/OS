#include <iostream>
#include <stdlib.h> 
#include <vector>
#include <cmath>
#include <ctime>
#include <string>
#include <queue>
#include <map>

#define SIZE_OF_PAGE_TABLE 3

using namespace std;

// This is optimal page replacement algortihm

int main(){

	int n;
	cout << "Enter number of input pages: ";
	cin >> n;
	map < int, vector < int > > m;
	vector < int > input(n);
	for(int i = 0; i < n; i++){
		cin >> input[i];
		m[input[i]].push_back(i);
	}
	vector < int > page_table(SIZE_OF_PAGE_TABLE);
	int j = 0;
	int page_faults = 0;
	for(int i = 0; i < n; i++){
		if(j == 3){
			// page table is full
			bool b = false;
			for(int y = 0; y < SIZE_OF_PAGE_TABLE; y++){
				if(page_table[y] == input[i])
					b = true;
			}
			if(!b){
				page_faults++;
				vector < int > pages_to_replace(3);
				for(int y = 0; y < SIZE_OF_PAGE_TABLE; y++){
					for(int o = 0; o < m[page_table[y]].size(); o++){
						if(m[page_table[y]][o] > i) {
							pages_to_replace[y] = m[page_table[y]][o];
							break;
						}
					}
					if(pages_to_replace[y] == 0)
						pages_to_replace[y] = 1000;
				}
				int maxi = -1, maxi_value = -1;
				for(int y = 0; y < SIZE_OF_PAGE_TABLE; y++){
					if(maxi_value < pages_to_replace[y]){
						maxi_value = pages_to_replace[y];
						maxi = y;
					}
				}
				page_table[maxi] = input[i];
			}

		} else{
			page_table[j] = input[i];
			j++;
			page_faults++;
		}

		cout << "Page table: ";
		for(int y = 0; y < SIZE_OF_PAGE_TABLE; y++){
			cout << page_table[y] << " ";
		}
		cout << endl;
	}

	cout << "Page faults: " << page_faults;
	return 0;
}