// ghost_cash.c

inherit COMBINED_ITEM;

void create()
{
	set_name("ڤֽ", ({ "ghost cash", "cash" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "�������������ո��������ѵ�ڤֽ��Ҳ�����׳Ƶ�ֽǮ��\n");
		set("unit", "��");
		set("material", "paper");
		set("base_unit", "��");
		set("base_weight", 3);
		set("base_value", 1);
	} 
	set_amount(1);
}
