// nanbt.c
// by dwolf  (changed by ysgl)

#include <ansi.h>
inherit NPC;

void create()
{
	set_name(YEL"�����"NOR, ({ "nan tian ba", "nan" }));
	set("gender", "����");
	set("age", 40);
	set("long",
        	RED"�����Ż�������Ŀ�׶񣬿������ڿ������ݺݵص�����һ�ۡ�\n"NOR);
	set("attitude", "heroism");
	set("str", 26);
	set("int", 25);
	set("combat_exp", 300000);
	set("chat_chance", 10);
	set("chat_msg", ({
		YEL"���������ص�����������һѽ�����������õ�ͷ���ߡ������� \n"NOR,
		YEL"����Զ���Ů���������������Ц��ɫ���е�С��������Ů���Ĵ��ȡ�\n"NOR,
	}) );
	
	set("force", 600);
	set("max_force", 600);
	set("force_factor", 30);

	set_skill("dodge", 80);
	set_skill("blade", 80);
	set_skill("parry", 80);
	set_skill("force", 80);          
	set_skill("tianmo-dafa", 80);
	set_skill("unarmed", 80);
	set_skill("mo-dao-jue", 80);
	set_skill("mo-shan-jue", 80);
	map_skill("dodge", "mo-shan-jue");
	map_skill("blade", "mo-dao-jue");
	map_skill("force", "tianmo-dafa"); 
	
	set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: exert_function , "jie ti" :),
	}));
	
	setup();
	carry_object(__DIR__"obj/blade")->wield();                                          	
	carry_object(__DIR__"obj/cloth")->wear();  
}      


