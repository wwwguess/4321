//NPC:/d/suzhou/npc/lhxiu.c 
//by dwolf   
//97.11.4

#include <ansi.h>
inherit NPC;

void create()
{
	set_name(RED"��ʦʦ"NOR, ({ "li shishi", "li"}) );
	set("gender", "Ů��" );
	set("age", 28);
        set("long",
		"����һ���ɰ���Ů�����ǵ����������ĸ�ˣ�����΢Ц�ź�ͬ��˵Ц��\n");
	set("combat_exp", 20000);
	set("int",40);
	set("per",40);
	set("attitude", "friendly");
	set("rank_info/respect", "��Ů");
	set("pursuer", 1);
	set("chat_chance",2);
        set("chat_msg", ({
                "��ʦʦЦ����������������С��Ƥ����\n",
        }) );
	
	setup();
	add_money("gold",1);   
	carry_object(__DIR__"obj/cloth.c")->wear();
}

