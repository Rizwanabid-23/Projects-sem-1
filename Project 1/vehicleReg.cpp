#include<iostream>
#include<string>
#include<conio.h>
#include<stdlib.h>
using namespace std;

//strings
string username;
string password;
string reg[10];
string pin[10];
string Reg;
string Pin;
string name;
string newPin;
string owner[10];
string sOwner;
string newOwner;
string previous;
string tax[10];
string sTax;
string sImportedOwner;
string importedOwner[10];

//ints
int adminOption;
int option;
int total=0;
int counter=0;
int import=0;
int large;
int small;
int regOption;
int OP;
int idx;
int plate[10];
int sPlate;
int model[10];
int sModel;
int sImportedPlate;
int importedPlate[10];
int duplicate[10];
int final[10];

//functions
int adminMenu();
void addReg();
void storeReg(string Reg, string Pin);
void changeReg();
int regMenu();
void addVehicle();
void storeVehicle(string Owner,int Plate,int Model);
void changeOwner();
void addImported();
void storeImported(string ImportedOwner, int ImportedPlate, string Tax);
void taxFunction();
void latestFunction();
void demo_view_vehicles();
void demo_view_registrars();
void demo_view_imported();
void pressKey();

int main(){														//main function starts
	demo_view_vehicles();	
	demo_view_registrars();
	demo_view_imported();
	while(true){
	
	system("CLS");
	cout<<"                ******Vehicle Registration Center******                "<<endl;				//login screen
	cout<<endl; cout<<endl;
	cout<<"                        ***Log in screen***"<<endl;							
	cout<<endl;
	cout<<"Enter Username..."<<endl;
	cin>>username;
	
	cout<<"Enter password"<<endl;
	cin>>password;

	 for(int j=0;j<=total;j++){
	 
	  if(username=="riz" && password=="abc"){					//running a loop to check if user exists or not.
		option=0;
		while(option!=4){										// option 4 means logout
			system("CLS");
			option=adminMenu();									// function to show admin menu and take back a option
			
				if(option==1){
					system("CLS");
					addReg();									//function to add a new registrar
					pressKey();
				}
				
				
				if(option==2){
					system("CLS");
					changeReg();								//function  to change pin of a any registrar
					pressKey();
				}
				
				
				if(option==3){
					system("CLS");
					cout<<"Following registrars are enrolled: "<<endl;
					cout<<"Names"<<endl;
					cout<<"------"<<endl;
					for(int i=0;i<=total;i++){					//running a loop to print all enrolled registrars
						cout<<endl;
						cout<<reg[i]<<endl;
					}
				pressKey();
				}
				
				if(option>4 || option<1){
					cout<<"You have entered wrong option"<<endl;
					pressKey();
				}
			}
	}
	 else if(username==reg[j] && password==pin[j]){
	 			//for registrars only
		OP=0;
		while(OP!=8){										//option 9 means logout
				
			system("CLS");
		 	OP=regMenu();									//function to show menu of registrar and take a option
		 		
		 	if(OP==1){
		 		system("CLS");
		 		addVehicle();								//function to add a new vehicle
		 		pressKey();
				 }
				 
			if(OP==2){
			 	system("CLS");
				changeOwner();								//function to change the owner of vehicle
				pressKey();
					}
	
			if(OP==3){
			 	system("CLS");
			 	cout<<"Following vehicles are registered "<<endl;
			 	cout<<endl;
			 	cout<<"Owner"<<"\t"<<"Number plate"<<"\t"<<"Model year"<<endl;
			 	for(int m=0;m<counter;m++){										     //a loop to print all the registered vehicles along their numberplates and model year
				 	cout<<owner[m]<<"\t"<<plate[m]<<"\t"<<"\t"<<model[m]<<endl;
				 		
					 }
				pressKey();
				 }
				 
			if(OP==4){
				system("CLS");
				cout<<"Owner"<<"\t"<<"Plate number"<<"\t"<<"Model year"<<endl;
				cout<<"-----"<<"\t"<<"------------"<<"\t"<<"----------"<<endl;
				for( int r=0; r<counter; r++){
				latestFunction();								//function to sort vehicles with latest being first
				}
				pressKey();
				}

		 	 if(OP==5){
		 	 	system("CLS");
		 	 	addImported();								  //function to add an imported vehicle to record
	
		 		pressKey();
				 }
	
				 
			 if(OP==6){
			 	system("CLS");
			 	cout<<"Following imported vehicles are registered: "<<endl;
				cout<<"Owner"<<"\t"<<"Number plate"<<"\t"<<"Tax paid"<<endl;
				cout<<"-----"<<"\t"<<"------------"<<"\t"<<"--------"<<endl;
				for(int h=0;h<import;h++){					//a loop to print all registered imported vehicles
					
				
				cout<<importedOwner[h]<<"\t"<<importedPlate[h]<<"\t"<<"\t"<<tax[h]<<endl;
				}
				pressKey();
			 }	 
			 
			 			 
			 if(OP==7){
			 	system("CLS");
			 	taxFunction();								//function to detect any tax defaulter in imported vehicles
				pressKey();
				}
				
			if(OP>8 || OP<1){
				cout<<"You have entered wrong information"<<endl;
				pressKey();
			}
		}
	}
		else if((username!=reg[j] && password!=pin[j]) || (username!="riz" && password!="abc"))	{
		cout<<"You entered wrong information"<<endl;
		pressKey();
		}		 
	}	

}
      	 	 
}															//main function ends

//other functions:

int adminMenu(){
	cout<<"                    Admin menu           "<<endl;
	cout<<"                 ---------------         "<<endl;
	cout<<endl;
	cout<<"1: Add a registrar"<<endl;
	cout<<"2: Change password of registrar"<<endl;
	cout<<"3: View all registrars"<<endl;
	cout<<"4: Log out"<<endl;
	cout<<endl;
	cout<<"Enter your option  "<<endl;
	cin>>adminOption;
	return adminOption;
}

