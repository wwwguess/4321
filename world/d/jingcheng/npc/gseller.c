// gseller.c
//by dwolf 

#include <ansi.h>

inherit NPC;
inherit F_VENDOR;  

void create()
{
        set_name(HIM"ţ��"NOR, ({ "niu er","seller" }));
	set("title", RED"�������"NOR); 
	set("shen_type", 1);

	set("str", 25);
	set("gender", "����");
	set("age", 18);
	set("long", "ţ���������ۺã��ַ�Ȥ��Ĭ��������ϲ����\n");
	set("combat_exp", 10000);
        set("kee", 150);
        set("max_kee", 150);
	set("attitude", "friendly");
	set_skill("unarmed", 40);
        set_skill("dodge", 40);
        set_temp("apply/attack", 10);
        set_temp("apply/defense", 10);
	set("vendor_goods", ([
               "ѩ�����": __DIR__"obj/gaodian1.c",
               "���": __DIR__"obj/gaodian2.c",    
	]));     

	setup();
	set("chat_chance", 10);
        set("chat_msg", ({
                YEL"����ร���������ร��ֳ���������\n"NOR, 
		YEL"������ӣ���Ҳ���ˡ�ɢ��ʱ����һ��ؼҰɣ�\n"NOR,   
	(: random :)
        }) );

	add_money("silver", 5);
}

void init()
{
        add_action("do_vendor_list", "list");   
}   

