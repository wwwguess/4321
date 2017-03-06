// zuoqh.c 
//by dwolf

#include <ansi.h>

inherit NPC;

string ask_me();

void create()
{
	set_name(YEL"�����"NOR, ({ "zuo qinghou", "zuo" }));
	set("gender", "����");
	set("age", 50);
	set("long",
        	"������ȥ�׷�ͯ�գ��Ͱ����ף�һ��������������ң����
��ģ����\n");

	set("attitude", "peaceful");

	set("str", 200);
	set("int", 200);

	set("combat_exp", 500000);

	set("inquiry", ([
		"�Ǵ���" : (: ask_me :),
	]) );  
	set("count", 1);
	
	set("chat_chance", 5);
	set("chat_msg", ({
		"С�ֵܣ����֪���Ϸ������Ǵ���������˫�� \n",
	}) );
	
	set("force", 1000);
	set("max_force", 1000);
	set("force_factor", 5);

	set_skill("dodge", 100);
	set_skill("sword", 100);
	set_skill("parry", 100);
	set_skill("force", 100);
	set_skill("unarmed", 100);
	
	setup();
}      

string ask_me()
{
	mapping fam; 
	object ob;
	
	if (query("count") < 1)
		return "��Ǹ���������ˣ��Ǵ����Ѿ��������ˡ�";

	ob = new(__DIR__"/npc/obj/yu");
	ob->move(this_player());

	add("count", -1);

	message_vision("\n�����Цһ�������ͷ���ܿ�����һ���Ǵ��㣬Ȼ��
			����$N��\n\n", this_player());

	return "��һ��ֻ��һ���Ǵ��㣬���Ȼ����ǡ��ʱ��������͸����ˡ�";
}


