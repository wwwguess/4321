// lingpai.c 
// Made by Ysg(1997.10.20)

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(YEL"����������"NOR, ({ "lingpai", "ling" }) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
                set("long", YEL"����һ����Ӳӵ����ƣ�������ż����֣��ظ�ͨ�á�\n"NOR);
		set("value", 1000);
		set("material", "gold");
		set("no_get",0);
		set("no_drop",1);
	}
	setup();
}

