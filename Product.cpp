//
// Created by Mirolena on 12/22/2021.
//
#include<iostream>
#include<string>
#include<vector>
#include "Product.h"
using namespace std;

///cautare cuvant
int f_word(string word, string s)
{
    int i=0,pos = 0;
    while(i==0) {
        pos =  s.find(word, ++pos);
        if (pos != std::string::npos) {
            i++;
        }
        else break;
    }

    return i;
}

///split in cuvinte
int split(string str1,string prop)
{
    string word = "";
    for (auto y : str1)
    {
        if (y == ' ')
        {
            if(f_word(word,prop)==1) return 1;
            word = "";
        }
        else {
            word = word + y;
        }
    }
    if(f_word(word,prop)==1) return 1;

    return 0;
}

///clasa Product
//constructori
Product::Product(float price1, const string &name1)
{
  price=price1;
  name=name1;
}
Product::Product() :Product(0, "0")
{

}

//supraincarcare operatori
ostream &operator<<(ostream &os, Product &product) {
    product.write(os);
     return os;
}
ostream &Product::write(ostream &os)
{
    os<<" Price: "<<price<<" Name: "<<name;
    return os;
}

istream &operator>>(istream &in, Product &product) {
    product.read(in);
    return in;
}
istream& Product::read(istream &in)
{
    cout<<" Price: ";
    in>>price;
    cout<<" Name: ";
    in.get();
    getline(in, name);
    return in;
}

//setteri
void Product::setPrice(float price)
{
    Product::price = price;
}
void Product::setName(const string &name)
{
    Product::name = name;
}

//getteri
float Product::getPrice() const
{
    return price;
}
const string &Product::getName() const
{
    return name;
}


///iscompatible with
bool Product :: isCompatibleWith(Product*other)
{
return 0;
}




///Clasa Song
//constructori
Song::Song(float price, const string &name, const string &author, const string &title, float lenght, bool type)
        : Product(price, name), author(author), title(title), lenght(lenght), type(type)
        {

        }
        Song::Song()
{
    author="0";
    title="0";
    lenght=0;
    type=0;
}

//supraincarcare operatori
istream &Song::read(istream &in)
{
    Product::read(in);
    cout<<"Author:";
    getline(in,author);
    cout<<"Title:";
    getline(in,title);
    cout<<"Length:";
    in>>lenght;
    cout<<"Type:";
    in>>type;
    return in;
}
ostream &Song::write(ostream &os) {
    Product::write(os);

    os<<" Author: "<<author<<endl<<" Title: "<<title<<endl<<" Lenght: "<<lenght<<endl<<" Type: "<<type;
    return os;
}

void Song::setType(bool type) {
    Song::type = type;
}
bool Song::isType() const {
    return type;
}

const string &Song::getTitle() const {
    return title;
}
void Song::setTitle(const string &title) {
    Song::title = title;
}


///clasa Music_player
//constructori
Music_player::Music_player(float price1, const string &name1, const string &title, const string &author) : Product(
        price1, name1), title(title), author(author) {}

Music_player::Music_player()
{
    title="0";
    author="0";
}

//supraincarcare operatori
ostream &Music_player::write(ostream &os) {
    return Product::write(os);
}
istream &Music_player::read(istream &in) {
    return Product::read(in);
}

bool Music_player::isType() const {
    return type;
}
void Music_player::setType(bool type) {
    Music_player::type = type;
}

const string &Music_player::getTitle() const {
    return title;
}
void Music_player::setTitle(const string &title) {
    Music_player::title = title;
}


///clasa Sticker
//constructori

Sticker::Sticker(float price1, const string &name1, const string &text) : Product(price1, name1), text(text) {}

Sticker::Sticker()
{
    text="0";
}

//supraincarcare operatori
ostream &Sticker::write(ostream &os) {
    return Product::write(os);
}
istream &Sticker::read(istream &in) {
    return Product::read(in);
}

const string &Sticker::getText() const {
    return text;
}
void Sticker::setText(const string &text) {
    Sticker::text = text;
}

///functie gasire tipul produsului
int GetType(Product *p)
{
    if(dynamic_cast<Song*>(p)!= nullptr)return 1; ///e song
    if(dynamic_cast<Music_player*>(p)!=nullptr)return 2;///e music player
    else return 3;///e sticker
}

///functie de alocare dinamica
Product* alocDinam(Product* product)
{
    Product* productPtr=dynamic_cast<Product*>(product);
    Song* songPtr=dynamic_cast<Song*>(product);
    Music_player* music_playerPtr=dynamic_cast<Music_player*>(product);
    Sticker* stickerPtr=dynamic_cast<Sticker*>(product);
    if(stickerPtr!= nullptr)
    {
        Sticker* tmp=new Sticker(*stickerPtr);
        return tmp;
    }
    if(music_playerPtr!= nullptr)
    {
        Music_player* tmp=new Music_player(*music_playerPtr);
        return tmp;
    }
    if(songPtr!= nullptr)
    {
        Song* tmp=new Song(*songPtr);
        return tmp;
    }
    if(productPtr!= nullptr)
    {
        Product* tmp=new Product(*productPtr);
        return tmp;
    }
    return nullptr;
}

