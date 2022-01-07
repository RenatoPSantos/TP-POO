//
// Created by ssasu on 1/6/2022.
//

#ifndef TRABALHO_RECURSOS_H
#define TRABALHO_RECURSOS_


class Recursos {
    int preco;
    int quantidade;
public:
    Recursos(float pre = 0,float quant = 0) : preco(pre),quantidade(quant){};
};


class Ferro : public Recursos{
    
public:
    Ferro(float pre = 1,float quant = 0) : Recursos(pre,quant){};
};

class Aco : public Recursos{
public:
    Aco(float pre = 2, float quant = 0) : Recursos(pre, quant) {};
};

class Carvao : public Recursos{
public:
    Carvao(float pre = 1, float quant = 0) : Recursos(pre, quant) {};
};

class Madeira : public Recursos{
public:
    Madeira(float pre = 1, float quant = 0) : Recursos(pre, quant) {};
};

class Vigas : public Recursos{
public:
    Vigas(float pre = 2, float quant = 0) : Recursos(pre, quant) {};
};

class Eletricidade: public Recursos{
public:
    Eletricidade(float pre = 1, float quant = 0) : Recursos(pre, quant) {};
};


#endif //TRABALHO_RECURSOS_H
