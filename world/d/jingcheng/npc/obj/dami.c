#include <ansi.h>
inherit ITEM;
inherit F_FOOD;
void create()
{
       set_name("����",({"da mi","mi"}));
       set_weight(1000);
       if( clonep() )
              set_default_object(__FILE__);
        else {
              set("long","һ������.\n");
              set("unit","��");
                set("value",1000);
                set("food_remaining",4);
                set("food_supply",70);
       }
}
