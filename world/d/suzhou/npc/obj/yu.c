//yu.c
//by dwolf         

#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name( MAG"糖醋鱼"NOR, ({ "yu", "tangcu yu" }) );  
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {  
		set("food_supply", 50);
		set("food_remaining", 5);
              	  set("unit", "条");
		set("long", MAG"这是做老先生亲自做的糖醋鱼，很好吃，很少见的喔。"NOR);
           set("value", 5000);
        }
        setup();
}
