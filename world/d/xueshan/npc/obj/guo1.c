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
        set_name(RED "ѩɽ���" NOR, ({"xueshan hongguo", "guo"}));
        set_weight(200);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "ö");
                set("long", 
"����һöѩɽ���������ȥ�����ͮͮ�ģ��ǳ�����ϲ����");
                set("value", 50000);
        }

        setup();
}

int do_eat(string arg)
{
        object me = this_player();

        if (!(arg) || arg=="")
                return notify_fail("��Ҫ��ʲô��\n");

        me->add("max_jingli", 5);
        me->add("combat_exp",100);
        me->add("potential",10);
        me->set("food", (int)me->max_food_capacity());
        me->set("water", (int)me->max_water_capacity());
        
        message_vision(HIG
 "$N����һöѩɽ�����ֻ���þ���������Ѫ��ӯ������������������ٸе������ɿ�! \n"NOR,me);

        destruct(this_object());
        return 1;
}
