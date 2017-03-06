//NPC:/d/suzhou/npc/myren.c
//by dwolf
//97.11.4

#include <ansi.h>
inherit NPC;

void create()
{
	set_name(BLK"������"NOR, ({ "mai yi ren", "ren" }));
	set("gender", "����");
	set("age", 50);
	set("long",
        	RED"�������ƾɣ���Ŀ��ɣ�����������ӹ��ò���ô����\n"NOR);

	set("attitude", "peaceful");

	set("str", 26);
	set("int", 25);

	set("combat_exp", 300000);
        	
	set("chat_chance", 5);
	set("chat_msg", ({
		BLK"��λ��ү����������������"NOR,
	}) );
	
	set("force", 300);
	set("max_force", 300);
	
	set_skill("dodge", 60);
	set_skill("blade", 60);
	set_skill("parry", 60);
	set_skill("force", 60);
	set_skill("unarmed", 60);
	
	setup();

	carry_object(__DIR__"obj/cloth")->wear();  
}      


