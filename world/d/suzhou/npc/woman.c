//NPC:/d/suzhou/npc/woman.c 
//by dwolf   
//97.11.7

#include <ansi.h>
inherit NPC;

void create()
{
	set_name(BLK"����"NOR, ({ "fu ren", "woman" }) );
	set("gender", "Ů��" );
	set("age", 38);
        set("long",
		"����һλ����ĸ��ˣ����ϵ�����\n");
	set("combat_exp", 500);
	set("attitude", "friendly");
	set("rank_info/respect", "��Ů");
	set("pursuer", 1);
	set("chat_chance",2);
    
	setup();
	add_money("silver",1);   
	carry_object(__DIR__"obj/cloth.c")->wear();
}

