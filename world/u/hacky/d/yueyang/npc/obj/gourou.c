// turou.c ���չ���
#include <ansi.h>

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name(RED "���չ���" NOR, ({"gou rou", "gou"}));
        set_weight(300);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "һ��������ĺ��չ���\n");
                set("unit", "��");
                set("value", 200);
                set("food_remaining", 4);
                set("food_supply", 50);
        }
}

