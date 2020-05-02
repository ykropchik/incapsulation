#include <iostream>

class Phone {
protected:
    std::string name;
public:
    std::string brandName;                      // Отсутствие инкапсуляции

    Phone(const std::string &name, const std::string &brandName){
        this->name = name;
        this->brandName = brandName;
    };

    virtual std::string setName(const std::string &name);
    virtual std::string getName();
};

class MobilePhone : public Phone {
private:
    std::string serialNumber;
public:
    // Расширение
    MobilePhone(const std::string &name, const std::string &serialNumber, const std::string &brandName): Phone(name, brandName) {
        this->serialNumber = serialNumber;
    }

    // Замена поведения
    std::string setName(const std::string &name) override {                      // Инкапсуляция при помощи сетера
        MobilePhone::name = name;
    }

    std::string getName() override {                                             // Инкапсуляция при помощи гетера
        return MobilePhone::name;
    }

    // Позднее связывание
    virtual void callRequest(MobilePhone *object){
        std::cout << this->serialNumber << ": Waiting answer...\n";
        object->callAnswer(this);
    };

private:
    virtual void callAnswer(MobilePhone *phone) {
        std::cout << this->serialNumber << ": ";
        std::cout << phone->serialNumber << " Request a call\n";
        std::cout << this->serialNumber << ": " << "Request approved\n";
        std::cout << this->serialNumber << ": " << "Start call\n";
    }

};

int main() {
    MobilePhone firstPhone = MobilePhone("mYpHonE", "7SY371D", "Nokia");
    MobilePhone secondPhone = MobilePhone("Phone3000", "js8sG2g", "Samsung");

    firstPhone.callRequest(&secondPhone);
    return 0;
}
