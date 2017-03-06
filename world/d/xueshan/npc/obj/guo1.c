//guo2.c 
//by dwolf

#include <ansi.h>
inherit ITEM;

int do_eat(string);
void init();

void init()
{                  
        add_action("do_eat", "eat");
}

void create()
{
        set_name(RED "雪山红果" NOR, ({"xueshan hongguo", "guo"}));
        set_weight(200);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "枚");
                set("long", 
"这是一枚雪山红果，看上去就像红彤彤的，非常惹人喜欢。");
                set("value", 50000);
        }

        setup();
}

int do_eat(string arg)
{
        object me = this_player();

        if (!(arg) || arg=="")
                return notify_fail("你要吃什么？\n");

        me->add("max_jingli", 5);
        me->add("combat_exp",100);
        me->add("potential",10);
        me->set("food", (int)me->max_food_capacity());
        me->set("water", (int)me->max_water_capacity());
        
        message_vision(HIG
 "$N吃下一枚雪山红果，只觉得精神健旺，气血充盈，精神焕发，甚至不再感到饥饿干渴! \n"NOR,me);

        destruct(this_object());
        return 1;
}
