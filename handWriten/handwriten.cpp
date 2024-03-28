#include<iostream>
#include<fstream>
#include<math.h>
#include<iomanip>
using namespace std;

//khoi tao lop sample
const int dimensionalityX = 18;
const int dimensionalityY = 24;
struct Sample{
	bool point[dimensionalityY][dimensionalityX];
};

//khai bao mang training set
const int sampleInt = 100;
const int classNumber = 10; // number of class [0, 9]
Sample trainingSets[classNumber][sampleInt];

//khai bao test sample
Sample testSample;

//nhap toan bo file class 0-9
void nhap(){
	string location = "class0.txt";//dia chi file training dataset class0
	char number = 48; 
	do{
		string temp = "";
		temp+= number;
		location.replace(5, 1, temp);
		ifstream ip(location.c_str());
		for(int i=0;i<sampleInt;i++)
			for(int j = 0; j < dimensionalityY; j++)
				for(int k =0; k<dimensionalityX; k++)
					ip>>trainingSets[number-48][i].point[j][k];
		ip.close();
		number+=1;
	}while(number<58);
}

//xuat training voi input class
void xuatTrainingSet(int classPointer){
	for(int i=0;i<sampleInt;i++)
		for(int j = 0; j < dimensionalityY; j++){
			for(int k =0; k<dimensionalityY; k++){
				cout<<trainingSets[classPointer][i].point[j][k];
			}
			cout<<endl;
		}
}
//xuat test voi input sample
void xuatTestSample(Sample sampleIn){
	for(int i = 0; i < dimensionalityY; i++){
		for(int j = 0; j<dimensionalityX; j++){
			cout<<sampleIn.point[i][j];
		}
		cout<<endl;
	}
}

void bayesAlgorhythm(){
	long double finalProbability[classNumber]; //xac xuat co the cua toan bo class
	long double finalExecuteProbabilityCounter[dimensionalityY][dimensionalityX]; // dem so lan xuat hien moi feature trong training
	int currentIndexfinalProbability=0; // class index
	
	for(int i =0; i < classNumber; i++) finalProbability[i]=1;
	for(int currentIndexfinalProbability =0 ; currentIndexfinalProbability < classNumber; currentIndexfinalProbability++){
		for (int j = 0; j < dimensionalityY; j++) {
		    for (int k = 0; k < dimensionalityX; k++) {
		        finalExecuteProbabilityCounter[j][k] = 0;
		    }
		}
		for(int i=0;i<sampleInt;i++){
			for(int j = 0; j < dimensionalityY; j++){
				for(int k =0; k<dimensionalityX; k++){
					if(trainingSets[currentIndexfinalProbability][i].point[j][k] == testSample.point[j][k]){
						finalExecuteProbabilityCounter[j][k] += 1;
					}
				}
			}
		}
		for(int i = 0;i<dimensionalityY;i++){
			for(int j=0;j<dimensionalityX; j++){
				cout<<finalExecuteProbabilityCounter[i][j]<<" ";
			}
			cout<<endl;
		}
		for(int i = 0;i<dimensionalityY;i++){
			for(int j=0;j<dimensionalityX; j++){
				finalProbability[currentIndexfinalProbability]*= ((long double)finalExecuteProbabilityCounter[i][j]/(long double)sampleInt);
			}
		}
	}
	
	cout<<"xac xuat cuoi cung: "<<endl;
	for(int i =0;i<classNumber;i++){
		cout<<fixed<<setprecision(200)<<"class"<<i<<": "<<finalProbability[i]<<endl;
	}
	int finger = 0;
	long double max = finalProbability[0];
	for(int i =1;i<classNumber;i++){
		if(max< finalProbability[i]){
			finger = i;
			max = finalProbability[i];
		}
	}
	cout<<"vay class cua test sample la: "<<finger;
}
main(){
	nhap();
	testSample = trainingSets[9][1]; // gan test set la phan tu class 0 dau tien
	xuatTestSample(testSample);
	bayesAlgorhythm();
	getchar();
}
