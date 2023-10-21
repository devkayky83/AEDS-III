#ifndef GRAFO_HPP
#define GRAFO_HPP

class Vertice 
{
    private:
    int id;
    int x;
    int y;

    public:
    Vertice()
    {
        id = 0;
        x = 0;
        y = 0;
    }

    Vertice(int id, int x, int y)
    {
        this->id = id;
        this->x = x;
        this->y = y;
    }

    int getX() 
    {
        return x;
    }

    void setX(int x) 
    {
        this->x = x;
    }

    int getY() 
    {
        return y;
    }

    void setY(int y) 
    {
        this->y = y;
    }

    int getId() 
    {
        return id;
    }

    void setId(int id) 
    {
        this->id = id;
    }
};

#endif