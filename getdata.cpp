/* This C++ program aims at 
1. Obtaining the multiplicity information from the "gevdump" command
2. Obtaining the types and numbers of "HadrBlob"
3. Obtaining the momentum and energy distribution of a specific final-state particle
4. Obtaining the momentum and energy distribition versus multiplicity of a specific final-state particle

Author: XU Sihong (sxubi@connect.ust.hk)
Update: July 3, 2023
*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cmath>
#include <math.h>
#include<iomanip>

using namespace std;

// A function comparing whether two strings are equal
// if equal, return true, otherwise return false
bool equal_string(string a, string b)
{
    if (a.length() != b.length())
    	return false;
    
    for (int i = 0; i < a.length(); i++)
    {
    	if (a[i] != b[i])
    	    return false;
    }
    
    return true;
}


// A structure which will be used in collecting the initial-state
// and final state particles
struct particle
{
	string particle_name;
	particle* next;
};

// A function that could delete the particle linked list
void particle_delete(particle* & head)
{
	if (head == nullptr)
		return;
	particle_delete(head->next);
	delete head;
	head = nullptr;
}

void particle_print(particle* head)
{
	for (const particle* p = head; p != nullptr; p = p->next)
	{
		cout << p->particle_name << " ";
	}
	cout << endl;
}

void particle_add(particle* head, string particle_name)
{
	particle* new_particle = new particle;
	new_particle->particle_name = particle_name;
	new_particle->next = nullptr;
	if (head == nullptr)
	{
		head = new_particle;
		return;
	}
	particle* p = nullptr;
	for (p = head; p->next != nullptr; p = p->next){}
	p->next = new_particle;
}

// charge of a particle
int charge(string particle)
{
	// charge 0 particles
	if 		((particle == "nu_mu_bar")   || (particle == " nu_e_bar") ||
			 (particle == "    nu_mu") 	 || (particle == "     nu_e") || 
			 (particle == "  neutron")   || (particle == "      pi0") || 
			 (particle == "  Lambda0")   || (particle == "   Sigma0")
		)
		return 0;
	// charge +1 particles
	else if ((particle == "       e+")    || (particle == "   proton")   ||
	         (particle == "      mu+")    || (particle == "      pi+")   ||
			 (particle == "   Sigma+")
	)
		{return 1;}
	// charge -1 particles
	else if ((particle == "       e-") || (particle == "         mu-")      ||
			 (particle == "   Sigma-") || (particle == "         pi-")      ||
			 (particle == "   Delta-") || (particle == "      Omega-")   
	)
		return -1;
	else if (particle == "C12")
		return 6;
	return 0;
}

void reset_array(string array[], int length )
{
	for (int i = 0; i < length; i++){
		array[i] = "0";}
}

void operating_isotopes(int num_hadrblob_proton, int num_hadrblob_neutron, int Hydrogen[], int Helium[],
int Lithium[], int Beryllium[], int Boron[], int Carbon[])
{
	if (num_hadrblob_proton == 1)
					{
						if (num_hadrblob_neutron == 0)
							Hydrogen[0] += 1;
						if (num_hadrblob_neutron == 1)
							Hydrogen[1] += 1;
						if (num_hadrblob_neutron == 2)
							Hydrogen[2] += 1;
						if (num_hadrblob_neutron == 3)
							Hydrogen[3] += 1;
						if (num_hadrblob_neutron == 4)
							Hydrogen[4] += 1;
						if (num_hadrblob_neutron == 5)
							Hydrogen[5] += 1;
						if (num_hadrblob_neutron == 6)
							Hydrogen[6] += 1;
					}
					else if (num_hadrblob_proton == 2)
					{
						if (num_hadrblob_neutron == 1)
							Helium[0] += 1;
						if (num_hadrblob_neutron == 2)
							Helium[1] += 1;
						if (num_hadrblob_neutron == 3)
							Helium[2] += 1;
						if (num_hadrblob_neutron == 4)
							Helium[3] += 1;
						if (num_hadrblob_neutron == 5)
							Helium[4] += 1;
						if (num_hadrblob_neutron == 6)
							Helium[5] += 1;
						if (num_hadrblob_neutron == 7)
							Helium[6] += 1;	
						if (num_hadrblob_neutron == 8)
							Helium[7] += 1;	
					}
					else if (num_hadrblob_proton == 3)
					{
						if (num_hadrblob_neutron == 0)
							Lithium[0] += 1;
						if (num_hadrblob_neutron == 1)
							Lithium[1] += 1;
						if (num_hadrblob_neutron == 2)
							Lithium[2] += 1;
						if (num_hadrblob_neutron == 3)
							Lithium[3] += 1;
						if (num_hadrblob_neutron == 4)
							Lithium[4] += 1;
						if (num_hadrblob_neutron == 5)
							Lithium[5] += 1;
						if (num_hadrblob_neutron == 6)
							Lithium[6] += 1;
						if (num_hadrblob_neutron == 7)
							Lithium[7] += 1;
						if (num_hadrblob_neutron == 8)
							Lithium[8] += 1;
						if (num_hadrblob_neutron == 9)
							Lithium[9] += 1;
					}
					else if (num_hadrblob_proton == 4)
					{
						if (num_hadrblob_neutron == 1)
							Beryllium[0] += 1;
						if (num_hadrblob_neutron == 2)
							Beryllium[1] += 1;
						if (num_hadrblob_neutron == 3)
							Beryllium[2] += 1;
						if (num_hadrblob_neutron == 4)
							Beryllium[3] += 1;
						if (num_hadrblob_neutron == 5)
							Beryllium[4] += 1;
						if (num_hadrblob_neutron == 6)
							Beryllium[5] += 1;
						if (num_hadrblob_neutron == 7)
							Beryllium[6] += 1;
					if (num_hadrblob_neutron == 8)
							Beryllium[7] += 1;}
					else if (num_hadrblob_proton == 5)
					{
						if (num_hadrblob_neutron == 1)
							Boron[0] += 1;
						if (num_hadrblob_neutron == 2)
							Boron[1] += 1;
						if (num_hadrblob_neutron == 3)
							Boron[2] += 1;
						if (num_hadrblob_neutron == 4)
							Boron[3] += 1;
						if (num_hadrblob_neutron == 5)
							Boron[4] += 1;
						if (num_hadrblob_neutron == 6)
							Boron[5] += 1;
						if (num_hadrblob_neutron == 7)
							Boron[6] += 1;
					}
					else if (num_hadrblob_proton == 6)
					{
						if (num_hadrblob_neutron == 2)
							Carbon[0] += 1;
						if (num_hadrblob_neutron == 3)
							Carbon[1] += 1;
						if (num_hadrblob_neutron == 4)
							Carbon[2] += 1;
						if (num_hadrblob_neutron == 5)
							Carbon[3] += 1;
						if (num_hadrblob_neutron == 6)
							Carbon[4] += 1;
					}
}


int main() {
    ifstream file("example.txt"); 
    // Opening file in read mode
    // Note that you may change the filename here
    string line;
    int num_of_events = 0; 		//total input events
    int num_of_final = 0; 		//total final state particles for a single event
    int num_of_charged = 0 ; 	//total charged final state particles
    const int max_length = 30;
    int multiplicity[max_length] = {}; //those arrays have the a maximum length of 30
    int multiplicity_charged[max_length] = {};
    int multiplicity_uncharged[max_length]= {};
    //arrays that carry the information of multiplicity
    //if final state particles of a single event is 0, then the 
    //correspoding multiplicity is multiplicity[0], etc.
    int total_final = 0;
    int total_charged = 0;
    int total_uncharged = 0;
    int num_p_in_this_event = 0;
    int num_n_in_this_event = 0;
	int num_hadrblob = 0;
	// The arrays that store the number of isotopes
	int Hydrogen[7] = {}; 	// H, D, T, H4, H5, H6, H7
	int Helium[8] = {}; 	// He3, He4, He5, He6, He7, He8, He9, He10
	int Lithium[10] = {}; 	// Li3, Li4, Li5, Li6, Li7, Li8, Li9, Li10, Li11, Li12
	int Beryllium[8] = {}; 	// Be5, Be6, Be7, Be8, Be9, Be10, Be11, Be12
	int Boron[7]  = {}; 	// B6, B7, B8, B9, B10, B11, B12
	int Carbon[5] = {}; 	// C8, C9, C10, C11, C12
	string final_state_particle_name[100];
	reset_array(final_state_particle_name,100);
	int num_hadrblob_proton = 0;
	int num_hadrblob_neutron = 0;
	int num_hadrblob_nucleon = 0;
    if (file.is_open()) {
        // Reading every line of the file
        while (getline(file, line)) {
            string check_new_event = line.substr(0,24);
            string check_particle_1 = line.substr(0,3);
            //now we need to see if it is a new event record
            if (equal_string("|GENIE GHEP Event Record",check_new_event)) // a new event record
            {	
            	//now we need to check the number of final state particles of a single event
            	//and add to the multiplicity
            	//note that this process is for the last event record
            	num_p_in_this_event = 0;
            	num_n_in_this_event = 0;
            	if (num_of_final != 0)
            	{
            	    for (int i = 0; i < max_length; i++)
            	    {
            	        if (i == num_of_final)
            	            multiplicity[i] += 1;
            	        if (i == num_of_charged)
            	            multiplicity_charged[i] += 1;
            	        if (i == (num_of_final - num_of_charged))
            	            multiplicity_uncharged[i] += 1;
            	    }
            	}
            	total_final += num_of_final;
            	total_charged += num_of_charged;
            	total_uncharged += num_of_final-num_of_charged;
            	num_of_final = 0;
            	num_of_charged = 0;
				// Preparing for finding the initial-state and final-state particles
				// In our case, the total charge for initial-state particles is +6
				// Thus we only need to deal with the final-state particle
				
				if (num_of_events == 0){ // this means that we are now looking at the first event	
				}
				else // if not the first event, first we need to do the charge conversation calculation
				{
					int final_state_charge = 0;
					for (int i = 0; final_state_particle_name[i] != "0"; i++)
					{final_state_charge+=charge(final_state_particle_name[i]);}
					// then determine the type of hadrblob
					num_hadrblob_proton = 6 - final_state_charge;
					num_hadrblob_neutron = num_hadrblob_nucleon - num_hadrblob_proton;
					operating_isotopes(num_hadrblob_proton,num_hadrblob_neutron,Hydrogen,Helium,Lithium,Beryllium,Boron,Carbon);
					reset_array(final_state_particle_name,100);
					
				}
				num_of_events +=1;
            }
            else if (equal_string("|  ",check_particle_1))//not a new event, then count the number of final-state particles
            {
            	//need to check whether we are now at a "particle line"
            	string check_particle_2 = line.substr(0,7);
            	string check_final_state_1 = line.substr(56,2);
            	string check_final_state_2 = line.substr(62,2);
            	string check_final_state_3 = line.substr(44,2);
            	string check_hadrblob = line.substr(13,8);
            	if (!equal_string("|      ",check_particle_2) && equal_string("-1",check_final_state_1) && 
            	equal_string("-1",check_final_state_2) && !equal_string("-1",check_final_state_3)) 
            	//make sure that it's not a Nuclear Binding Energy
            	//okay, now it's a final-state particle record
            	{
				//now extract the particle numbers and add to num_of_final/num_of_charged
				num_of_final += 1;
				char sign = line[20];
				string check_proton = line.substr(15,6);
				string check_neutron = line.substr(14,7);
				if ((sign=='+') || (sign=='-') || (equal_string("proton",check_proton))) //see whether a charged particle
				{num_of_charged += 1;}
				if (equal_string("proton",check_proton))
				{num_p_in_this_event+=1;}
				if (equal_string("neutron",check_neutron))
				{num_n_in_this_event+=1;}
				if (equal_string("HadrBlob",check_hadrblob)) // check wether hadrblob
				{num_hadrblob += 1;
					char judge = line[122];
					if (judge == '.')
						num_hadrblob_nucleon = stoi(line.substr(121,1)) + 1;
					else
						num_hadrblob_nucleon = stoi(line.substr(121,2)) + 1;
				}
				else // if not a hadrblob, then add it to the linked list
				{
					int i;
					for (i = 0; final_state_particle_name[i] != "0"; i++){}
					final_state_particle_name[i] = line.substr(12,9);
				}
            }
        }
        }
		for (int i = 0; i < max_length; i++)
        {
            if (i == num_of_final)
            	 multiplicity[i] += 1;
            if (i == num_of_charged)
            	 multiplicity_charged[i] += 1;
            if (i == (num_of_final - num_of_charged))
            	 multiplicity_uncharged[i] += 1;
        }
		int final_state_charge = 0;
		for (int i = 0; final_state_particle_name[i] != "0"; i++)
		{final_state_charge+=charge(final_state_particle_name[i]);}
		// then determine the type of hadrblob
		num_hadrblob_proton = 6 - final_state_charge;
		num_hadrblob_neutron = num_hadrblob_nucleon - num_hadrblob_proton;
		operating_isotopes(num_hadrblob_proton,num_hadrblob_neutron,Hydrogen,Helium,Lithium,Beryllium,Boron,Carbon);
	    total_final += num_of_final;
        total_charged += num_of_charged;
        total_uncharged += num_of_final-num_of_charged;
        file.close(); //closing the file
		
    } 
    else {
        cout << "Unable to open file, please input a valid filename." << endl;
        return 0;}
    // calculate mean and standard deviation
    float total_final_d = total_final;
    float total_charged_d = total_charged;
    float total_uncharged_d = total_uncharged;
    float num_of_events_d=num_of_events;
    float mean_final = total_final_d/num_of_events_d;
    float mean_charged = total_charged_d/num_of_events_d;
    float mean_uncharged = total_uncharged_d/num_of_events_d;
    float dev_final = 0;
    float dev_charged = 0;
    float dev_uncharged = 0;

    for (int i = 0; i < max_length; i++)
    {
    	dev_final += sqrt(multiplicity[i]);
    	dev_charged += sqrt(multiplicity_charged[i]);
    	dev_uncharged += sqrt(multiplicity_uncharged[i]);
    }
    
    dev_final /= num_of_events_d;
    dev_charged /= num_of_events_d;
    dev_uncharged /= num_of_events_d;
    
    cout << " *************************************************************************" << endl;
    cout << " Reading completed." << endl;
    cout << " Number of total input events: " << num_of_events << endl;
    cout << " *************************************************************************" << endl;
    cout << " Please input the option command:" << endl;
    cout << " 0 - Quit;" << endl;
    cout << " 1 - Multiplicity of total, charged and uncharged final-state particles;" << endl;
    cout << " 2 - Types of final-state nuclei (HadrBlob);" << endl;
	cout << " 3 - Momentum and energy distribution for a specific final-state particle;" << endl;
	cout << " 4 - Momentum and energy versus multiplicity for a specific final-state particle." << endl;
    cout << " -------------------------------------------------------------------------" << endl;
    int option;
    while (cin >> option)
    {
    	if (option == 0)
    	    break;
    	else if (option == 1){
    	    cout << " -------------------------------------------------------------------------" << endl;
	    cout << " Multiplicity for final state particles" << endl;
	    cout << " Number of final state particles of all events: " << total_final << endl;
	    cout << " Average final state particles per event: " << mean_final << endl;
	    cout << " Standard deviation of the average number: " << dev_final << endl;
	    cout << " Denote the number of final state particles of a single event as n_i" << endl;
	    cout << " -------------------------------------------------------------------------" << endl;
	    //then we output the multiplicity information:
	    for (int i = 0; i < max_length; i++) //you may change the output number here
	    {
	    	cout << " n_" << i << " = "<< multiplicity[i] << endl;   
	    }
	    cout << " -------------------------------------------------------------------------" << endl;    
	    cout << " Denote the standard deviation of n_i as sigma_n_i" << endl;
	    cout << " -------------------------------------------------------------------------" << endl;
	    for (int i = 0; i < max_length; i++)
	    {
	    	cout << " sigma_n_" << i << " = "<< sqrt(multiplicity[i]) << endl;   
	    }
	    cout << " -------------------------------------------------------------------------" << endl;
	    cout << " Multiplicity for charged final state particles" << endl;
	    cout << " Number of final state charged particles of all events: " << total_charged << endl;
	    cout << " Average final state particles per event: " << mean_charged << endl;
	    cout << " Standard deviation of the average number: " << dev_charged << endl;
	    cout << " Denote the number of charged final state particles of a single event as n_i" << endl;
	    cout << " -------------------------------------------------------------------------" << endl;
	    for (int i = 0; i < max_length; i++)
	    {
	    	cout << " n_" << i << " = "<< multiplicity_charged[i] << endl;   
	    }
	    cout << " -------------------------------------------------------------------------" << endl;    
	    cout << " Denote the standard deviation of n_i as sigma_n_i" << endl;
	    cout << " -------------------------------------------------------------------------" << endl;
	    for (int i = 0; i < max_length; i++)
	    {
	    	cout << " sigma_n_" << i << " = "<< sqrt(multiplicity_charged[i]) << endl;   
	    }
	    cout << " -------------------------------------------------------------------------" << endl;
	    cout << " Multiplicity for uncharged final state particles" << endl;
	    cout << " Number of final state uncharged particles of all events: " << total_uncharged << endl;
	    cout << " Average final state particles per event: " << mean_uncharged << endl;
	    cout << " Standard deviation of the average number: " << dev_uncharged << endl;
	    cout << " Denote the number of uncharged final state particles of a single event as n_i" << endl;
	    cout << " -------------------------------------------------------------------------" << endl;
	    for (int i = 0; i < max_length; i++)
	    {
	    	cout << " n_" << i << " = "<< multiplicity_uncharged[i] << endl;   
	    }
	    cout << " -------------------------------------------------------------------------" << endl;    
	    cout << " Denote the standard deviation of n_i as sigma_n_i" << endl;
	    cout << " -------------------------------------------------------------------------" << endl;
	    for (int i = 0; i < max_length; i++)
	    {
	    	cout << " sigma_n_" << i << " = "<< sqrt(multiplicity_charged[i]) << endl;   
	    }
	    cout << " -------------------------------------------------------------------------" << endl;
	    cout << " Multiplicity information output completed." << endl;
	    cout << " *************************************************************************" << endl;
    	}
    	else if (option == 2){
    	    cout << " -------------------------------------------------------------------------" << endl;
			cout << " There are " << num_hadrblob << " HadrBlob(s) in all the events" << endl;
			cout << " H:    " << setw(6) << Hydrogen[0] << "; D:    " << setw(6) << Hydrogen[1] << "; T:    " << setw(6) << Hydrogen[2] << endl;
			cout << " H4:   " << setw(6) << Hydrogen[3] << "; H5:   " << setw(6) << Hydrogen[4] << "; H6:   " << setw(6) << Hydrogen[5] << endl;
			cout << " -------------------------------------------------------------------------" << endl;
			cout << " He3:  " << setw(6) << Helium[0] << "; He4:  " << setw(6) << Helium[1] << "; He5:  " << setw(6) << Helium[2] << endl;
			cout << " He6:  " << setw(6) << Helium[3] << "; He7:  " << setw(6) << Helium[4] << "; He8:  " << setw(6) << Helium[5] << endl;
			cout << " He9:  " << setw(6) << Helium[6] << "; He10: " << setw(6) << Helium[7] << ";" << endl; 
			cout << " -------------------------------------------------------------------------" << endl;
			cout << " Li3:  " << setw(6) << Lithium[0] << "; Li4:  " << setw(6) << Lithium[1] << "; Li5:  " << setw(6) << Lithium[2] << endl;
			cout << " Li6:  " << setw(6) << Lithium[3] << "; Li7:  " << setw(6) << Lithium[4] << "; Li8:  " << setw(6) << Lithium[5] << endl;
			cout << " Li9:  " << setw(6) << Lithium[6] << "; Li10: " << setw(6) << Lithium[7] << "; Li11: " << setw(6) << Lithium[8] << endl;
			cout << " Li12: " << setw(6) << Lithium[9] << ";" << endl;
			cout << " -------------------------------------------------------------------------" << endl;
			cout << " Be5:  " << setw(6) << Beryllium[0] << "; Be6:  " << setw(6) << Beryllium[1] << "; Be7:  " << setw(6) << Beryllium[2] << endl;
			cout << " Be8:  " << setw(6) << Beryllium[3] << "; Be9:  " << setw(6) << Beryllium[4] << "; Be10: " << setw(6) << Beryllium[5] << endl;
			cout << " Be11: " << setw(6) << Beryllium[6] << "; Be12: " << setw(6) << Beryllium[7] << endl;
			cout << " -------------------------------------------------------------------------" << endl;
			cout << " B6:   " << setw(6) << Boron[0] << "; B7:   " << setw(6) << Boron[1] << "; B8:   " << setw(6) << Boron[2] << endl;
			cout << " B9:   " << setw(6) << Boron[3] << "; B10:  " << setw(6) << Boron[4] << "; B11:  " << setw(6) << Boron[5] << endl;
			cout << " B12:  " << setw(6) << Boron[6] << ";" << endl;
			cout << " -------------------------------------------------------------------------" << endl;
			cout << " C8:   " << setw(6) << Carbon[0] << "; C9:   " << setw(6) << Carbon[1] << "; C10:  " << setw(6) << Carbon[2] << endl;
			cout << " C11:  " << setw(6) << Carbon[3] << "; C12:  " << setw(6) << Carbon[4]  << ";" << endl;
			cout << " -------------------------------------------------------------------------" << endl;
			cout << " The output of HadrBlob types is competed." << endl;
			cout << " *************************************************************************" << endl;
		}
		else if (option == 3){
		cout << " -------------------------------------------------------------------------" << endl;
		cout << " Please input the PDG code of the particle you want." << endl;
		cout << " e.g. proton = 2212, neutron = 2112, gamma = 22," << endl;
		cout << " pi+ = 211, pi- = -211, nucleus = 2000000002" << endl;
		cout << " -------------------------------------------------------------------------" << endl;
		int particle_PDG_code;
		cin >> particle_PDG_code;
		cout << " -------------------------------------------------------------------------" << endl;
		cout << " Please input the momentum / energy you want." << endl;
		cout << " i.e. Px, Py, Pz, E" << endl;
		cout << " -------------------------------------------------------------------------" << endl;
		string option2;
		cin >> option2;
		int checkpoint = 0;
		if (option2 == "Px")
			checkpoint = 67;
		else if (option2 == "Py")
			checkpoint = 77;
		else if (option2 == "Pz")
			checkpoint = 87;
		else if (option2 == "E")
			checkpoint = 97;
		ifstream file("example.txt"); 
		string line;
		ofstream out_txt_file;
		out_txt_file.open("./data.txt", ios::out | ios::trunc);
    	out_txt_file << fixed;
		if (file.is_open()) {
			while (getline(file, line)) {
				if (line.length() < 110)
					continue;
				string check_particle_2 = line.substr(0,7);
            	string check_final_state_1 = line.substr(56,2);
            	string check_final_state_2 = line.substr(62,2);
            	string check_final_state_3 = line.substr(44,2);
            	string check_hadrblob = line.substr(13,8);
            	if (!equal_string("|      ",check_particle_2) && equal_string("-1",check_final_state_1) && 
            	equal_string("-1",check_final_state_2) && !equal_string("-1",check_final_state_3)) 
				{if (particle_PDG_code == stoi(line.substr(30,10)))
					{out_txt_file << stof(line.substr(checkpoint,7)) << endl;}}
			}
		}
		file.close();
		out_txt_file.close();
		cout << " -------------------------------------------------------------------------" << endl;
		cout << " The data has been stored in 'data.txt'." << endl;
		cout << " Please use 'distribution.C' to plot the histogram." << endl;
		cout << " *************************************************************************" << endl;
		}
		else if (option == 4){
			cout << " -------------------------------------------------------------------------" << endl;
			cout << " Please input the PDG code of the particle you want." << endl;
			cout << " e.g. proton = 2212, neutron = 2112, gamma = 22," << endl;
			cout << " pi+ = 211, pi- = -211, nucleus = 2000000002" << endl;
			cout << " -------------------------------------------------------------------------" << endl;
			int particle_PDG_code;
			cin >> particle_PDG_code;
			cout << " -------------------------------------------------------------------------" << endl;
			cout << " Please input the momentum / energy you want." << endl;
			cout << " i.e. Px, Py, Pz, E" << endl;
			cout << " -------------------------------------------------------------------------" << endl;
			string option2;
			cin >> option2;
			int checkpoint = 0;
			if (option2 == "Px")
				checkpoint = 67;
			else if (option2 == "Py")
				checkpoint = 77;
			else if (option2 == "Pz")
				checkpoint = 87;
			else if (option2 == "E")
				checkpoint = 97;
			ifstream file("example.txt"); 
			string line;
			ofstream out_txt_file;
			out_txt_file.open("./data2.txt", ios::out | ios::trunc);
    		out_txt_file << fixed;
			float momentum_of_the_particle[15] = {};
			int multiplcity_of_the_particle = 0;
			int numEvent = 0;
			if (file.is_open()) {
			while (getline(file, line)) {
				string check_new_event = line.substr(0,24);
           		string check_particle_1 = line.substr(0,3);
				if (equal_string("|GENIE GHEP Event Record",check_new_event))
				{
					if (numEvent != 0)
					{
						for (int i = 0; i < multiplcity_of_the_particle; i++)
						{
							out_txt_file << multiplcity_of_the_particle << " " << momentum_of_the_particle[i] << endl;
						} 
					}
					multiplcity_of_the_particle = 0;
					numEvent+=1;
				}
				else if (equal_string("|  ",check_particle_1))
				{
					string check_particle_2 = line.substr(0,7);
            		string check_final_state_1 = line.substr(56,2);
            		string check_final_state_2 = line.substr(62,2);
            		string check_final_state_3 = line.substr(44,2);
            		string check_hadrblob = line.substr(13,8);
					if (!equal_string("|      ",check_particle_2) && equal_string("-1",check_final_state_1) && 
					equal_string("-1",check_final_state_2) && !equal_string("-1",check_final_state_3)) 
					{if (particle_PDG_code == stoi(line.substr(30,10)))
						{momentum_of_the_particle[multiplcity_of_the_particle] = stof(line.substr(checkpoint,7));
						multiplcity_of_the_particle += 1;}}
				}
			}
			for (int i = 0; i < multiplcity_of_the_particle; i++)
			{
				out_txt_file << multiplcity_of_the_particle << " " << momentum_of_the_particle[i] << endl;
			}
		}
		file.close();
		out_txt_file.close();
		cout << " -------------------------------------------------------------------------" << endl;
		cout << " The data has been stored in 'data2.txt'." << endl;
		cout << " Please use 'distribution2.C' to plot the histogram." << endl;
		cout << " *************************************************************************" << endl;
		}
		else{cout << " -------------------------------------------------------------------------" << endl;
            cout << " The option you input is invalid. Please try again." << endl;
            cout << " -------------------------------------------------------------------------" << endl;}
        cout << " Please input the option command:" << endl;
    	cout << " 0 - Quit;" << endl;
    	cout << " 1 - Multiplicity of total, charged and uncharged final-state particles;" << endl;
    	cout << " 2 - Types of final-state nuclei (HadrBlob);" << endl;
		cout << " 3 - Momentum and energy distribution for a specific final-state particle;" << endl;
		cout << " 4 - Momentum and energy versus multiplicity for a specific final-state particle." << endl;
    	cout << " -------------------------------------------------------------------------" << endl;
    
    }
    return 0;
}



