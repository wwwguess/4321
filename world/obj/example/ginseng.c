// ginseng.c

inherit COMBINED_ITEM;

void create()
{
	set_name("�˲�", ({"ginseng"}) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "�˲���һ�������Ĳ�Ʒ��\n");
		set("unit", "Щ");
		set("base_unit", "֦");
		set("base_weight", 70);
		set("base_value", 400);
		set("medical_effect/ľ", ({ 6, 5, 10 }) );
	}
	set_amount(1);
}
