#ifndef KDRAMA_H
#define KDRAMA_H
#include <string>
#include <vector>
#include <iostream>

class kdrama
{
private:
    std::string name;
    std::string status;
    double rating;
    static std::vector<kdrama> watchlist;
    
public:
    kdrama();
    kdrama(std::string name, std::string status, double rating);
    ~kdrama();
    void static add_kdrama(kdrama input);
    void setName(std::string name);
    void setRating(double rating);
    void static print_list();
    bool check_if_exists_already(kdrama input_name);
    

};

#endif // KDRAMA_H