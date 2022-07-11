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
    
    while (choice!=7 && !isalpha(choice) ){
        switch(choice){
            case 1: 
            {
                kdrama::create_kdrama();
                break;
            }    
            
            case 2: //Rate a korean drama or change a rating
            {
                int num_check = kdrama::find_kdrama();
                std::cout << num_check << std::endl;
                if(num_check){
//                    kdrama::update_rating();
                    // use the index returned by find_kdrama and find it in the vector 
                    // then call update_rating function 
                    // i cannot call a non-static method from a static method
                    // since i'm updating a korean drama rating, it has to be done from the object of the korean drama
                    // i'm gonna have to write a function to return the kdrama i'm looking for
                    // then store that return into a reference here in the main
                    kdrama& desired = kdrama::get_kdrama(num_check);
                    desired.setRating();
                }
                break;
            }    
            
            case 3:
            {
                int num_check = kdrama::find_kdrama();
                std::cout << num_check << std::endl;
                if(num_check){
//                    kdrama::update_rating();
                    // use the index returned by find_kdrama and find it in the vector 
                    // then call update_rating function 
                    // i cannot call a non-static method from a static method
                    // since i'm updating a korean drama rating, it has to be done from the object of the korean drama
                    // i'm gonna have to write a function to return the kdrama i'm looking for
                    // then store that return into a reference here in the main
                    kdrama& desired = kdrama::get_kdrama(num_check);
                    desired.setStatus();
                }
                break;
            }
                
            case 4:
            {
                kdrama::print_list();
                std::cout << std::endl;
            }
                break;
            
                
            case 5:
            {
                kdrama::export_list();
                std::cout << std::endl;
            }
                break;
            
            case 6: {
                // enter in method here
                kdrama::import_kdrama_list();
                std::cout << std::endl;
                break;
            }
                
            default:
            
                std::cout << "invalid selection." << std::endl;
                break;
        }
    
        std::cout << std::endl;
        std::cout << "Do you want to return back to main menu (Y/N): ?" <<  std::endl;
        char c;
        std::cin >> c;
        std::cin.ignore();
        
        if (c=='Y' || c =='y'){
            display_menu();
            std::cin >> choice;     
            std::cin.ignore();
            std::cout << std::endl;
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
    std::cout << "6. Read korean drama list text file" << std::endl;
    std::cout << "7. QUIT" << std::endl;
    std::cout << std::endl;
}