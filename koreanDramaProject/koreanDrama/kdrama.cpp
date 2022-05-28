#include "kdrama.h"

std::vector<kdrama> kdrama::watchlist {};

kdrama::kdrama()
{
    std::cout << "New korean drama record" << std::endl;
}

kdrama::kdrama(std::string name, std::string status, double rating){
    kdrama::name = name;
    kdrama::status = status;
    kdrama::rating = rating;
}

void kdrama::add_kdrama(kdrama input){
    watchlist.push_back(input);
    std::cout << "You have " << watchlist.size() << " korean dramas on your list." << std::endl;
}


void kdrama::print_list(){
    
    if (watchlist.size()==0){
        std::cout << "You have no korean dramas you are watching or have finished" << std::endl;
        return;
    }
    
    std::cout << "Here is your list of korean dramas: " << std::endl;
    std::cout << "Korean Drama Title                                                 " << "Status (Complete/Watching)                " << "Rating (1-10)" << std::endl; 
    std::cout << "________________________________________________________________________________________________________________________" << std::endl;
    for (int i=0;i<watchlist.size();i++){
        std::cout << watchlist[i].name << "                                                 " << watchlist[i].status << "                " << watchlist[i].rating << std::endl;
    }
}