// yblade.c

#include <weapon.h> 
#include <ansi.h>

inherit BLADE;

void create()
{
	set_name(CYN"ԧ�쵶"NOR, ({ "yuanyang blade", "blade" }) );
	set_weight(15000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", 
YEL"�����������ԧ�쵶��ֻ������ѩ��������ҫ�۵Ĺ�â�����˲��ұ���.\n"NOR);
		set("value", 3000);
		set("material", "greysteel");
		set("wield_msg", MAG"ֻ������һ����$N�������Ѿ�����һ�Ѻ���
����ı�������$n��\n" NOR);
		set("unwield_msg", MAG"����һ����ԧ�쵶�Ѳ�����.\n" NOR);
	}
	init_blade(50);
	setup();
}
