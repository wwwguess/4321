// Created by ysg
// data: 1997.10.17
               
#include <ansi.h> 
inherit NPC; 

void create()
{
	set_name("���", ({ "li bai" , "li" , "bai" }));
	set("nickname", CYN"ʫ��"NOR); 
	set("long",
	"���Ǵ�ʫ����ף����Ʈ�ݣ�׿����Ⱥ�������������\n");
	set("gender", "����");
	set("age", 35);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	set("per", 30);
	set("max_kee", 800);
	set("max_gin", 800);
	set("force", 300);
	set("max_force", 300);
	set("force_factor", 5);
	set("combat_exp", 50000);
	set("score", 100000);
	set_skill("sword",50);
	set_skill("force", 40);
	set_skill("dodge", 50);
	set_skill("unarmed", 30);
	set_skill("parry", 30);
	set_temp("apply/attack", 10);
	set_temp("apply/defense", 15);
	set_temp("apply/damage", 5);
	setup();
        set("chat_chance", 10);
        set("chat_msg", ({
        	"��״�Ц�������廨��ǧ���ã��������������ƣ����ͬ����ų\n",	
        }) );
	carry_object(__DIR__"obj/cloth")->wear();
	carry_object(__DIR__"obj/gangjian")->wield();
}
void init()
{
	object me;
    	::init();
    	if( interactive(me = this_player()) && !is_fighting() ) 
	{
        	remove_call_out("greeting");
        	call_out("greeting", 3, me);
        	return;
        }
}
void greeting(object me)
{
 	command("say ��λ"+(string)RANK_D->query_respect(me)+"�ɷ���"+
	RANK_D->query_self(this_object())+"��ıһ��\n");
}
