//OBJ:/d/suzhou/npc/obj/blade.c 
//by dwolf
//97.11.4

#include <weapon.h> 
#include <ansi.h>
inherit BLADE;

void create()
{
	set_name(CYN"�嵶"NOR, ({ "pei blade", "blade" }) );
	set_weight(5000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long",  "����һ�ѷ������嵶��ֻ������ѩ��������ҫ�۵Ĺ�â�����˲��ұ���.\n");
		set("value", 2400);
		set("material", "greysteel");
		set("wield_msg", "$N���һ�ѷ������嵶��\n");
		set("unwield_msg", "$N���嵶�������䡣.\n");
	}
	init_blade(80);
	setup();
}
