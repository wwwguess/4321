// silk_bag.c

inherit ITEM;

void create()
{
	set_name("����ԧ��ɰ�", ({ "silk bag", "bag", "###silk bag###" }));
	set_weight(200);
	set_max_encumbrance(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ���幤ʮ�־�ϸ����ɫ˿��ɰ�����������һ��ԧ�졣\n");
		set("value", 0);
		set("material", "silk");
	}
}
