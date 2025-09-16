#include <vector>
#include <string>

#ifndef BEADEDBAG_BEADEDBAG_HPP
#define BEADEDBAG_BEADEDBAG_HPP

/**
 * class Shippable
 *
 * Anything that is shippable must have a volume and a name. 
 */

class Shippable {
public:
  /**
   * get_volume()
   *
   * Get the volume of the item shipped.
   *
   * \return The volume of the item shipped.
   */
  virtual double get_volume() const = 0;
  virtual std::string get_name() const = 0;


  protected:
  double volume;
  std::string name;
};

/**
 * class FastFashionPackage
 * A FastFashionPackage is a Shippable item where
 * every item has a name and a volume. 
 *
 */
class FastFashionPackage : public Shippable {
  
  public:
  FastFashionPackage(std::string name, double volume):name{name}, volume{volume}{}
  virtual double get_volume() const{
    return volume;
  }
  virtual std::string get_name()const{
    return name;
  }
  private:
  double volume;
  std::string name; 
};
//Class Electroincs
//this stores only a name all vol is 4
class Electronics : public Shippable {
  
  public:
  Electronics(std::string name):name{name}{}

  
  virtual double get_volume() const{
    return volume;
  }
  virtual std::string get_name()const{
    return name;
  }

  private:
  std::string name;
  double volume = 4;
};

template <typename  T>

//this is the container
class Teu {
public:
  Teu(std::string address, double max_volume):location{address}, max_volumee{max_volume}{}

  std::string get_manifest() const {
    std::vector <T> copy = all_of_em;
    std::string names = copy.at(0).get_name();
    copy.erase(copy.begin());
    for(T x:copy){
      names += ", " + x.get_name();
    }
    return names;
  }


  double get_tonnage() const {
    double tonage  = 0; 
    for (T x:all_of_em){
      tonage += x.get_volume();
    }
    return tonage;
  }
  bool add_to_container(T to_ship){
     double tonage; 
    for (T x:all_of_em){
      tonage += x.get_volume();
    }
    if ((to_ship.get_volume() + tonage) <= max_volumee){
        all_of_em.push_back(to_ship);
        return true;
    }
    else{
      return false;
    }
  }

private:
  std::vector <T> all_of_em;
  std::string location;
  double max_volumee;
};

#endif
