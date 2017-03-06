// dead_leech.c

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("������", ({ "dead leech", "leech" }) );
	set_weight(700);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ������Ӳ�������Σ�Ҫ���ǻ����˵���ɫ��������������Щ����������\n");
		set("unit", "ֻ");
		set("value", 0);
		set("food_remaining", 3);
		set("eat_func", (: eat_tonic :) );
		set("tonic", ([ "force": 1, "max_mana": 60 ]) );
		set("food_supply", 70);
	}
	call_out("decay", 240);
}

static void decay()
{
	say("�����η���һ�����ŵĶ�����õ��� ... \n");
	destruct(this_object());
}
