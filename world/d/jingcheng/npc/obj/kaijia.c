// kaijia.c
//created by kiss

#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
	set_name(RED "��������" NOR, ({ "kaijia", "jinlun kaijia" }));
	set_weight(20000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", @LONG
����һ��������������ף���Լ�ж�ʮ�����.
LONG
     );

		set("material", "gold");
		set("unit", "��");
		set("value", 50000);
		set("wear_msg",RED "$N����һ���������������.\n" NOR);
		set("remove_msg", HIY "$N���������״���������������\n" NOR);
		set("armor_prop/armor", 40);
	}
	setup();
}
