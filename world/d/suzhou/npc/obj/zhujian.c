//OBJECT:/d/suzhou/npc/obj/zhujian.c 
//by dwolf
//97.11.5

#include <ansi.h>
#include <weapon.h>
inherit SWORD;

void create()
{
	set_name(MAG"��"NOR, ({ "zhu jian", "jian" }));
	set_weight(5000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ����ͨ����,��������ϰ�á�\n");
		set("value", 10);
		set("material", "bamboo");
		set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n��ؽ��ʡ�\n");
	}
	init_sword(2);
	setup();
}
