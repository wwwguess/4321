#include <ansi.h>
inherit ITEM;
inherit F_FOOD;
void create()
{
       set_name("�������", ({"yangrou baozi", "baozi" }));
       set_weight(60);
        if(clonep() )
               set_default_object(__FILE__);
         else {
               set("long"," һ���������İ���. \n");
                set("unit","��");
              set("value",150);
               set("food_remaining",2);
               set("food_supply",25);
       }
}
