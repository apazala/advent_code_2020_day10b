#include <cstdio>
#include <algorithm>
#include <cinttypes>

int values[105];
int64_t ways[105];
int main() {

	FILE *fin = fopen("input.txt", "r");
	if (!fin) {
		fprintf(stderr, "Can't open input file\n");
		return 1;
	}

	int nvalues = 0;

	//two initial values
	values[nvalues++] = -3;
	values[nvalues++] = 0;

	int val;
	while (fscanf(fin, "%d", &val) == 1)
	{
		values[nvalues] = val;
		nvalues++;
	}
	fclose(fin);

	std::sort(values, values + nvalues);

	//one last value
	values[nvalues] = values[nvalues - 1] + 3;
	nvalues++;
	
	ways[0] = 1;//-3 jolts sentinel
	ways[1] = 1;//0 jolts initial
	for (int i = 2; i < nvalues; i++) {
		int val = values[i];
		for (int j = i - 1; val - values[j] <= 3; j--) {
			ways[i] += ways[j];
		}		
	}

	printf("%" PRId64 "\n", ways[nvalues - 1]);

	return 0;
}