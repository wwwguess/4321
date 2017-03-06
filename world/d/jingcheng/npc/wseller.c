// wseller.c
//by dwolf 

#include <ansi.h>

inherit NPC;
inherit F_VENDOR;  

void create()
{
        set_name(HIM"�찢��"NOR, ({ "zhu axiang", "zhu" }));
	set("title", YEL"�������"NOR); 
	set("shen_type", 1);

	set("str", 18);
	set("gender", "Ů��");
	set("age", 18);
	set("long", "�����Ǹ�ͦƯ���Ĺ������ţ�����ھӣ����˷ǳ�Ҫ�á�\n");
	set("combat_exp", 10000);
        set("kee", 150);
        set("max_kee", 150);
	set("attitude", "friendly");
	set_skill("unarmed", 40);
        set_skill("dodge", 40);
        set_temp("apply/attack", 10);
        set_temp("apply/defense", 10);
	set("vendor_goods", ([
              "���«":  __DIR__"obj/wanju1.c",
                "���":__DIR__"obj/wanju2.c",    
	]));     

	setup();
	set("chat_chance", 10);
        set("chat_msg", ({
                MAG"������ţ�Ҷ��硣�ð���\n"NOR, 
		MAG"�����ѽ�������ѽ����\n"NOR,      
		(: random_move :)
        }) );

	add_money("silver", 5);
}

void init()
{
        add_action("do_vendor_list", "list");   
}   

