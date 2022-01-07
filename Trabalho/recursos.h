//
// Created by ssasu on 1/6/2022.
//

#ifndef TRABALHO_RECURSOS_H
#define TRABALHO_RECURSOS_

class Resources {
    int preco;
    int quantidade;
public:
    Resources(float preco = 0,float quantidade = 0) : preco(preco) ,quantidade(quantidade){};
};

class Ferro : public Resources{
    
public:
    Ferro(float pre = 1,float quant = 0) : Resources(pre,quant){};
};

class Aco : public Resources{
public:
    Aco(float pre = 2, float quant = 0) : Resources(pre, quant) {};
};

class Carvao : public Resources{
public:
    Carvao(float pre = 1, float quant = 0) : Resources(pre, quant) {};
};

class Madeira : public Resources{
public:
    Madeira(float pre = 1, float quant = 0) : Resources(pre, quant) {};
};

class Vigas : public Resources{
public:
    Vigas(float pre = 2, float quant = 0) : Resources(pre, quant) {};
};

class Eletricidade: public Resources{
public:
    Eletricidade(float pre = 1, float quant = 0) : Resources(pre, quant) {};
};


class Data{
    int day, money;
    Resources resources;
public:
    Data();
};
#endif //TRABALHO_RECURSOS_H
