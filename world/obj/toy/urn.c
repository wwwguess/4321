// urn.c

inherit ITEM;

void create()
{
	set_name("ҩ��", ({ "urn" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long",
			"����������ҩ��ҩ�ޣ�����԰��ʵ�������ҩ��\n"
			"�Ž�ȥ��Ȼ�Ὣҩ�޷ŵ���¯�ϼ塣\n"
		);
		set("unit", "��");
		set("weight", 1200);
		set("value", 600);
	}
	set_max_encumbrance(1500);
}
