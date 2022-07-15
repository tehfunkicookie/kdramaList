#include "kdrama.h"

std::vector<kdrama> kdrama::watchlist {};

kdrama::kdrama()
{
    std::cout << "New korean drama record" << std::endl;
}

kdrama::~kdrama(){
}

kdrama::kdrama(std::string input_name, std::string input_status, double input_rating, int current_episode){
    name = input_name;
    status = input_status;
    rating = input_rating;
    episode = current_episode;
}

void kdrama::add_kdrama(kdrama input){
    watchlist.push_back(input);
    std::cout << "You have " << watchlist.size() << " korean dramas on your list." << std::endl;
}

//void kdrama::update_rating(kdrama& input){
//    double new_rating;
//    std::cout << "Enter in rating: " << std::endl;
//    input.setRating(new_rating);
//    std::cout << "Rating updated" << std::endl;
//}

int kdrama::find_kdrama(){
        std::string user_kdrama_name;
        std::cout << "Enter in korean drama that you want to update/change the rating of: ";
        std::getline(std::cin,user_kdrama_name);
        
        for (int i=0;i<watchlist.size();i++){
            if (watchlist[i].name == user_kdrama_name){
                std::cout << "Korean drama found" << std::endl;
                std::cout << "korean drama is the " << i+1 << " drama on your list" << std::endl;
                // remember that vectors start at 0 index so gotta add 1 to return true.
                return i+1;
            }
        }
        
        std::cout << "Korean drama not found. Please add it to the list." << std::endl; 
        return -1;
        
        
}

void kdrama::create_kdrama(){
            std::string user_kdrama, user_status;
            double user_rating;
            int user_episode=0;
                
            std::cout << "Name of korean drama: ";
            std::getline(std::cin, user_kdrama);
                
            std::cout << "Status (Complete/Watching): ";
            std::getline(std::cin, user_status);
            
            if (user_status == "Watching"){
                std::cout << "Enter current episode you are watching: ";
                std::cin >> user_episode;
            } else{
                user_episode = 16;
                // standard kdramas are 16 episode long. 
            }
                
            std::cout << "Rating (1-10): ";
            std::cin >> user_rating;
                
            kdrama input = kdrama(user_kdrama,user_status,user_rating,user_episode);
            kdrama::add_kdrama(input);   
}


void kdrama::print_list(){
    
    if (watchlist.size()==0){
        std::cout << "You have no korean dramas you are watching or have finished" << std::endl;
        return;
    }
    
    std::cout << "Here is your list of korean dramas: " << std::endl;
    std::cout << std::left << std::setw(30) << "Korean Drama Title " << std::left << std::setw(40) << "Status (Complete/Watching)" << std::left << std::setw(20)<< "Episode" << std::left << std::setw(20) << "Rating (1-10)" << std::endl; 
    std::cout << "______________________________________________________________________________________________________________________________" << std::endl;
    for (int i=0;i<watchlist.size();i++){
        std::cout << std::left << std::setw(30) << watchlist[i].name << std::left << std::setw(40) << watchlist[i].status << std::left << std::setw(20) << watchlist[i].episode << std::left << std::setw(10) << watchlist[i].rating << std::endl;
    }
}

void kdrama::export_list(){
        if (watchlist.size()==0){
        std::cout << "You have no korean dramas you are watching or have finished" << std::endl;
        return;
    }
    
    // check if file exists already
    
    
    std::cout << "Outputting current kdrama list to text file..." << std::endl;
    std::ofstream outfile ("kdrama_List.txt");
    
    outfile << std::left << std::setw(30) << "Korean Drama Title " << std::left << std::setw(40) << "Status (Complete/Watching)" << std::left << std::setw(20)<< "Episode" << std::left << std::setw(20) << "Rating (1-10)" << std::endl; 
    outfile << "________________________________________________________________________________________________________" << std::endl;
    for (int i=0;i<watchlist.size();i++){
        outfile << std::left << std::setw(30) << watchlist[i].name << std::left << std::setw(40) << watchlist[i].status << std::left << std::setw(20) << watchlist[i].episode << std::left << std::setw(10) << watchlist[i].rating << std::endl;
    }
    
    outfile.close();
    std::cout << std::endl;
}
     
void kdrama::import_kdrama_list(){
    std::string file_location;
//    std::cout << "Enter in file location of kdrama list to import: ";
//    std::getline(std::cin,file_location);
    std::ifstream in_file;
    in_file.open("kdrama_List.txt");
//    in_file.open(file_location,std::ios::in);
    
    if(!in_file){
        std::cerr << "Problem opening file" << std::endl;
        return;
    } 
    
    // inputs read from file;
    std::string kdrama_name;
    std::string kdrama_status;
    std::string kdrama_episode_string; // will convert to int later
    std::string kdrama_rating_string; // will convert to double later
    int kdrama_episode;
    double kdrama_rating;
    //
    // skip the first two lines in the file since its just description of the rows
    std::string line;
    std::getline(in_file,line);
    std::getline(in_file,line);
    
    while(std::getline(in_file,line)){
        
        // read in the kdrama name first..since the kdrama name can vary in length, use resize function to make sure the kdrama name will be dynamically changed by the software
        kdrama_name = line.substr(0,30);
        for (int i=kdrama_name.size()-1;i>=0;i--){
            if (kdrama_name[i]==' '){
                kdrama_name.pop_back();
            } else{
                break;
            }
        }
        // read in the kdrama status next
        kdrama_status = line.substr(30,8);
        
        // read in episode string 
        kdrama_episode_string = line.substr(70,2);
        kdrama_episode = stoi(kdrama_episode_string);        
        
        // reading in rating. assuming rating is up to 2 sig figs or one number after decimal point. so max of 3 chars can be read for rating
        kdrama_rating_string = line.substr(90,3);
        kdrama_rating = stod(kdrama_rating_string);
        
        kdrama input = kdrama(kdrama_name,kdrama_status,kdrama_rating,kdrama_episode);
        kdrama::add_kdrama(input);           
    }
    
    
    in_file.close();
    std::cout << "File imported and read" << std::endl;
    
}     
     
     
void kdrama::setRating(){
    double input;
    std::cout << "Enter in rating for korean drama: ";
    std::cin >> input;
    rating = input;
}

void kdrama::setStatus(){
    std::string status_change;
    std::cout << "Enter in new status (complete, watching ,etc...): ";
    std::getline(std::cin,status_change);
    status = status_change;
}

kdrama& kdrama::get_kdrama(int index){
    std::cout << "Retrieving " << watchlist[index-1].name << std::endl;
    return watchlist[index-1];
}