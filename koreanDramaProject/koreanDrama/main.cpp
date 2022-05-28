#include <vector>
#include <array>
#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>

//include classes
#include <kdrama.h>


//function declarations
void display_menu();

int main (){
    // goal of this program is to:
    // record your kdrama that you are currently watching or have finished
    // if you are still watching it, what episode you are on
    // if you are done watching it, give it a rating
    // store all the korean dramas watching/watched so far and their ranking
    // then print them to a text file and export that text file to a folder
    
    display_menu();
    int choice;
    std::cin >> choice;
    std::cin.ignore();
    
    while (choice!=6){
        switch(choice){
            case 1: 
            {
                std::string name, status;
                double rating;
                
                std::cout << "Name of korean drama: ";
                std::getline(std::cin, name);
                
                std::cout << "Status (Complete/Watching): ";
                std::getline(std::cin, status);
                
                std::cout << "Rating (1-10): ";
                std::cin >> rating;
                
                kdrama input = kdrama(name,status,rating);
                kdrama::add_kdrama(input);
                
                break;
            }
            
            case 2:
                std::string user_kdrama_name;
                std::cout << "Enter in korean drama that you want to update/change the rating of: ";
                std::getline(std::cin,user_kdrama_name);
                
                
                
                
                break;
                
            case 3:
                
                break;
                
            case 4:
                kdrama::print_list();
                std::cout << std::endl;
                break;
                
            case 5:
                break;
                
            default:
                std::cout << "invalid selection. Please make another choice" << std::endl;
                break;
        }
        
        std::cout << "Do you want to return back to main menu (Y/N): ?" <<  std::endl;
        char c;
        std::cin >> c;
        
        if (c=='Y'){
            display_menu();
            std::cin >> choice;           
        } else{
            break;
        }
}
    
    return 0;
}

void display_menu(){
    std::cout << "Choose from the following options: \n"<< std::endl;
    std::cout << "1. Add korean drama to watch list" << std::endl;
    std::cout << "2. Rate a korean drama or change a rating" << std::endl;
    std::cout << "3. Update status of korean drama" << std::endl; // finished, still watching or stopping/giving up, updating episode
    std::cout << "4. Print current korean drama list" << std::endl;
    std::cout << "5. Export current korean drama list out to .txt file" << std::endl;
    std::cout << "6. QUIT" << std::endl;
    std::cout << std::endl;
}