//NPC:/d/suzhou/npc/hhgz.c
//by dwolf              
//97.11.4

#include <ansi.h>
inherit NPC;

void create()
{
	set_name(BLK"��������"NOR, ({ "huahua gongzi", "gongzi" }));
	set("gender", "����");
	set("age", 40);
	set("long",
        	RED"�����Ż�������Ŀ�׶񣬿������ڿ������ݺݵص�����һ�ۡ�\n"NOR);

	set("attitude", "peaceful");

	set("str", 26);
	set("int", 25);

	set("combat_exp", 30000);
        	
		
	set("chat_chance", 5);
	set("chat_msg", ({
		MAG"������������ص�������С椲����� \n"NOR,
	}) );
	
	set("force", 200);
	set("max_force", 200);
	set("force_factor", 5);

	set_skill("dodge", 30);
	set_skill("blade", 40);
	set_skill("parry", 50);
	set_skill("force", 30);
	set_skill("unarmed", 40);
	
	setup();

	carry_object(__DIR__"obj/cloth")->wear();   
}      


