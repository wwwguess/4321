// tail.c

#include <weapon.h>

inherit WHIP;

void create()
{
        set_name("ţβ", ({ "tail" }) );
        set_weight(200);
	set("long", "һ���ִ��ֳ���ţβ\n");
	set("unit", "��");
	set("value", 50);
        set("material", "skin");
        set("wield_msg", "$Nץ��һ��$n���������е�������\n");
        init_whip(2);
        setup();
}

