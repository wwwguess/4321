// longsword.c ����

#include <weapon.h>
inherit SWORD;

void create()
{
	set_name("��Ħ��", ({ "damo sword", "damo", "sword" }));
	set_weight(6000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "�����ഫ��Ħ��ʦ�����Ħ����ʱ�õĽ�������һ��\n"
                            "  �ĸֽ�Ҫ�أ�����ī�ڣ���֪��ʲô�����������ɡ�\n");
		set("value", 300000);
		set("material", "steel");
		set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n��ؽ��ʡ�\n");
	}
	init_sword(150);
	setup();
}
int auto_load(){ return 1; }
