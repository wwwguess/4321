// sxh.c 
//by dwolf

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIW"ˮ�ɻ�"NOR, ({ "shuixian hua", "hua" }) );
	set_weight(250);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", HIW"һ��Ư����ˮ�ɻ���\n"NOR);
		set("unit", "��");
		set("value", 80);
	}
	setup();
}

