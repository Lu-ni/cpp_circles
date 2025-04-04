#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <cstddef>
#include <string>

class Contact {
   private:
    std::string first_name_;
    std::string last_name_;
    std::string nickname_;
    std::string phone_number_;
    std::string darkest_secret_;

   public:
    static const char* const* get_field_names() {
        static const char* const field_names[] = {"first_name",   "last_name",      "nickname",
                                                  "phone_number", "darkest_secret", NULL};
        return field_names;
    }

    Contact() : first_name_(""), last_name_(""), nickname_(""), phone_number_(""), darkest_secret_("") {}

    const std::string& get_first_name() const { return first_name_; }
    const std::string& get_last_name() const { return last_name_; }
    const std::string& get_nickname() const { return nickname_; }
    const std::string& get_phone_number() const { return phone_number_; }
    const std::string& get_darkest_secret() const { return darkest_secret_; }

    void set_first_name(const std::string& first) { first_name_ = first; }
    void set_last_name(const std::string& last) { last_name_ = last; }
    void set_nickname(const std::string& nick) { nickname_ = nick; }
    void set_phone_number(const std::string& phone) { phone_number_ = phone; }
    void set_darkest_secret(const std::string& secret) { darkest_secret_ = secret; }
};

#endif  // CONTACT_HPP
