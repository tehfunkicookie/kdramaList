#ifndef KDRAMA_H
#define KDRAMA_H
#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
#include <fstream>

class kdrama
{
private:
    std::string name;
    std::string status;
    int year;
    int episode;
    double rating;
    static std::vector<kdrama> watchlist;
    
public:
    kdrama();
    kdrama(std::string name, std::string status, double rating,int episode);
    ~kdrama();
    void static create_kdrama();
//    void update_rating(kdrama& input);
    int static find_kdrama();
    void static add_kdrama(kdrama input);
    void static print_list();
    bool check_if_exists_already(kdrama input_name);
    void static export_list();
    void static import_kdrama_list();
    
    // setters and getters
    static kdrama& get_kdrama(int index);
    void setName(std::string name);
    void setRating();
    void setStatus();
};

#endif // KDRAMA_H