#include <stdio.h>

float roundRobin(int jobs[], int length, int timeQuantum){
	int jobsCopy[length]; //Kopie des uebergebenen Arrays
	int waitTimes[length];
	float avgTime;
	int remainingTime = 1;
	float totalProcessingTime = 0;
	float totalWaitTime = 0;
	int i, n, x; 
	
	for(i = 0; i < length; i++){
		jobsCopy[i] = jobs[i];
	}
	
	for(i = 0; i < length; i++){
		waitTimes[i] = 1;	
	}
	
	
	while(remainingTime > 0){
		for(i = 0; i < length; i++){
			for(n = 0; n < timeQuantum && jobsCopy[i] > 0; n++){
				jobsCopy[i] -= 1;
				for(x = 0; x < length; x++){
					if(jobsCopy[x] > 0){
						waitTimes[x] += 1;
					}
				}
			}
		}
		remainingTime = 0;
		for(i = 0; i < length; i++){
			remainingTime += jobsCopy[i];
		}
	}
	
	
	for(i = 0; i < length; i++){
		totalWaitTime += waitTimes[i];
		totalProcessingTime += jobs[i];
	}
	
	avgTime = (totalWaitTime - totalProcessingTime)/(float)length;
	
	printf("\t%.3d  |\t", timeQuantum);
	for(i = 0; i < length; i++){
		printf("%.2d\t", waitTimes[i]);
	}
	printf("|  %.3f\n", avgTime);
	
	return avgTime;
}

void roundRobinTable(int jobs[], int length, int quantum){
	int x;
	float lowestAvg = -1.0;
	float avgTime;
	printf("#\tQ\t");
	for(x = 1; x <= length; x++){
		printf("P%d\t", x);
	}
	printf("   Avg.Time\n#");
	
	for(x = 0; x < 8*(length+3)+2; x++){
		printf("-");
	}
	printf("\n");
	
	for(x = 1; x <= quantum; x++){
		avgTime = roundRobin(jobs, length, x);
		if(lowestAvg == -1.0 || avgTime < lowestAvg){
		lowestAvg = avgTime;
		}
	}
	printf("#");
	for(x = 0; x < 8*(length+3)+2; x++){
		printf("-");
	}
	printf("\n");
	printf("#\tQ\t");
	for(x = 1; x <= length; x++){
		printf("P%d\t", x);
	}
	printf("   Avg.Time(low: %.3f)\n", lowestAvg);
	
	
	
	
}
int main(){
	int jobs[] = {6, 13, 7, 3, 4, 900, 10, 11, 24};
	roundRobinTable(jobs, 9, 100);
	
	
	return 0;
}