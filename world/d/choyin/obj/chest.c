// chest.c

inherit ITEM;

void create()
{
	set_name("��ľ��", ({ "peach chest", "chest" }) );
	set_weight(1400);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ���̹���վ�ϸ����ľ�䣬Ҳ��\������װ�����õġ�\n");
		set("value", 300);
		set("material", "wood");
	}
}
