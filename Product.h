//
// Created by Mirolena on 12/22/2021.
//
#include<iostream>
#include<string>
#include<vector>
using namespace std;
#ifndef MUSICSTORE_MUSICSTORE_H
#define MUSICSTORE_MUSICSTORE_H

///clasa de baza
class Product
{
private:

    float price;
    string name;

public:

    Product(float price1, const string &name1);
    Product();

    friend ostream &operator<<(ostream &os, Product &product);//TODO de revenit cu const
    virtual ostream& write(ostream& os);

    friend istream &operator>>(istream &in, Product &product);
    virtual istream& read(istream& in);

    void setPrice(float price);
    void setName(const string &name);

    float getPrice() const;
    const string &getName() const;

    virtual bool isCompatibleWith(Product *other);

};


///clasa Song
class Song:public Product
{
private:

    string author, title;
    float lenght;
    bool type;

public:

    Song(float price, const string &name, const string &author, const string &title, float lenght, bool type);
    Song();

    ostream &write(ostream &os) override;
    istream &read(istream &in) override;

    void setType(bool type);
    bool isType() const;

    const string &getTitle() const;

    void setTitle(const string &title);

    bool isCompatibleWith(Product *other) override;
};

#endif //MUSICSTORE_MUSICSTORE_H

///Clasa Music_player
class Music_player:public Product
{
private:
    string title, author;
    bool type;

public:
///constructori
    Music_player(float price1, const string &name1, const string &title, const string &author);
    Music_player();

    ostream &write(ostream &os) override;
    istream &read(istream &in) override;

    void setType(bool type);
    bool isType() const;

    const string &getTitle() const;

    void setTitle(const string &title);

    bool isCompatibleWith(Product *other) override;
};

///clasa Sticker
class Sticker:public Product
{
private:
    string text;

public:
    Sticker(float price1, const string &name1, const string &text);
    Sticker();

    ostream &write(ostream &os) override;

    istream &read(istream &in) override;

    const string &getText() const;

    void setText(const string &text);

    bool isCompatibleWith(Product *other) override;
};

Product* alocDinam(Product* product);

///clasa MusicStore
class MusicStore
{
private:
    vector<Product*> products;

public:
    friend ostream &operator<<(ostream &os, const MusicStore &store);

    MusicStore:: MusicStore(const vector<Product *> &_products);


    virtual ~MusicStore();
    void addProduct();
    void addProduct(const Product& newProduct);
    void run();
    void showMenu();
    void compare();
};

