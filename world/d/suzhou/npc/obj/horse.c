// OBJECT:/d/suzhou/npc/obj/horse.c
//by dwolf
//97.11.4 

#include <ansi.h>
inherit ITEM;
void setup()
{}

void init()
{
        add_action("do_ride", "ride");
}

void create()
{
        set_name(BLK"����"NOR, ({"horse", "jun ma", "ma"}));
        set_weight(45000);
        set_max_encumbrance(50000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "ƥ");
                set("long", "һƥ���ֵľ���������(ride)��Ҳ�����Զ�����\n");
                set("value", 1000);
        }
}

int do_ride(string arg)
{
	object me = this_player();
        if (!id(arg))
                return notify_fail("��Ҫ��ʲô��\n");
        if (this_player()->query_temp("marks/��") ) {
                       write(RED"���Ѿ����������ˡ�\n"NOR);
                        return 1;
        }
        else {
               message("vision",this_player()->name() + "��������\n",
                        environment(me), ({me}) );
               write(YEL"��սս���������������ã�����û��������\n"NOR);
                this_player()->set_temp("marks/��", 1);
        return 1;
        }
}
