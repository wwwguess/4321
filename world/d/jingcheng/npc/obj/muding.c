// kaoya.c ��Ѽ
#include <ansi.h>
inherit ITEM;


void create()
{
	set_name(RED"��ľ��"NOR, ({"muding", "ding"}));
	set_weight(300);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ������������ľ��\n");
		set("unit", "��");
		set("value", 3000);
		
	
	}
}
