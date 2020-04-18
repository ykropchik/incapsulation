#include <iostream>

class Phone {
protected:
    std::string name;
    std::string serialNumber;
public:
    std::string brandName;                      // Отсутствие инкапсуляции

    // Инкапсуляция через позднее связывание
    virtual void callRequest(Phone *object){
        std::cout << this->serialNumber << ": Waiting answer...\n";
        object->callAnswer(this);
    };

private:
    virtual void callAnswer(Phone *phone) {
        std::cout << this->serialNumber << ": ";
        std::cout << phone->serialNumber << " Request a call\n";
        std::cout << this->serialNumber << ": " << "Request approved\n";
        std::cout << this->serialNumber << ": " << "Start call\n";
    }
};

class MobilePhone : public Phone {
public:
    MobilePhone(const std::string &name, const std::string &serialNumber, const std::string &brandName) {
        this->name = name;
        this->serialNumber = serialNumber;
        this->brandName = brandName;
    }

    std::string setName(const std::string &name){                      // Инкапсуляция при помощи сетера
        MobilePhone::name = name;
    }

    std::string getName(){                                             // Инкапсуляция при помощи гетера
        return MobilePhone::name;
    }

};

class HomePhone : public Phone {
public:
    HomePhone(const std::string &name, const std::string &serialNumber, const std::string &brandName) {
        this->name = name;
        this->serialNumber = serialNumber;
        this->brandName = brandName;
    }

    std::string setName(const std::string &name){                      // Инкапсуляция при помощи сетера
        HomePhone::name = name;
    }

    std::string getName(){                                             // Инкапсуляция при помощи гетера
        return HomePhone::name;
    }


};

int main() {
    MobilePhone firstPhone = MobilePhone("mYpHonE", "7SY371D", "Nokia");
    HomePhone secondPhone = HomePhone("HomePhoneROSTELECOM", "612HS73G", "Panasonic");

    firstPhone.callRequest(&secondPhone);
    return 0;
}
