// token.c

inherit ITEM;

void create()
{
	set_name("ɱ������", ({ "token", "###token###" }));
	set_weight(200);
	set_max_encumbrance(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ����ľ����ɱ�����ƣ�������������ͼ�ڱ�־��\n");
		set("value", 1200);
		set("material", "wood");
	}
}
