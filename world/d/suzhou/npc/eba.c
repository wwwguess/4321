//NPC:/d/suzhou/npc/eba.c
//by dwolf
//97.11.4

#include <ansi.h>
inherit NPC;

void create()
{
	set_name(BLK"���"NOR, ({ "e ba", "e" }));
	set("gender", "����");
	set("age", 30);
	set("long",
        	RED"�����Ż�������Ŀ�׶񣬿������ڿ������ݺݵص�����һ�ۡ�\n"NOR);

	set("attitude", "peaceful");

	set("str", 26);
	set("int", 25);

	set("combat_exp", 30000);
        	
	set("chat_chance", 5);
//	set("chat_msg", ({
//		MAG"���ɫ���Եص�����������һѽ�����������õ�ͷ���ߡ������� \n"NOR,
//		MAG"��Զ��Ű��巢�����������Ц��ɫ���е�С�������Ű�����ظ���\n"NOR,
//	}) );
	
	set("force", 200);
	set("max_force", 200);
	
	set_skill("dodge", 40);
	set_skill("blade", 40);
	set_skill("parry", 40);
	set_skill("force", 40);
	set_skill("unarmed", 50);
	
	setup();

	carry_object(__DIR__"obj/cloth.c")->wear();  
}      


