#include "GildedRose.h"


GildedRose::GildedRose(::std::vector<Item> const& items) : items(items)
{}

GildedRose::GildedRose(::std::vector<Item> && items) : items(::std::move(items))
{}

void GildedRose::updateQuality()
{
    for (int i = 0; i < items.size(); i++)
    {
        if(items[i].name != "Sulfuras, Hand of Ragnaros")
        {
            if (items[i].name != "Aged Brie" && items[i].name != "Backstage passes to a TAFKAL80ETC concert")   
            {
                if (items[i].quality > 0 ) // III
                {
                    if(items[i].sellIn > 0)
                    {
                        items[i].quality -= 1;  // I
                    }
                    else
                    {
                        items[i].quality -= 2;
                    }
                }
            }
            else  // I - 1, 3
            {
                if (items[i].quality < 50) // IV
                {
                    items[i].quality += 1; 

                    if (items[i].name == "Backstage passes to a TAFKAL80ETC concert")  // I - 3
                    {
                        if (items[i].sellIn < 11)  // a
                        {
                            if (items[i].quality < 50) // IV
                            {
                                items[i].quality += 1;
                            }
                        }

                        if (items[i].sellIn < 6)  // b
                        {
                            if (items[i].quality < 50) // IV
                            {
                                items[i].quality += 1;
                            }
                        }
                    }
                }
            }
            items[i].sellIn -= 1;

            if (items[i].sellIn < 0 && items[i].name == "Backstage passes to a TAFKAL80ETC concert") 
            {
                items[i].quality = 0;
            }

            if(items[i].sellIn < 0 && items[i].quality < 50 &&items[i].name == "Aged Brie")
            {

                items[i].quality += 1;
            }
        }    
    }

}