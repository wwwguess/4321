//NPC:/d/suzhou/npc/surr.c 
//by dwolf   
//97.11.4

#include <ansi.h>
inherit NPC;

void create()
{
	set_name(YEL"�����"NOR, ({ "mu nianci", "mu"}) );
	set("gender", "Ů��" );
	set("age", 38);
        set("long",
		"����������ȣ�����΢Ц�ź�ͬ�����죬ż�����������������Ȼʧɫ��\n");
	set("combat_exp", 20000);
	set("int",70);
	set("attitude", "friendly");
	set("rank_info/respect", "��Ů");
	set("pursuer", 1);
	set("chat_chance",2);
        set("chat_msg", ({
                "����ȶ�ͬ��˵�������ҵĹ������Ķ�ȥ����?��\n",
        }) );
	
	setup();
	add_money("gold",1);   
	carry_object(__DIR__"obj/cloth.c")->wear();
}

