// fireplace.c

inherit ITEM;

void create()
{
	set_name("��¯", ({ "fireplace" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ����ҩ�õĻ�¯��������������̿��\n");
		set("no_get", "�����¯���̶��ڵ��ϣ��ò�������\n");
		set("unit", "��");
		set("weight", 8000);
		set("value", 700);
	}
	set_max_encumbrance(9000);
}

void insert_object(object ob)
{
	if( ob->to_burn() ) return;

	seteuid(getuid());
	switch( (string)ob->query("material")) {
		case "cloth":
		case "paper":
			message("vision", ob->name() + "���˻𣬺ܿ���յ��ˡ�\n", environment() );
			message("vision", ob->name() + "���˻𣬺ܿ���յ��ˡ�\n", this_object() );
			destruct(ob);
			return;
		default:
			return;
	}
}
