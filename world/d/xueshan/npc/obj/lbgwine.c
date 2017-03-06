// waterskin.c

inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("�ϰ׸�", ({ "lbgwine", "wnie" }) );
	set_weight(700);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һƿ��ζ�˱ǡ�����������ϰ׸�\n");
		set("unit", "ƿ");
		set("value", 30);
		set("max_liquid", 10);
	}

	// The liquid contained in the container is independent, we set a copy
	// in each cloned copy.
	set("liquid", ([
		"type": "alcohol",
		"name": "�ϰ׸�",
		"remaining": 15,
		"drunk_apply": 4,
	]) );
}
