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

    virtual std::string setName(const std::string &name) = 0;
    virtual std::string getName() = 0;
    virtual void callingSound() = 0;
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

    void callingSound() override {
        std::cout << "bem bem bem bem BEM BEM" << std::endl;
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

class HomePhone : public Phone{
public:
    HomePhone(const std::string &name, const std::string &brandName): Phone(name, brandName) {};

    std::string setName(const std::string &name) override {
        HomePhone::name = name;
    }

    std::string getName() override {
        return HomePhone::name;
    }

    void callingSound() override {
        std::cout << "BZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ" << std::endl;
    }
};

void playSound(Phone *phone) {
    phone->callingSound();
}

int main() {
    MobilePhone firstPhone = MobilePhone("mYpHonE", "7SY371D", "Nokia");
    MobilePhone secondPhone = MobilePhone("Phone3000", "js8sG2g", "Samsung");
    HomePhone thirdPhone = HomePhone("Kakoyta name", "Kakoyta brand name");

    firstPhone.callRequest(&secondPhone);
    playSound(&firstPhone);
    playSound(&secondPhone);
    playSound(&thirdPhone);
    return 0;
}
