#include <iostream>
#include <string>
#include <vector>

// Строителя имеет смысл использовать, когда продукты достаточно сложны
// и требуют обширной конфигурации. Различные конкретные строители могут
// производить несвязанные продукты.

// Состав животных на ферме или в коллекции
class Animals{
public:
    std::vector<std::string> parts_;
    void ListParts()const{
        std::cout << "Animals:\n";
        for (size_t i=0;i<parts_.size();i++){
            if(parts_[i]== parts_.back()){
                std::cout << "    " << parts_[i];
            }else{
                std::cout << "    " << parts_[i] << ",\n";
            }
        }
        std::cout << "\n\n";
    }
};

// Интерфейс Строителя объявляет методы для приобретения животных.
class Builder{
public:
    virtual ~Builder(){}
    virtual void BuyDuck() const =0;
    virtual void BuyDog() const =0;
};

// Классы Конкретного Строителя следуют интерфейсу предоставляют конкретные
// шаги построения. Программа может иметь нескольковариантов Строителей,
// реализованных по-разному.

class DomesticFarmBuilder : public Builder{
private:
    Animals* farm;
    // Новый экземпляр строителя должен содержать пустой объект продукта,
    // который используется в дальнейшей сборке.
public:
    DomesticFarmBuilder(){
        this->Reset();
    }
    ~DomesticFarmBuilder(){
        delete farm;
    }
    void Reset(){
        this->farm = new Animals();
    }
    // Все этапы производства работают с одним и тем же экземпляром продукта.
    void BuyDuck()const override{
        // Здесь можно еще и создать купленную утку
        this->farm->parts_.push_back("We have bought the Domestic Duck");
    }
    void BuyDog()const override{
        // Здесь можно еще и создать купленную собаку
        this->farm->parts_.push_back("We have bought the Domestic Dog");
    }
    // Конкретные Строители должны предоставить свои собственные методы
    // получения результатов. Это связано с тем, что различные типы строителей
    // могут создавать совершенно разные продукты с разными интерфейсами.
    Animals* GetProduct() {
        Animals* result = this->farm;
        this->Reset();
        return result;
    }
};

class ToyFarmBuilder : public Builder{
private:
    Animals* farm;
    // Новый экземпляр строителя должен содержать пустой объект продукта,
    // который используется в дальнейшей сборке.
public:
    ToyFarmBuilder(){
        this->Reset();
    }
    ~ToyFarmBuilder(){
        delete farm;
    }
    void Reset(){
        this->farm = new Animals();
    }
    // Все этапы производства работают с одним и тем же экземпляром продукта.
    void BuyDuck()const override {
        // Здесь можно еще и создать игрушечную купленную утку
        this->farm->parts_.push_back("We have bought the Toy Duck");
    }
    void BuyDog()const override{
        // Здесь можно еще и создать купленную игрушечную собаку
        this->farm->parts_.push_back("We have bought the Toy Dog");
    }
    // Конкретные Строители должны предоставить свои собственные методы
    // получения результатов. Это связано с тем, что различные типы строителей
    // могут создавать совершенно разные продукты с разными интерфейсами.
    Animals* GetProduct() {
        Animals* result = this->farm;
        this->Reset();
        return result;
    }
};

// Директор отвечает только за выполнение шагов построения в определённой
// последовательности. Это полезно при производстве продуктов в определённом
// порядке или особой конфигурации. Строго говоря, класс Директор необязателен,
// так как клиент может напрямую управлять строителями.
class Director{
private:
    Builder* builder;
    // Директор работает с любым экземпляром строителя, который передаётся ему
    // клиентским кодом. Таким образом, клиентский код может изменить конечный
    // тип вновь собираемого продукта.
public:
    void set_builder(Builder* builder){
        this->builder=builder;
    }
    // Директор может строить несколько вариаций продукта, используя одинаковые
    // шаги построения.
    void BuildMinimalViableProduct(){
        this->builder->BuyDuck();
    }
    void BuildFullFeaturedProduct(){
        this->builder->BuyDuck();
        this->builder->BuyDog();
    }
};

// Клиентский код создаёт объект-строитель, передаёт его директору, а затем
// инициирует процесс построения. Конечный результат извлекается из объекта-
// строителя.
void ClientCode(Director& director) {
    DomesticFarmBuilder* domesticBuilder = new DomesticFarmBuilder();
    director.set_builder(domesticBuilder);
    std::cout << "Standard basic domestic farm:\n";
    director.BuildMinimalViableProduct();

    Animals* p = domesticBuilder->GetProduct();
    p->ListParts();
    delete p;

    std::cout << "Standard full featured domestic farm:\n";
    director.BuildFullFeaturedProduct();

    p= domesticBuilder->GetProduct();
    p->ListParts();
    delete p;

    // Помните, что паттерн Строитель можно использовать без класса Директор.
    std::cout << "Custom domestic farm:\n";
    domesticBuilder->BuyDuck();
    p=domesticBuilder->GetProduct();
    p->ListParts();
    delete p;

    delete domesticBuilder;

    ToyFarmBuilder* toyBuilder = new ToyFarmBuilder();
    director.set_builder(toyBuilder);
    std::cout << "Standard basic toys's farm:\n";
    director.BuildMinimalViableProduct();

    p = toyBuilder->GetProduct();
    p->ListParts();
    delete p;

    std::cout << "Standard full featured toys's farm:\n";
    director.BuildFullFeaturedProduct();

    p= toyBuilder->GetProduct();
    p->ListParts();
    delete p;

    // Помните, что паттерн Строитель можно использовать без класса Директор.
    std::cout << "Custom toys's farm:\n";
    toyBuilder->BuyDog();
    p=toyBuilder->GetProduct();
    p->ListParts();
    delete p;

    delete toyBuilder;
}

int main(){
    Director* director= new Director();
    ClientCode(*director);
    delete director;
    return 0;
}
