//OBJ:/d/fgszhuang/npc/obj/coldb.c 
//by tlang
//97.11.4

#include <weapon.h> 
#include <ansi.h>
inherit BLADE;

void create()
{
	set_name(GRN"���±���"NOR, ({ "lengyue blade", "blade" }) );
	set_weight(8000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long",  "����һ�ѷ����ĵ���ֻ������ѩ��������ҫ�۵Ĺ�â�����˲��ұ���.\n");
		set("value", 24000);
		set("material", "greysteel");
		set("wield_msg", YEL"ֻ������һ����$N�������Ѿ�����һ�Ѻ�������ı�����\n" NOR);
		set("unwield_msg", MAG"����һ���������Ѳ�����.\n" NOR);
	}
	init_blade(300);
	setup();
}
