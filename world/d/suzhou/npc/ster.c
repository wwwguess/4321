//NPC:/d/suzhou/npc/ster.c 
//by dwolf   
//97.11.4

#include <ansi.h>
inherit NPC;

void create()
{
	set_name(BLK"���"NOR, ({ "tian er" }) );
	set("gender", "Ů��" );
	set("age", 18);
        set("long",
		"������һ���ɰ���Ů��������΢Ц�ź�ͬ��˵Ц��\n");
	set("combat_exp", 20000);
	set("int",40);
	set("per",40);
	set("attitude", "friendly");
	set("rank_info/respect", "��Ů");
	set("pursuer", 1);
	set("chat_chance",2);
        set("chat_msg", ({
                "���Ц����������....��\n",
        }) );
	
	setup();
	add_money("gold",1);   
	carry_object(__DIR__"obj/cloth.c")->wear();
}

