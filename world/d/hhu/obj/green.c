inherit ITEM;
inherit F_FOOD;

void create()
{
     set_name("绿果",({"green"}));
    set_weight(1000);
    if( clonep() )
            set_default_object(__FILE__);
    else {
          set("long","这个无名果看上去很诱人，你恨不得一口就吞下去！\n");
 	  set("unit","颗");
          set("value",100);
          set("food_remaining",1);
          set("food_supply", 80);
     }
}


