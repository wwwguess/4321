// melon.c

inherit ITEM;
//inherit F_LIQUID;
inherit F_FOOD;

void create()
{
	set_name("����", ({ "water melon", "melon" }) );
	set_weight(1200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ����Ƥī�ƵĴ����ϣ�������ʣ���������ӡ�\n");
		set("unit", "��");
		set("value", 60);
		set("drink_func",1);
		set("food_remaining", 8);
		set("water_supply", 40 );
		set("food_supply", 20);
		set("max_liquid", 15);
	}

	// The liquid contained in the container is independent, we set a copy
	// in each cloned copy.
	set("liquid", ([
		"type": "water",
		"name": "����֭",
		"remaining": 15,
	]) );
}

int finish_eat()
{
	set_name("����Ƥ", ({ "bone" }) );
	set_weight(150);
	set("long", "һ��еþ��������Ƥ��\n");
	return 1;
}
