#ifndef HARL_HPP
#define HARL_HPP

#include <string>

class Harl {
   public:
    void complain(std::string level);
    Harl();

   private:
    typedef void (Harl::*msg_f_ptr_)(void);
    msg_f_ptr_ function_map_[4];
    std::string name_map_[4];
    void debug(void);
    void info(void);
    void warning(void);
    void error(void);
};

#endif  // HARL_HPP
