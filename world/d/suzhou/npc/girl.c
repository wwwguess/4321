//NPC:/d/suzhou/npc/girl.c 
//by dwolf   
//97.11.4

#include <ansi.h>
inherit NPC;

void create()
{
	set_name(YEL"Ů��"NOR, ({ "girl"}) );
	set("gender", "Ů��" );
	set("age", 18);
        set("long",
		"����һλ̤����Ů������΢Ц�ź�ͬ��˵Ц��\n");
	set("combat_exp", 200);
	set("attitude", "friendly");
	set("rank_info/respect", "��Ů");
	set("pursuer", 1);
	set("chat_chance",2);
        set("chat_msg", ({
                "Ů����ͬ��˵��������˵����԰�ֺܺ���ร���\n",
                "Ů�������㣬Ц��������Ҳ������԰�ֵ�ô����\n",
                (: random_move :)
        }) );
	
	setup();
	add_money("silver",1);   
	carry_object(__DIR__"obj/cloth.c")->wear();
}

