// renshen-guo.c �˲ι�
#include <ansi.h>

inherit ITEM;

int do_eat(string);
void init();

void init()
{
        if (!wizardp(this_player())) {
                set("no_get", "�ٺ٣����ΰ�! \n");
                set("no_drop","��ô������˲ι�����������! \n");
        }
                                              
        add_action("do_eat", "eat");
}

void create()
{
        set_name(HIG "�˲ι�" NOR, ({"renshen guo", "guo"}));
        set_weight(20);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "ö");
                set("long", 
"����һö�˲ι�������ȥ����һ���װ����ֵ�С����");
                set("value", 100000);
        }

        setup();
}

int do_eat(string arg)
{
        object me = this_player();

        if (!id(arg))
                return notify_fail("��Ҫ��ʲô��\n");

        me->set("eff_jing", (int)me->query("max_gin"));
        me->set("gin", (int)me->query("max_gin"));
        me->set("eff_qi", (int)me->query("max_kee"));
        me->set("kee", (int)me->query("max_kee"));
        me->set("force", (int)me->query("max_force"));
        me->set("food", (int)me->max_food_capacity());
        me->set("water", (int)me->max_water_capacity());
        
        message_vision(HIG
 "$N����һö�˲ι���ֻ���þ���������Ѫ��ӯ����������ԴԴ�������������ٸе������ɿ�! \n"NOR,me);

        destruct(this_object());
        return 1;
}