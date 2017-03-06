// tseller.c
//by dwolf 

#include <ansi.h>

inherit NPC;
inherit F_VENDOR;  

void create()
{
        set_name(HIM"������"NOR, ({ "tangren wang", "wang" }));
	set("title", YEL"������"NOR); 
	set("shen_type", 1);

	set("str", 25);
	set("gender", "����");
	set("age", 20);
	set("long", "����������Ͳ����������˿ɺ��ˣ��ǿ������Ҵ�������\n");
	set("combat_exp", 10000);
        set("kee", 150);
        set("max_kee", 150);
	set("attitude", "friendly");
	set_skill("unarmed", 40);
        set_skill("dodge", 40);
        set_temp("apply/attack", 10);
        set_temp("apply/defense", 10);
	set("vendor_goods", ([
               "���������": __DIR__"obj/tren1.c",
               "��˽�����": __DIR__"obj/tren2.c",    
		"ɳɮ����":__DIR__"obj/tren3.c",
	"��ɮ����":	__DIR__"obj/tren4.c",
	]));     

	setup();
	set("chat_chance", 10);
        set("chat_msg", ({
                YEL"����������ร�\n"NOR, 
		YEL"�۸���ˣ���Ҷ����԰����Ǻǣ���\n"NOR,
        }) );

	add_money("silver", 5);
}

void init()
{
        add_action("do_vendor_list", "list");   
}   

