// wanju1.c //by dwolf


#include <ansi.h>

inherit ITEM;
inherit F_LIQUID;

void create()
{
 set_name("���«", ({ "qing hulu", "hulu" }) );
	set_weight(400);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", HIC"����һ������ɫ�ĺ�«������͸����ɫʮ������ϲ����\n"
"��«�Ͽ�������������ͦ�����,������װˮ��\n"NOR);
		set("unit", "��");
		set("value", 80);
		set("max_liquid", 60);
	}

		set("liquid", ([
		"type": "water",
		"name": "��Ȫˮ",
		"remaining": 60,
	]) );
}
