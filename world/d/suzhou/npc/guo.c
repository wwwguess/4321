//NPC:/d/suzhou/npc/guo.c 
//by dwolf   
//97.11.4

#include <ansi.h>
inherit NPC;           
void create()
{
	set_name(HIM"��Х��"NOR, ({ "guo xiaotian", "guo"}) );
	set("gender", "����" );
	set("age", 68);
        set("long",
		"����һλ���ϵ����ˣ����ò�����֪��Ϊʲô�������ȭ��\n");
	
	set("per", 30);
	set("int", 30);  
	set("str", 40);

	set("combat_exp", 300000);
	set("attitude", "friendly");
	set("rank_info/respect", "Ӣ��");
	set("pursuer", 1);      
	set_skill("iron-cloth", 80);
	set_skill("unarmed", 80);
	set_skill("dodge", 80);
	set_skill("parry", 80);

	set("chat_chance",2);
        set("chat_msg", ({
                YEL"��Х����Ȼ�ӳ�һȭ��������ǽ����һ���󶴡�\n"NOR,
                RED"Ȼ���Х������һ��ɨ���ȣ���һ��˨������������ߵ���\n"NOR,
               
        }) );
	
	setup();
	add_money("silver",0);   
	carry_object(__DIR__"obj/cloth2.c")->wear();
}

