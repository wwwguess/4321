// cake.c

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("ɽҩ��", ({ "tomatoo"}) );
	set_weight(130);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "Բ�����ɽҩ����߯���ʡ�\n");
		set("unit", "��");
		set("value", 25);
		set("food_remaining", 5);
		set("food_supply", 10);
	}
}
