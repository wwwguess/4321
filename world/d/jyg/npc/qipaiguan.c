// qipaiguan.c

inherit NPC;

void create()
{
	set_name("���ƹ�", ({ "qipai guan","wu" }));
	set("gender", "����");
	set("age", 30);
	set("long",
        	"�����ǲ��������ƹٵļ����ص������ơ�\n");

	set("attitude", "peaceful");

	set("str", 27);
	set("int", 25);

	set("combat_exp", 80000);
	
	set("chat_chance", 8);
	set("chat_msg", ({
	"������˵��������û�и����������������������·�ѣ�����������\n",
	}) );
	
	set("inquiry", ([
		"������" : "����������ɣ��Ҳ��Ǻ������\n",
		"�󱸱�" : "�󱸱���..........������ʲô����������\n",
	]) );
	
	set("force", 400);
	set("max_force", 400);
	set("force_factor", 5);

	set_skill("dodge", 60);
	set_skill("blade", 60);
	set_skill("parry", 60);
	set_skill("force", 60);
	set_skill("unarmed", 65);
	
	setup();

	carry_object( __DIR__"obj/blade")->wield();
}

		
