// eba.c
//by dwolf

#include <ansi.h>
inherit NPC;

void create()
{
	set_name(YEL"�����"NOR, ({ "nan tian ba", "nan" }));
	set("gender", "����");
	set("age", 40);
	set("long",
        	RED"�����Ż�������Ŀ�׶񣬿������ڿ������ݺݵص�����һ�ۡ�\n"NOR);

	set("attitude", "peaceful");

	set("str", 26);
	set("int", 25);

	set("combat_exp", 300000);
        	
	set("count", 1);
	
	set("chat_chance", 10);
	set("chat_msg", ({
		YEL"���������ص�����������һѽ�����������õ�ͷ���ߡ������� \n"NOR,
		YEL"����Զ���Ů���������������Ц��ɫ���е�С��������Ů���Ĵ��ȡ�\n"NOR,
	}) );
	
	set("force", 200);
	set("max_force", 200);
	set("force_factor", 5);

	set_skill("dodge", 60);
	set_skill("blade", 60);
	set_skill("parry", 60);
	set_skill("force", 60);
	set_skill("unarmed", 60);
	
	setup();
        carry_object(__DIR__"obj/cloth")->wear();    
 	carry_object(__DIR__"obj/dblade");
     }
