#include<iostream>
#include<string>
#include "Product.h"
#include<vector>
using namespace std;
int main()
{

    Song *s1=new Song(22,"While my guitar gently weeps","The Beatles","While my guitar gently weeps",4,0);
    Song *s2=new Song(30,"Dance me to the end of love","Madeleine Peyroux","Dance me to the end of love",3,0);
    Song *s3=new Song(22,"I want it all","Arctic Monkeys","I want it all",3,0);
    Song *s4=new Song(22,"Balaclava","Arctic Monkeys","Balaclava",3,0);
    Sticker *st1=new Sticker(5,"Balaclava","Balaclava");
    Sticker *st2=new Sticker(6,"Dance","Dance me");
    Music_player *p1= new Music_player(22,"","ceva","cineva");
    vector <Product*> v={s1,s2,s3,s4,p1,st1,st2};
    MusicStore shop{v};
//    cout<<shop;
//    MusicStore ceva();
//    shop.addProduct();

      shop.run();
}


