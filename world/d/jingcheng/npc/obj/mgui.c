// mgui.c 
//by dwolf

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(RED"õ�廨"NOR, ({ "meigui hua", "hua" }) );
	set_weight(250);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", RED"һ��Ư����õ�廨,�����е��˿��ٲ���ม�\n"NOR);
		set("unit", "��");
		set("value", 100);
	}
	setup();
}

