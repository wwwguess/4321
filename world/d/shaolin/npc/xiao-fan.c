// seller.c

inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name("С��", ({ "xiao fan", "seller", "fan" }) );
	set("gender", "����" );
	set("age", 32);
	set("long",
		"���Ǹ�С����������������ʵʵ�������������Ƕ��ͱ��ˡ�\n");
	set("shen_type", 1);
	set("combat_exp", 300);
        set("str", 17);
        set("dex", 20);
        set("con", 17);
        set("int", 22);
	set("attitude", "peaceful");
	set("vendor_goods", ([
		"/d/shaolin/obj/map":-1,
		"/d/shaolin/obj/guide":-1,
                "/obj/food/bottle":-1,
	]) );
	setup();
        carry_object("obj/cloth")->wear();
	add_money("coin", 100);
}
void init()
{
        ::init();
//        add_action("do_buy", "buy");
        add_action("do_vendor_list", "list");
}

