#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <unistd.h>
unsigned int detect_os(void);
static void own_info();
struct Energy{
	double joule;
	double electron_volts;
	};
struct Energy shell_energy(int);
struct Energy shell_energy(int shell_number){
	 struct Energy enrg;
	 const double rydberg_cont=2.18e-18;
	 const double charge_on_electron=1.602176e-19;//c charge, for conver jule into electron volt 
     const double one_joule_in_electron_volt=((1)/(charge_on_electron));
     //one joule in electron volt 1/1.602176*e-19;
     //1joule=1/1.602176*e-19 eV
     enrg.joule=((rydberg_cont)/(shell_number*shell_number));
     enrg.electron_volts=(((rydberg_cont)/(shell_number*shell_number))*(one_joule_in_electron_volt));	
	 //printf("\n%f",enrg.electron_volts);
	 return enrg;
}

int main(){
	struct Energy shell;
	int n=0;
	own_info();
	printf("\n\n\n");
	shell=shell_energy(n);
	if(detect_os()==0){
		//windows OS
		while(1){
			printf("\nn=%d shell-energy==%.10f",n,shell.electron_volts);
			shell=shell_energy(n);
		    usleep(783883);
			n++;
		}
		
	}else if (detect_os()==1){
	//linux falvour color availble	
        	while(1){
        	shell=shell_energy(n);
		
			printf("\nn=%d \033[93mshell-energy==%.10f eV | and in joule==%e",n,shell.electron_volts,shell.joule);
			usleep(783883);
			n++;
		}
		
	}else{
			while(1){
			printf("\nn=%d shell-energy ==%.15f",n,shell.electron_volts);
			shell=shell_energy(n);
			usleep(783883);
			n++;
		}
	 
	 }

//	printf("\nn=%d Enery==%.20f",n,shell.electron_volts);	

}

static void own_info(){
printf("\n\n\nAuthor : One-Exploits @GNU/Projects"
"\nÂ©Mohammad Arquam(C.E.O)"
"\n+______________________________________________+"
"\n| Programmer,H@cker,Web developer,Web designer,|\n| Data Scientist,Software developer,YouTuber,  |\n| Blogger and more.\t\t\t       |\n|\t\t\t\t\t       |"
"\n| Gmail: oneexploits@gmail.com\t\t       |"
"\n| GitHub: https://github.com/one-exploits      |"
"\n| Insta: https://www.instagram.com/one_exploits\|"
"\n| Website: https://one-exploits.business.site/ |"
"\n|\t\t\t\t\t       |"
"\n| \t\t\tVersion:1.00.00\t       |\n"
"|\t\t\tDate:01/02/2021,Mon    |"
"\n+______________________________________________+");

}
unsigned int detect_os(void){
	#ifdef _WIN32
		return 0; 
	#elif __linux__
	     return 1;
	#else
	  return 1;  
	#endif		
}