///clasa MusicStore
//supraincarcare
ostream &operator<<(ostream &os, const MusicStore &store)
{
    os << "products: ";
    for(auto*item: store.products)
    {
        os<<*item<<" ";
    }
    return os;
}
//constructor
MusicStore::MusicStore(const vector<Product *> &_products) {
    for(auto *item:_products){
        Product* newProduct;
        newProduct= alocDinam(item);
        products.push_back( newProduct );
    }
}
//destructor
MusicStore::~MusicStore() {

}

void MusicStore:: compare()
{
    for(auto i:products)
     for(auto j:products)
    {

        if(GetType(i)==1 && i->isCompatibleWith(j))
        {
            cout<<endl;
            cout<<i->getName()<<" is compatible with "<<j->getName();
        }
        if(GetType(i)==2 && i->isCompatibleWith(j))
        {
            cout<<endl;
            cout<<i->getName()<<" is compatible with "<<j->getName();
        }
        if(GetType(i)==3 && i->isCompatibleWith(j))
        {
            cout<<endl;
            cout<<i->getName()<<" is compatible with "<<j->getName();
        }

    }
}

///functiile addProduct
void MusicStore :: addProduct()
{
    int prod;
    cout<<"\nAdd a product:\n"
          "1.Song\n"
          "2.Music player\n"
          "3.Sticker";
    cin>>prod;
    if(prod==1)
    {
     Song *temp=new Song();
     cin>>*temp;
     products.push_back(temp);
    }

    if(prod==2)
    {
        Music_player *temp2=new Music_player();
        cin>>*temp2;
        products.push_back(temp2);
    }

    if(prod==3)
    {
        Sticker *temp3=new Sticker();
        cin>>*temp3;
        products.push_back(temp3);
    }

    else if(prod!=2 && prod!=1)
    {
     cout<<"The product doesn't exist";
    }
}
void MusicStore :: addProduct(const Product& newProduct){
    Product* prod= nullptr;
    int c=0;
    try{
        auto pr=dynamic_cast<const Song&>(newProduct);
        prod=new Song(pr);
    }
    catch (bad_cast&){c++;}
    try{
        auto pr=dynamic_cast<const Music_player&>(newProduct);
        prod=new Music_player(pr);
    }
    catch (bad_cast&){c++;}
    try{
        auto pr=dynamic_cast<const Sticker&>(newProduct);
        prod=new Sticker(pr);
    }
    catch (bad_cast){c++;}
    if(c==3)cout<<"That is not a product";
    else products.push_back(prod);

}




///iscompatible with song
bool Song::isCompatibleWith(Product *other)
{
    if (GetType(other)==1)
    {
        Song* s=dynamic_cast<Song*>(other);
        if(s->author==author)
            return 1;
        return 0;
    }
    else if(GetType(other)==2)
    {
        Music_player* m=dynamic_cast<Music_player*>(other);
        if(m->isType() ==type)
            return 1;
        return 0;
    }
    else
    {
        Sticker* s=dynamic_cast<Sticker*>(other);
        split(title,s->getText());

    }
    return 0;
}

///iscompatible with music player
bool Music_player::isCompatibleWith(Product *other)
{
    if (GetType(other)==1)
    {
        Song* s=dynamic_cast<Song*>(other);
        if(s->isType() ==type)
            return 1;
        return 0;
    }

    else if(GetType(other)==3)
    {
        Sticker* s=dynamic_cast<Sticker*>(other);
        split(title,s->getText());

    }
    return 0;
}

///iscompatible with sticker
bool Sticker::isCompatibleWith(Product *other)
{   if(GetType(other)==1)
    {
        Song* s=dynamic_cast<Song*>(other);
        split(s->getTitle(),text);

    }
      else if(GetType(other)==2)
    {
        Music_player* m=dynamic_cast<Music_player*>(other);
        split(m->getTitle(),text);
    }
    return 0;
}




///meniul
void MusicStore:: showMenu()
{
    cout<<"\n1.Show all the products\n";
    cout<<"2.Add a new product\n";
    cout<<"3.Show all the products that are compatible\n";
    cout<<"4.Exit\n";
}


///functia run
void MusicStore:: run() {

    int option;
    while (true) {
        showMenu();
        cout << "Option: ";
        cin >> option;
        if (option == 1) {
            cout << *this;
        } else if (option == 2) {
            addProduct();
        } else if (option == 3)
        {
            compare();
        }
        else { break; }
    }
}