// mdan.c 
//by dwolf

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(YEL"ĵ����"NOR, ({ "mudan hua", "hua" }) );
	set_weight(250);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", YEL"һ��Ư����ĵ����,�˳ƻ��лʺ�\n"NOR);
		set("unit", "��");
		set("value", 180);
	}
	setup();
}

