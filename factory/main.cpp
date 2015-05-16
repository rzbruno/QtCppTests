#include <QCoreApplication>
#include <map>
#include <iostream>

class Operational{
    public:
        virtual ~Operational(){}
        virtual void setValues(double v1, double v2) = 0;
        virtual double getResults() = 0;
};

class Soma: public Operational{
    public:
       void setValues(double v1, double v2);
       double getResults();

    protected:
        double number1, number2;
};

void Soma::setValues(double v1, double v2){
    number1 = v1;
    number2 = v2;
}

double Soma::getResults(){
    return number1 + number2;
}

class Subtracao: public Operational{
    public:
        void setValues(double v1, double v2);
        double getResults();

    protected:
        double number1, number2;
};

void Subtracao::setValues(double v1, double v2){
    number1 = v1;
    number2 = v2;
}

double Subtracao::getResults(){
    return number1 - number2;
}

class Factory{
    public:
        ~Factory();
        void setValues(QString, double Value1, double Value2);

        double getResult(QString);
        void addOperation(QString, Operational*);

    private:
        std::map<QString, Operational*> nomeOperacao;
};

Factory::~Factory(){
    for (std::map<QString,Operational*>::iterator it=nomeOperacao.begin(); it!=nomeOperacao.end(); ++it)
        delete it->second;
}

void Factory::addOperation(QString Name, Operational* Op){
    nomeOperacao[Name] = Op;
}

void Factory::setValues(QString obj, double Value1, double Value2){
    nomeOperacao[obj]->setValues(Value1, Value2);
}

double Factory::getResult(QString Nome){
    return nomeOperacao[Nome]->getResults();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Factory *f = new Factory();
    f->addOperation("+", new Soma());
    f->addOperation("-", new Subtracao());

    f->setValues("-", 1.1, 2.2);
    f->setValues("-", 5, 2);

    std::cout << f->getResult("-") << std::endl;

    return a.exec();
}
