// red_guay.c

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("����", ({ "red guay", "guay" }) );
	set_weight(180);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ��������������\�˸�ӡ�ӣ���������\n");
		set("unit", "��");
		set("value", 25);
		set("food_remaining", 6);
		set("food_supply", 45);
	}
}