void addReg(){										//information of registrar is being stored
	cout<<"Add a new registrar."<<endl;
	cout<<endl;
	cout<<"Enter name..."; 
	cin>>Reg;
	cout<<endl;
				
	cout<<"Enter pin...";
	cin>>Pin;
	storeReg(Reg, Pin);
}

void storeReg(string Reg, string Pin){
	reg[total]=Reg;
	pin[total]=Pin;
	total=total+1;				//total is being incremented to store a new value every time		
}

void changeReg(){
	cout<<"Change pin of a registrar"<<endl;
	cout<<endl;
	cout<<"Enter name of registrar...";
	cin>>name;
				
	cout<<"Enter new pin of registrar...";
	cin>>newPin;
	for(int i=0;i<=total;i++ ){
		if(name==reg[i]){
			pin[i]=newPin;		
		}	
	}
}

int regMenu(){	
	cout<<"1: Add a vehicle"<<endl;
	cout<<"2: Change vehicle owner"<<endl;
	cout<<"3: View all vehicles"<<endl;
	cout<<"4: Sort vehicles with latest being first"<<endl;
	cout<<"5: Register an imported vehicle"<<endl;
	cout<<"6: View all imported vehicles"<<endl;
	cout<<"7: View imported cars tax defaulters"<<endl;
	cout<<"8: Log out"<<endl;
	cout<<endl;
	cout<<"Select an option...";
	cin>>regOption;	
	return regOption;	
}

void addVehicle(){	
		 		cout<<"Add a vehicle"<<endl;
		 		cout<<"--------------"<<endl;
	 			cout<<endl;
	 			cout<<"Enter owner name...";
	 			cin>>sOwner;
				cout<<endl;
	 			
				cout<<"Enter number plate of vehicle...";
	 			cin>>sPlate;
	 			if(sPlate>9999){
	 				cout<<"You have entered an invalid number"<<endl;
				 }
				cout<<endl;
	 			
				cout<<"Enter model year...";
	 			cin>>sModel;       
	            storeVehicle(sOwner, sPlate, sModel);
}

void storeVehicle(string Owner,int Plate,int Model){
	owner[counter]=Owner;
	plate[counter]=Plate;
	model[counter]=Model;
	counter++;										//counter is being incremented to store a new value every time
		            
	for(int h=0; h<=counter; h++){					//the array "model" is copied into "duplicate"
	duplicate[h]=model[h];
	}
}

void changeOwner(){
			cout<<"Change owner "<<endl;
			cout<<endl;
			cout<<"Enter previous owner name...";
			cin>>previous;
			
			cout<<"Enter new owner name...";
			cin>>newOwner;
			
			for(int i=0;i<=counter;i++){
				if(previous==owner[i]){
					owner[i]=newOwner;
				}
			}
	}

void addImported(){
		 	 system("CLS");
	 		 cout<<"*Registring an imported vehicle*"<<endl;
	 		 cout<<endl;
			 cout<<"Enter owner name...";
	 		 cin>>sImportedOwner;
	 			
	 		 cout<<"Enter plate number...";
	 		 cin>>sImportedPlate;
	 			
	 		 cout<<"Is tax paid? (yes/no)  ";
	 		 cin>>sTax;
	 		 
	 		 storeImported(sImportedOwner, sImportedPlate, sTax);
}

void storeImported(string ImportedOwner, int ImportedPlate, string Tax){
	importedOwner[import]=ImportedOwner;
	importedPlate[import]=ImportedPlate;
	tax[import]=Tax;
	
	import=import+1;								//import is being incremented to store a new value every time	
}

void taxFunction(){
		 	cout<<"The tax defaulters of imported vehicles are:"<<endl;
		 	cout<<endl;
		 	cout<<"Owner"<<"\t"<<"Plate number"<<endl;
		 	cout<<"-----"<<"\t"<<"------------"<<endl;
		for(int h=0;h<=import;h++){
				
	 		if(tax[h]=="no"){									//a mirror  example of boolian operation to detect tax defaulters
				cout<<importedOwner[h]<<"\t"<<importedPlate[h]<<endl;
			}
		}
}

void latestFunction(){							//sorting with latest vehicle being first
		int p;
		int f;
		int l;
		large=-100;							   //initializing a very small value to compare
	for(p=0; p<=counter; p++){					//main loop
		for(f=0; f<=counter; f++){				//nested loop
			if(duplicate[f]>large){				//comparing every value with large
				large=duplicate[f];				//if comparison successful, store its value in large
				idx=f;							//also store the index of obtained value
			}
		}
		final[p]=idx;							//store the indexes of obtained values in another array Final
		duplicate[idx]=-1;						//replace the original value with -1 so that it can be ignored next time
	}
	for(int x=0; x<1; x++){						//last loop to print out the sorted vehicles
		idx=final[x];
		cout<<owner[idx]<<"\t"<<plate[idx]<<"\t"<<"\t"<<model[idx]<<endl;
	}
	idx=0;
}

void demo_view_registrars(){	
	storeReg("ali", "xyz");
}

void demo_view_vehicles(){
	storeVehicle("Umair",786,2018);
	storeVehicle("Musawir",1234,2019);
	storeVehicle("Riaz", 1122,2011);
}

void demo_view_imported(){
	storeImported("laeeq", 7, "yes");
	storeImported("abid",15,"yes");
	storeImported("lateef",2547,"no");
	storeImported("saad",7812,"no");
	}
	
void pressKey(){	
	cout<<"Press any key to continue..."<<endl;
	getch();
}

