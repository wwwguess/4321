// hsbi.c 

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIB"�����"NOR, ({ "heshi bi", "bi" }) );
	set_weight(3000);
	set_max_encumbrance(5000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
                set("long", HIR"ս��ʱ���Ի����ųأ�˫���ѿ���֮�����ڱ���֮��\n
������սһ�������ľ���������\n"NOR);
		set("value", 500000);
		set("material", "greysteal");
		set("no_get",0);
		set("no_drop",1);
		set("amount",30);
	}
	setup();
}

